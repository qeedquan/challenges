#!/usr/bin/env python3

"""

Determine how many natural numbers within the range [A;B] have a prime factorization consisting of exactly 3 prime factors.

Input
A single line containing two integers A and B, separated by a space, where 1≤A≤B≤10000000.

Output
A single line with one integer: the count of numbers in the specified range that have exactly 3 prime factors.

Examples

Input #1
10 20

Answer #1
3

Input #2
8 20

Answer #2
4

"""

from sympy import factorint

def solve(a, b):
    r = 0
    for i in range(a, b + 1):
        c = 0
        f = factorint(i)
        for p in f:
            c += f[p]
        if c == 3:
            r += 1
    return r

def main():
    assert(solve(10, 20) == 3)
    assert(solve(8, 20) == 4)

main()
