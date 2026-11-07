#!/usr/bin/env python3

"""

Let's call a positive integer composite if it has at least one divisor other than 1 and itself. For example:

the following numbers are composite: 1024, 4, 6, 9;
the following numbers are not composite: 13, 1, 2, 3, 37.
You are given a positive integer n. Find two composite integers a,b such that a−b=n.

It can be proven that solution always exists.

Input
The input contains one integer n (1≤n≤10^7): the given integer.

Output
Print two composite integers a,b (2≤a,b≤10^9,a−b=n).

It can be proven, that solution always exists.

If there are several possible solutions, you can print any.

Examples
input
1
output
9 8

input
512
output
4608 4096

"""

from sympy import *

def composites(n):
    b = 2
    while True:
        a = n + b
        if not isprime(a) and not isprime(b):
            return (a, b)
        b += 1
    return (-1, -1)

def test(n):
    (a, b) = composites(n)
    print(a, b)
    assert(not isprime(a))
    assert(not isprime(b))
    assert(a - b == n)

def main():
    test(1)
    test(512)
    test(10**9)

main()
