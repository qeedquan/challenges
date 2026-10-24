#!/usr/bin/env python3

"""

Catalan numbers cn are defined by the recurrence relation:

c0 = 1
cn = Sum[k=0, n-1] c[k]*c[n-k-1] n > 0

Compute the n-th Catalan number modulo m.

Input
Two integers n (0≤n≤10^4) and m (0<m≤10^9).

Output
Print the value of cn mod m.

Examples

Input #1
5 100

Answer #1
42

"""

from math import comb

def catalan(n):
    return comb(2*n, n) // (n+1)

def solve(n, m):
    return catalan(n) % m

def main():
    assert(solve(5, 100) == 42)

main()
