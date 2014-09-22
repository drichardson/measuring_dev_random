Measuring Uniformity of /dev/random and /dev/urandom
=====================================================
This experiment measures the uniform-ness of a few
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

Out of the box, only 256 samples are taken, giving the uniform distribution an expected value of 1.
Ideally, a lot more samples would be taken, but /dev/random on my system blocks after just a few bytes
are requested. For more accurate results (law of large numbers) you ought to up expected value
significantly higher.

Example Run
===========

    Expected value 1
    Samples per source 256
    === /dev/zero ===
    distance from expected: 510
      0:   256     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
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
    distance from expected: 182
      0:     0     2     0     0     1     0     0     0     0     0     1     1     0     2     0     1
     16:     0     0     0     1     2     1     0     0     0     3     1     0     0     0     4     0
     32:     2     0     1     1     1     1     2     0     2     0     1     0     0     0     0     1
     48:     1     0     1     2     1     1     3     1     1     1     1     0     1     0     3     2
     64:     2     0     1     1     1     3     1     0     0     0     1     0     1     2     1     0
     80:     0     2     1     3     0     2     1     0     0     2     1     1     1     0     1     2
     96:     0     0     1     1     2     1     1     0     1     0     1     2     2     2     1     0
    112:     1     1     3     2     0     1     0     0     1     2     3     1     0     3     0     6
    128:     3     1     2     1     2     2     0     1     1     0     2     1     0     0     0     1
    144:     2     0     1     3     2     1     2     1     0     0     1     1     4     1     4     2
    160:     0     1     0     0     2     1     0     4     0     0     0     2     2     0     1     1
    176:     1     1     1     0     0     2     1     1     1     0     0     3     1     1     1     1
    192:     1     2     1     2     1     1     1     1     0     1     0     1     1     1     0     0
    208:     0     3     0     1     1     4     2     1     0     0     1     1     1     1     0     1
    224:     3     0     0     1     1     2     1     0     0     2     0     1     1     0     1     2
    240:     0     2     1     1     1     2     0     1     3     1     1     2     0     3     0     0
    === /dev/random ===
    distance from expected: 204
      0:     1     1     1     0     0     0     1     3     2     1     1     1     2     0     3     2
     16:     0     1     1     4     0     0     2     0     0     3     0     1     0     1     0     1
     32:     0     3     0     0     2     1     0     0     1     0     3     0     0     1     0     1
     48:     0     0     0     1     1     0     0     1     5     3     0     0     1     1     0     0
     64:     0     1     1     1     2     0     1     0     2     1     2     1     0     1     3     1
     80:     1     1     2     1     0     0     1     0     0     0     1     0     0     1     0     0
     96:     2     0     1     0     2     1     4     1     1     2     2     0     2     2     1     0
    112:     1     1     0     2     0     1     0     2     1     2     1     1     0     2     0     4
    128:     2     0     3     0     2     0     1     0     0     2     1     2     0     0     1     3
    144:     1     0     1     0     3     0     4     2     0     0     1     0     1     0     0     0
    160:     0     0     2     0     2     0     1     1     3     3     0     0     2     1     0     0
    176:     1     1     0     2     0     1     0     4     3     2     0     0     2     1     4     0
    192:     0     3     0     3     0     1     0     3     0     1     1     3     1     2     1     1
    208:     1     1     0     1     1     1     1     1     2     2     0     2     1     3     2     1
    224:     0     1     1     1     0     0     3     0     1     0     2     2     0     2     0     2
    240:     1     1     0     0     0     2     1     1     1     1     1     0     3     1     0     0
