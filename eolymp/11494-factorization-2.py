#!/usr/bin/env python3

"""

Let n = p1^a1 * p2^a2 * ... pk^ak (p1 < p2 < ... pk) be a factorization of positive integer n.

Find the value of p1 + p2 + ... + pk.

Input
One positive integer n(1<n≤10^9).

Output
Find the factorization of n and print the value of p1+p2+...+pk.

Examples
For example, 72=2^3⋅3^2. The answer is p1+p2=2+3=5.

Input #1
72

Answer #1
5

Input #2
60

Answer #2
10

"""

from sympy import factorint

def solve(n):
    r = 0
    f = factorint(n)
    for p in f:
        r += p
    return r

def main():
    assert(solve(72) == 5)
    assert(solve(60) == 10)

main()
