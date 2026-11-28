#!/usr/bin/env python3

"""

OEIS: A167171

A dense number is a number that has exactly as many prime divisors as non-prime divisors (including 1 and itself as divisors). Equivalently, it is either a prime or a product of two distinct primes. The first 100 dense numbers are:

2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 31, 33, 34, 35, 37, 38, 39, 41, 43, 46, 47, 51, 53, 55, 57, 58, 59, 61, 62, 65, 67, 69, 71, 73, 74, 77, 79, 82, 83, 85, 86, 87, 89, 91, 93, 94, 95, 97, 101, 103, 106, 107, 109, 111, 113, 115, 118, 119, 122, 123, 127, 129, 131, 133, 134, 137, 139, 141, 142, 143, 145, 146, 149, 151, 155, 157, 158, 159, 161, 163, 166, 167, 173, 177, 178, 179, 181, 183, 185, 187, 191, 193, 194
Given a nonnegative integer n, output dense(n). n may be 0-indexed or 1-indexed.

Reference implementation (Sage)
import itertools

def dense_numbers():
    n = 1
    while True:
        prime_divisors = [x for x in divisors(n) if x.is_prime()]
        non_prime_divisors = [x for x in divisors(n) if not x.is_prime()]
        if len(prime_divisors) == len(non_prime_divisors):
            yield n
        n += 1

N = 20

print itertools.islice(dense_numbers(), N, N+1).next()

"""

from sympy import *

# https://oeis.org/A167171
def dense(n):
    d = divisors(n)
    a = 0
    b = 0
    for v in d:
        if isprime(v):
            a += 1
        else:
            b += 1
    return a == b

def gen(n):
    r = []
    i = 2
    while len(r) < n:
        if dense(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 31, 33, 34, 35, 37, 38, 39, 41, 43, 46, 47, 51, 53, 55, 57, 58, 59, 61, 62, 65, 67, 69, 71, 73, 74, 77, 79, 82, 83, 85, 86, 87, 89, 91, 93, 94, 95, 97, 101, 103, 106, 107, 109, 111, 113, 115, 118, 119, 122, 123, 127, 129, 131, 133, 134, 137, 139, 141, 142, 143, 145, 146, 149, 151, 155, 157, 158, 159, 161, 163, 166, 167, 173, 177, 178, 179, 181, 183, 185, 187, 191, 193, 194]
    
    assert(gen(len(tab)) == tab)

main()
