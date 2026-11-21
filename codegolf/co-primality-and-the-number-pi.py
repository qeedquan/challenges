#!/usr/bin/env python3

"""

Introduction
Number theory is full of wonders, in the form of unexpected connections. Here's one of them.

Two integers are co-prime if they have no factors in common other than 1. Given a number N, consider all integers from 1 to N.
Draw two such integers at random (all integers have the same probability of being selected at each draw; draws are independent and with replacement).
Let p denote the probability that the two selected integers are co-prime. Then p tends to 6/π^2≈0.6079... as N tends to infinity.

The challenge
The purpose of this challenge is to compute p as a function of N.

As an example, consider N=4. There are 16 possible pairs obtained from the integers 1,2,3,4. 11 of those pairs are co-prime, namely
(1,1), (1,2), (1,3), (1,4), (2,1), (3,1), (4,1), (2,3), (3,2), (3,4), (4,3). Thus p=11/16=0.6875 for N=4.

The exact value of p needs to be computed with at least 4 decimals. This implies that the computation has to be deterministic (as opposed to Monte Carlo). But it need not be a direct enumeration of all pairs as above; any method can be used.

Function arguments or stdin/stdout may be used. If displaying the output, trailing zeros may be omitted. So for example 0.6300
 can be displayed as 0.63. It should be displayed as a decimal number, not as a fraction (displaying the string 63/100 is not allowed).

Winning criterion is fewest bytes. There are no restrictions on the use of built-in functions.

Test cases
Input / output (only four decimals are mandatory, as indicated above):

1    / 1.000000000000000
2    / 0.750000000000000
4    / 0.687500000000000
10   / 0.630000000000000
100  / 0.608700000000000
1000 / 0.608383000000000

"""

from math import *

def ratio(n):
    c = 0
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if gcd(i, j) == 1:
                c += 1
    return c / n**2

def test(n, r):
    p = ratio(n)
    print(p)
    assert(abs(p - r) < 1e-12)

def main():
    test(1, 1.000000000000000)
    test(2, 0.750000000000000)
    test(4, 0.687500000000000)
    test(10, 0.630000000000000)
    test(100, 0.608700000000000)
    test(1000, 0.608383000000000)

main()
