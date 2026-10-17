#!/usr/bin/env python3

"""

Given an x and y find the smallest and greatest numbers above and below a given n that are divisible by both x and y.

Examples
greatest(2, 3, 20) => 18   # 18 is the greatest number under 20 that is divisible by both 2 and 3
smallest(2, 3, 20) => 24   # 24 is the smallest number above 20 that is divisible by both 2 and 3

greatest(5, 15, 100) => 90
smallest(5, 15, 100) => 105

greatest(123, 456, 789) => 0   # there are no numbers under 789 that are divisible by both 123 and 456
smallest(123, 456, 789) => 18696
Notes:

you should never return n even if it is divisible by x and y always the number above or below it
greatest should return 0 if there are no numbers under n that are divisible by both x and y
and all arguments will be valid (integers greater than 0).
Note for Haskell users
Please take a look at bkaes comment and give us your opinion

"""

from math import lcm

def greatest(x, y, n):
    m = lcm(x, y)
    return (n - 1)//m * m

def smallest(x, y, n):
    m = lcm(x, y)
    return (n//m + 1) * m

def main():
    assert(greatest(13, 17, 100) == 0)
    assert(greatest(10, 100, 100) == 0)
    assert(greatest(2, 3, 20) == 18)
    assert(greatest(5, 15, 100) == 90)
    assert(greatest(123, 456, 789) == 0)
    assert(greatest(51735, 77238, 8567205540015) == 8565894632610)
    assert(greatest(1000000007, 1000000009, 10000000000000000000) == 9000000144000000567)

    assert(smallest(2, 3, 20) == 24)
    assert(smallest(5, 15, 100) == 105)
    assert(smallest(123, 456, 789) == 18696)
    assert(smallest(13, 17, 100) == 221)
    assert(smallest(10, 100, 100) == 200)
    assert(smallest(51735, 77238, 8567205540015) == 8567226601920)
    assert(smallest(1000000007, 1000000009, 10000000000000000000) == 10000000160000000630)

main()
