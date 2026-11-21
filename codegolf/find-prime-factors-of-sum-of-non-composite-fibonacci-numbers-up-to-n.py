#!/usr/bin/env python3

"""

The Challenge

Given a number, find the sum of the non-composite numbers in the Fibonacci sequence up to that number, and find the prime factors of the sum.

For example, if you were given 8, the non-composite numbers would be 1, 1, 2, 3, and 5. Adding these up would get 12. The prime factors of 12 are 2, 2 and 3, so your program should return something along the lines of 2, 2, 3 when given 12.

The Objective

This is Code Golf, so the answer with the least amount of bytes wins.

"""

from sympy import factorint, isprime

def solve(n):
    a, b, x = 1, 1, 0
    while a < n:
        if a <= 1 or isprime(a):
            x += a
        a, b = b, a + b

    r = []
    f = factorint(x)
    for p in f:
        for _ in range(f[p]):
            r.append(p)
    return r

def main():
    assert(solve(12) == [2, 2, 3])

main()
