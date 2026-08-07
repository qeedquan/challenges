#!/usr/bin/env python3

"""

A semiprime, also known as a biprime, is a natural number that is the product of two prime numbers.
Your task is to find the N-th biprime number in sequence and output its two prime factors.

Input
A natural number N, where 1≤N≤10^5.

Output
The N-th biprime number and its two prime factors, listed in non-decreasing order.

Examples
Input #1
7

Answer #1
21 3 7

"""

from math import isqrt
from sympy import primepi, prime, factorint

# https://oeis.org/A001358
def biprime(n):
    def f(x):
        r = 0
        for k in range(1, primepi(isqrt(x)) + 1):
            r += primepi(x // prime(k)) - k + 1
        return int(n + x - r)

    m, k = n, f(n)
    while m != k:
        m, k = k, f(k)
    return m

def solve(n):
    if n < 0:
        return (0, 0, 0)

    p = biprime(n)
    f = list(factorint(p))
    return (p, f[0], f[1])

def main():
    tab = [
        4, 6, 9, 10, 14, 15, 21, 22, 25, 26, 33, 34, 35, 38, 39, 46, 49, 51,
        55, 57, 58, 62, 65, 69, 74, 77, 82, 85, 86, 87, 91, 93, 94, 95, 106,
        111, 115, 118, 119, 121, 122, 123, 129, 133, 134, 141, 142, 143, 145,
        146, 155, 158, 159, 161, 166, 169, 177, 178, 183, 185, 187
    ]

    assert(solve(7) == (21, 3, 7))

    for i in range(len(tab)):
        assert(biprime(i + 1) == tab[i])

main()
