#!/usr/bin/env python3

"""

Given a number n, print the nth prime Fermat number, where the Fermat numbers are of the form 22k+1. This code should theoretically work for any n (i.e. don't hardcode it), although it is not expected to terminate for n > 4. (It should not return 4294967297 for n=5, as 4294967297 is not a prime number.)

Do note that while all Fermat primes are of the form 22n+1, not all numbers of the form 22n+1 are prime. The goal of this challenge is to return the n-th prime.

Test cases
0 -> 3
1 -> 5
2 -> 17
3 -> 257
4 -> 65537
Rules
Standard loopholes are disallowed.
0-indexing and 1-indexing are both acceptable.
This is code-golf, lowest byte-count wins.

Related: Constructible n-gons
https://codegolf.stackexchange.com/questions/92272/constructible-n-gons

"""

from sympy import isprime

# https://oeis.org/A019434
def fermat_prime(n):
    if n < 0:
        return 0

    p = 0
    i = 0
    while i < n:
        if isprime(2**(2**p) + 1):
            i += 1
        p += 1
    return 2**(2**p) + 1

def main():
    assert(fermat_prime(0) == 3)
    assert(fermat_prime(1) == 5)
    assert(fermat_prime(2) == 17)
    assert(fermat_prime(3) == 257)
    assert(fermat_prime(4) == 65537)

main()

