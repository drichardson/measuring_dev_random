Measuring Uniformity of /dev/random and /dev/urandom
=====================================================
This experiment measures the uniformness of a few
files: /dev/random, /dev/urandom, and /dev/zero.

The byte values (0-255) of each file is counted and stored in
an int array with 256 elements.

To measure the difference from a uniform distribution is displayed
for each source.

/dev/random blocks and, unless you have something contributing a lot of
entropy, you may need to kick it to keep it moving forward. Here are a few
commands on my system that seemed to move /dev/random forward:

    - while true; do find /; done
    - cp -R /usr $HOME/junk_usr

10 * 256 samples are taken, giving the uniform distribution an expected value of 10.
Ideally, more samples would be taken, but /dev/random on my system blocks after just a few bytes
are requested. For more accurate results (law of large numbers) you ought to increase the expected
value.

Example Run
===========

    Expected value 10
    Samples per source 2560
    === /dev/zero ===
    distance from expected: 5100
      0:  2560     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
     16:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
     32:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
     48:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
     64:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
     80:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
     96:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
    112:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
    128:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
    144:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
    160:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
    176:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
    192:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
    208:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
    224:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
    240:     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
    === /dev/urandom ===
    distance from expected: 658
      0:    12     9     9    10    13    13     7    19    16     8    11     9     8    10     8     8
     16:    15    11    14    10    10     7     8     7     6     8    11    14     6     4     8    20
     32:     8    10    11    14    10     7     8    11     9    12     7    11    10    10     9    13
     48:     7    17     4     7     7     8     7     9    12     4     7     8     9    16     5     9
     64:    13     6    10     9    13     8    12     9     4     8     6    19     6     8     9    11
     80:    13     6     9     9    10    13     8    10    18    10    10     9     5    14    12     8
     96:    13    12     9     5    10    10     7     7     8     9     9    10    13    16    10    11
    112:    11    11     7     9     7     8     7     7    15    10    13    10    12    10     6    12
    128:    10     7    11    13     8    13     5    11    16     9    13     4    10     5     9     6
    144:    13    14    12    12     6     8     8     9     6     5    13     7    11    17    10    12
    160:     9    10    14     7    13     7    11     8    12    13     7     4    12     7     6     7
    176:    10    13    15    11    12    13    12    14    15    11    10    14    11    16    11     7
    192:    10    15    10    11    10     6     7     9     8    12    10     7     5    13     8     7
    208:     8     5    16     7    13     7     7    12    11    13    13     4     6     7    12     9
    224:     9    10    14    12    11     8    10    15    10     6    12    15    14     7     9     6
    240:     9    14    13    11     7     7    11    10    14     4    16    13    12    18    14    12
    === /dev/random ===
    distance from expected: 582
      0:    11    12     9     8    16     7     7    10    11     9     6    10     5    11    13     8
     16:    13    10    10     9    12    10    13     9     9    16     3    10    15     7     7     9
     32:     9    10     7    10    10    11     9     9     6     6    15    16    16     5     6    12
     48:    11    12    12     6     8     6    11    11    11     5     9    10     8     5    12    18
     64:     8    13     8     8     6     5     9    11     8     9    14     8    11     8    13    10
     80:     7     5     9    11    10     9     9     8     9    14     7     3     9    11     6     9
     96:     6    10    13     7    18    12    11     4    10    11     9    11    14    11     7    10
    112:     7    11    14     8    12     7     7     6     7    11     9     8    10     8    11     5
    128:     7    12    14     9     8    15     9    14    10     7    10    13     8    12    10    12
    144:    12    12    10    11     7    10    13    11    10    14    13     9    14    10     3    10
    160:    16     9     8     9    14     9    11     9     9    13    13    14     9     8     7     4
    176:     6    11    13    12    13     8    15    12    11    10    13     8    13     6    14    16
    192:    15     7    12     9    10    10     8     8     9     8     7    13     9     8    12     9
    208:     7    14    15    10    12     6    11    12     9     7    15    10     6     9    15    11
    224:     8     9    11     9    13     6    11    11    10    10    10    12    10    11    14    10
    240:    10     8    11     8    22     9    13    13     7    14    13    10     8     8     9    10

