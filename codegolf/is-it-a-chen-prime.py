#!/usr/bin/env python3

"""

A number is a Chen prime if it satisfies two conditions:

It is prime itself
Itself plus two is either a prime or a semi-prime.
A prime is a number where it has exactly two divisors and those divisors consist of itself and one.

A semi-prime is a number which is the product of two primes. (Note that 12 = 2*2*3 is not semi-prime, but 25 = 5*5 is).

Your task is to determine if a number is a Chen prime. You should output any truthy value for yes and any falsy value for no.

The input will be any integer greater than or equal to one. It may also be taken as a string, character array, or an array or digits.

Examples:
101 -> truthy
223 -> falsy
233 -> truthy
1 -> falsy

This is OEIS A109611.

This is, in part, inspired by Am I a Sophie Germain prime? which, unfortunately, got closed as a duplicate, so I'm posting a somewhat related challenge which isn't a duplicate.

"""

from sympy import *

# https://oeis.org/A109611
def chenprime(n):
    return isprime(n) and (primeomega(n + 2) < 3)

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if chenprime(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 53, 59, 67, 71, 83, 89, 101, 107, 109, 113, 127, 131, 137, 139, 149, 157, 167, 179, 181, 191, 197, 199, 211, 227, 233, 239, 251, 257, 263, 269, 281, 293, 307, 311, 317, 337, 347, 353, 359, 379, 389, 401, 409]

    assert(gen(len(tab)) == tab)

main()
