measure_random: measure_random.c
	$(CC) -o $@ $< -Wall -O0 -g -std=c11

clean:
	$(RM) measure_random

