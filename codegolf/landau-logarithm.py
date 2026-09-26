#!/usr/bin/env python3

"""

Related: Landau's function (OEIS A000793)

Background
Landau's function g(n) is defined as the largest order of permutation of n elements,
which is equal to  max(lcm(a1,a2,⋯,ai)) where a1,a2,⋯,ai is an integer partition of  n.

We can extend this to define "iterations" of Landau's function:
let's define g0(n)=1, and gk+1(n)=max(lcm(gk(n),a1,a2,⋯,ai)) for k≥0.
This eventually converges to  lcm(1,2,⋯,n),
so we can define "Landau logarithm" to be the smallest value of k such that gk(n)=lcm(1,2,⋯,n), or equivalently gk(n)=gk+1(n).

The resulting sequence is OEIS A225633.

Illustration
n = 5
To make it clear, let's list up all the integer partitions of 5, which are:

(5)
(4, 1)
(3, 2)
(3, 1, 1)
(2, 2, 1)
(2, 1, 1, 1)
(1, 1, 1, 1, 1)

By definition, g0(5)=1.
g1(5) is defined by whatever partition gives the largest LCM, which is lcm(2, 3)=6 (which is the same as the plain Landau function).
g2(5) is the largest LCM of any partition when combined with 6. We need to find the partition which can give the largest additional factor. Such partition is plain 5, so g2(5)=lcm(6,5)=30.
In the next step, the only partition that boosts the LCM further is (4,1), giving g3(5)=lcm(30, 4, 1)=60,
which is the same as lcm(1,2,3,4,5).
Therefore, the Landau logarithm of 5 is 3.

n = 10
g0(10)=1

g1(10)=lcm(2,3,5)=30

g2(10)=lcm(30,7,3)=210

g3(10)=lcm(210,8,2)=840

g4(10)=lcm(840,9,1)=2520=lcm(1,2,⋯,10)

Therefore the Landau logarithm of 10 is 4.

Challenge
Given a positive integer n, compute its Landau logarithm.

The shortest code in bytes wins.

Test cases
The first 20 terms (starting at n=1, up to n=20 inclusive) are:

0, 1, 2, 2, 3, 3, 3, 3, 4, 4,
5, 5, 6, 5, 5, 5, 6, 6, 7, 6

"""

from functools import lru_cache
from math import gcd

@lru_cache(maxsize=None)
def lcms(n, d):
    return max([lcms(n - k, k*d//gcd(k, d)) for k in range(1, n + 1)] + [d])

# https://oeis.org/A225633
@lru_cache(maxsize=None)
def landaulog(n, d=1):
    return d - lcms(n, d) and (landaulog(n, lcms(n, d)) + 1)

def main():
    tab = [
        0, 0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 6, 5, 5, 5, 6, 6, 7, 6,
        6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 9, 8, 9, 10, 10, 9,
        10, 9, 11, 11, 11, 11, 12, 11, 12, 12, 12, 11, 12, 12, 12, 11,
        11, 11, 12, 12, 13, 12, 12, 13, 13, 12, 13, 12, 12, 12, 13, 13,
        14, 14
    ]

    for i in range(len(tab)):
        assert(landaulog(i) == tab[i])

main()
