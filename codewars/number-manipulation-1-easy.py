#!/usr/bin/env python3

"""

For a given large number (num), write a function which returns the number with the second half of digits changed to 0.

In cases where the number has an odd number of digits, the middle digit onwards should be changed to 0.

Example:

192827764920 --> 192827000000

938473 --> 938000

2837743 --> 2830000

"""

def manipulate(x):
    n = len(str(x))
    p = 10**(n//2 + n%2)
    return x//p * p

def main():
    assert(manipulate(192827764920) == 192827000000)
    assert(manipulate(938473) == 938000)
    assert(manipulate(2837743) == 2830000)
    assert(manipulate(838473) == 838000)
    assert(manipulate(8173648710293847) == 8173648700000000)

main()
