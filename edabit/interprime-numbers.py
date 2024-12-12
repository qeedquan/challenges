#!/usr/bin/env python3

"""

An interprime number is a composite number which is equidistant from two consecutive primes. For example, the interprime 6 is 1 point after 5, a prime, and 1 point before the next prime, 7. Another interprime is 93, which lies midway between primes 89 and 97.

Create a function that takes a number n as input. If n is an interprime number, return a list containing the two consecutive primes between which it lies. If it isn't, return an empty list.

Examples
interprime(6) ➞ [5, 7]

interprime(9) ➞ [7, 11]

interprime(8) ➞ []

Notes
Interprimes cannot be prime themselves (otherwise the primes would not have been consecutive).

"""

from sympy import *

def interprime(n):
    if isprime(n):
        return []
    for i in range(1, n):
        if isprime(n - i) and nextprime(n - i + 1) == n + i:
            return [n - i, n + i]
    return []

def main():
    assert(interprime(93) == [89, 97])
    assert(interprime(6) == [5, 7])
    assert(interprime(8) == [])
    assert(interprime(9) == [7, 11])
    assert(interprime(473) == [467, 479])
    assert(interprime(373) == [])
    assert(interprime(756) == [])
    assert(interprime(413) == [])
    assert(interprime(924) == [919, 929])

main()
