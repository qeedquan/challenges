#!/usr/bin/env python3

"""

The Knödel numbers are a set of sequences.
Specifically, the Knödel numbers for a positive integer n are the set of composite numbers m, such that all i<m, coprime to m, satisfy i(m−n)≡1modm.
The set of Knödel numbers for a specific n is denoted Kn. (Wikipedia).

For example, K1 are the Carmichael numbers, and OEIS A002997. They go like: {561,1105,1729,2465,2821,6601,...}. K2 is OEIS A050990 and goes like, {4,6,8,10,12,14,22,24,26,...}.

Your task
Your task is to write a program/function/etc. that takes two numbers, n and p. It should return the first p numbers of the Knödel Sequence, Kn.

This is code-golf, so shortest code in bytes wins!

Examples
1, 6   ->   [561, 1105, 1729, 2465, 2821, 6601]
2, 3   ->   [4, 6, 8]
4, 9   ->   [6, 8, 12, 16, 20, 24, 28, 40, 44]
3, 1   ->   [9]
3, 0   ->   []
21, 21 ->   [45, 57, 63, 85, 105, 117, 147, 231, 273, 357, 399, 441, 483, 585, 609, 651, 741, 777, 861, 903, 987]

"""

from sympy import *

def knodel(n, p):
    r = []
    m = n + 1
    while len(r) < p:
        if isprime(m):
            m += 1
            continue

        for i in range(1, m):
            if gcd(i, m) != 1:
                continue

            if i**(m-n)%m != 1:
                break
        else:
            r.append(m)

        m += 1
    return r

def main():
    assert(knodel(1, 6) == [561, 1105, 1729, 2465, 2821, 6601])
    assert(knodel(2, 3) == [4, 6, 8])
    assert(knodel(4, 9) == [6, 8, 12, 16, 20, 24, 28, 40, 44])
    assert(knodel(3, 1) == [9])
    assert(knodel(3, 0) == [])
    assert(knodel(21, 21) == [45, 57, 63, 85, 105, 117, 147, 231, 273, 357, 399, 441, 483, 585, 609, 651, 741, 777, 861, 903, 987])

main()
