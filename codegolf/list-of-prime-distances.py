#!/usr/bin/env python3

"""

Task:
Write a code golf program that, given two positive integers n and m,
returns a list of the distances between consecutive prime numbers in the range [n, m] inclusive.

Note: My question is different from this one

Assumptions:

Consider 1 as the first prime number
n < m
Both n and m are inclusive
If there are no primes in the range or there is only one prime, return [0] or [] (empty list), whichever is easier.
Code golf scoring
Examples:

 - Input: 1, 12 → Output: [1, 1, 2, 2, 4] (Distance between consecutive primes: 1-2, 2-3, 3-5, 5-7, 7-11)
 - Input: 21, 31 → Output: [6, 2]
 - Input: 80, 100 → Output: [6, 8]
 - Input: 84, 88 → Output: [0] or [] (No primes in range)

"""

from sympy import isprime, nextprime

def prime_distances(n, m):
    n = max(n, 0)
    m = max(m, 0)
    if m < n:
        n, m = m, n

    p = 1
    if n >= 2:
        p = nextprime(n - 1)

    r = []
    while True:
        q = nextprime(p)
        if q > m:
            break
        r.append(q - p)
        p = q
    return r

def main():
    assert(prime_distances(1, 12) == [1, 1, 2, 2, 4])
    assert(prime_distances(21, 31) == [6, 2])
    assert(prime_distances(80, 100) == [6, 8])
    assert(prime_distances(84, 88) == [])

main()
