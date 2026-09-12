#!/usr/bin/env python3

"""

Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n which are relatively prime to n.
For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.

n	Relatively Prime	φ(n)	n/φ(n)
2   1	                1       2
3   1,2                 2       1.5
4   1,3                 2       2
5   1,2,3,4             4       1.25
6   1,5                 2       3
7   1,2,3,4,5,6         6       1.1666...
8   1,3,5,7             4       2
9   1,2,4,5,7,8         6       1.5
10  1,3,7,9             4       2.5

It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.

Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.

"""

from sympy import *
from math import *

def solvebf(n):
    r, m = 0, 0
    for i in range(1, n+1):
        v = i/totient(i)
        if m < v:
            r, m = i, v
    return r

"""

https://www.mathblog.dk/project-euler-69-find-the-value-of-n-%E2%89%A4-1000000-for-which-n%CF%86n-is-a-maximum/

The ratio can be simplified to 1 / [PI[p|n] (1 - 1/p)]
So to make the value as large as possible, make the denominator as small as possible.
To make the denominator as small as possible, multiply it with as many distinct primes as possible to create the number that has the largest ratio.

"""
def solve(n):
    r = 1
    for v in primerange(2, isqrt(n)+10):
        if r*v > n:
            break
        r *= v
    return r

def main():
    print(solve(10))
    print(solve(1000000))
    for i in range(1, 1000):
        assert(solve(i) == solvebf(i))

main()
