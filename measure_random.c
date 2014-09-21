#define _GNU_SOURCE

#include <error.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef int bucket_t[256];

static void fill_bucket_from_fd(int fd, bucket_t bucket, int reads) {
    FILE* fp = fdopen(fd, "r");
    if (fp == NULL) {
        perror("fdopen failed");
        exit(1);
    }
    while(reads-- > 0) {
        int c = fgetc(fp);
        if (c == EOF) {
            fprintf(stderr, "Unexpectedly got EOF\n");
            exit(1);
        }
        if (c < 0 || c > 255) {
            fprintf(stderr, "Got c %d which is out of range.\n", c);
            exit(1);
        }
        bucket[c] += 1;
        putchar('.');
    }
    putchar('\n');
}

static void fill_bucket_from_file(char const* file, bucket_t bucket, int reads) {
    memset(bucket, 0, sizeof(bucket_t));
    int fd = open(file, O_RDONLY); 
    if (fd == -1) {
        perror("Couldn't open file.");
        exit(1);
    }

    fill_bucket_from_fd(fd, bucket, reads);

    close(fd);
}

static void print_bucket(bucket_t bucket) {
    for(int i = 0; i < 16; ++i) {
        printf("%3d: ", i * 16);
        int i_multiplied = i * 16;
        for(int j = 0; j < 16; ++j) {
            printf("%5d ", bucket[i_multiplied+j]);
        }
        putchar('\n');
    }
}

unsigned int distance_from_expected(bucket_t b, int expected) {
    int result = 0;
    for(int i = 0; i < 256; ++i) {
       result += abs(expected - b[i]); 
    }
    return result;
}

void print_bucket_report(char const* bucket_name, bucket_t bucket, int expected) {
    printf("=== %s ===\n", bucket_name);
    printf("distance from expected: %u\n", distance_from_expected(bucket, expected));
    print_bucket(bucket);
}

int main(int argc, char** argv) {
    const int expected_value = 1;
    const int samples = 256 * expected_value;

    printf("Expected value %d\n", expected_value);
    printf("Samples per source %d\n", samples);

    printf("Filling from /dev/urandom...\n");
    bucket_t urandom_bucket;
    fill_bucket_from_file("/dev/urandom", urandom_bucket, samples);

    printf("Filling from /dev/random. This might block until you generate some events that contribute entropy.\n");
    bucket_t random_bucket;
    fill_bucket_from_file("/dev/random", random_bucket, samples);

    print_bucket_report("urandom", urandom_bucket, expected_value);
    print_bucket_report("random", random_bucket, expected_value);

    return 0;
}

