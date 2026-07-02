#!/usr/bin/env python3

"""

A Fermi-Dirac Prime is a prime power of the form p^(2^k), where p is prime and k≥0, or in other words, a prime to the power of an integer power of two.
They are listed as integer sequence A050376. While a normal prime factorization generally does not contain a set of distinct primes (for example 24=2×2×2×3),
a Fermi-Dirac prime factorization contains each Fermi-Dirac-prime at most once 24=2×3×4.

Your task is to write a program that takes an integer n as input and prints out the n'th Fermi-Dirac prime or chose any other options from the standard sequence IO rules

Shortest code in bytes wins, no funny business.

1-indexed

1, 2
2, 3
3, 4
4, 5
5, 7
6, 9
7, 11
8, 13
9, 16
10, 17
100, 461
1000, 7649
6605, 65536
10000, 103919
100000, 1296749
1000000, 15476291

"""

from sympy import *

# https://oeis.org/A050376
def fdp(n):
    if isprime(n):
        return True

    p = perfect_power(n)
    if not p:
        return False

    b, e = p
    if not isprime(b):
        return False

    while e%2 == 0:
        e //= 2

    return e == 1

def gen(n):
    r = []
    for i in range(1, n+1):
        if fdp(i):
            r.append(i)
    return r

def main():
    tab = [2, 3, 4, 5, 7, 9, 11, 13, 16, 17, 19, 23, 25, 29, 31, 37, 41, 43, 47, 49, 53, 59, 61, 67, 71, 73, 79, 81, 83, 89, 97, 101, 103, 107, 109, 113, 121, 127, 131, 137, 139, 149, 151, 157, 163, 167, 169, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241]

    assert(gen(tab[-1]) == tab)

main()
