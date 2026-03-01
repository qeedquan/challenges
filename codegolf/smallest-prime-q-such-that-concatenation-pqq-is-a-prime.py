#!/usr/bin/env python3

"""

Let p, q, and c := (p + q)"q (where " denotes concatenation) be positive integers such that p and c are primes and q is the smallest prime such that c is prime.

Such a prime triple (p, q, (p + q)"q) is for example (9721, 101, 9822101).

In natural order, the results start 3, 7, 3, 3, 19, 3, 31, ...

Challenge

Write a function that, given p, returns q that satisfies the above conditions.

Make sure that the program can calculate the given example in a reasonable time (say in 99 seconds).

Rules

Standard I/O rules apply and no standard loopholes.

This is code-golf, so shortest code in bytes wins.

"""

from sympy import *

# https://oeis.org/A375553
def solve(p):
    q = 2
    while True:
        x = int(str(p + q) + str(q))
        if isprime(x):
            break
        q = nextprime(q)
    return q

def main():
    assert(solve(9721) == 101)

main()

