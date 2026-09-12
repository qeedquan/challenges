#!/usr/bin/env python3

"""

Given a positive odd number n, return two primes p and q such that p bitwise-and q equals n.

n   p   q   p&q
1	3	5	1
3	3	3	3
9	11	13	9
Shortest code in each language wins.

Proof that a solution always exists:

Given n, by Dirichlet's theorem there exist primes p=n+k*2^n and q=n+l*2^p and p&q=n.

"""

from sympy import *

def solve(n):
    L = 1000
    while True:
        R = list(primerange(0, L))
        for p in R:
            for q in R:
                if p&q == n:
                    return (p, q)
        L *= 10

def main():
    for i in range(100):
        n = 2*i + 1
        print(n, solve(n))

main()

