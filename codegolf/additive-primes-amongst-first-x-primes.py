#!/usr/bin/env python3

"""

Definition of Additive Primes:
Numbers which have exactly 2 divisors are called Prime numbers.

Numbers which are prime and their sum of digits is also a prime number are called Additive Primes

Task:
Given an integer x, compute all the additive primes amongst the first x prime numbers, with 2 being considered both the first prime and additive prime number. The numbers are represented in base 10.

Rules:
The output consists of all the additive primes amongst the first x primes
0 < x < 151, for this challenge, for functionality purposes
Since the additive primes are all integers, decimals are not allowed (e.g.: you should output 2, not 2.0) and they must not be displayed as a fraction.

Examples:
10 -> 2 3 5 7 11 23 29

Explanation:

The first 10 primes are 2 3 5 7 11 13 17 19 23 29, and only 2 3 5 7 11 23 29 have their sum of digits prime numbers, those being, respectively 2,3,5,7,2,5,11, so they are additive primes

Following the explanation from example 1, other test cases may be:

2 -> 2 3

25 -> 2 3 5 7 11 23 29 41 43 47 61 67 83 89

7 -> 2 3 5 7 11

"""

from sympy import *

def digsum(n):
    r = 0
    while n > 0:
        r += n % 10
        n //= 10
    return r

# https://oeis.org/A046704
def additive_prime(n):
    return isprime(n) and isprime(digsum(n))

def upto(n):
    r = []
    p = list(primerange(2, prime(n) + 1))
    for i in p:
        if additive_prime(i):
            r.append(i)
    return r

def gen(n):
    r = []
    i = 2
    while len(r) < n:
        if additive_prime(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [
        2, 3, 5, 7, 11, 23, 29, 41, 43, 47, 61, 67, 83, 89, 101, 113, 131, 137,
        139, 151, 157, 173, 179, 191, 193, 197, 199, 223, 227, 229, 241, 263,
        269, 281, 283, 311, 313, 317, 331, 337, 353, 359, 373, 379, 397, 401,
        409, 421, 443, 449, 461, 463, 467, 487, 557, 571, 577, 593
    ]

    assert(upto(10) == [2, 3, 5, 7, 11, 23, 29])
    assert(upto(2) == [2, 3])
    assert(upto(25) == [2, 3, 5, 7, 11, 23, 29, 41, 43, 47, 61, 67, 83, 89])
    assert(upto(7) == [2, 3, 5, 7, 11])
    
    assert(gen(len(tab)) == tab)

main()
