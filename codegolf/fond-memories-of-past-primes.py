#!/usr/bin/env python3

"""

Consider a prime number p, written in base 10. The memory of p is defined as the number of distinct primes strictly less than p that are contained as substrings of p.

Challenge
Given a non-negative integer n as input, find the smallest prime p such that p has memory n. That is, find the smallest prime with exactly n distinct strictly lesser primes as substrings.

Input
Input can be taken through any standard format. You must support input up to the largest n such that the output does not overflow. For reference, 4294967291 is the largest prime in 32 bits.

Output
Output may be written to STDOUT or returned from a function.

Examples
The number 2 has memory 0 since it contains no strictly lesser primes as substrings.

The number 113 is the smallest prime with memory 3. The numbers 3, 13, and 11 are the only prime substrings and no prime smaller than 113 contains exactly 3 primes as substrings.

The first 10 terms of the sequence, beginning with n = 0, are

2, 13, 23, 113, 137, 1237, 1733, 1373, 12373, 11317

Note
This is A079397 in OEIS.

"""

from sympy import nextprime

# https://oeis.org/A079397
def primemem(n):
    if n < 0:
        return 0

    p = 2
    while True:
        c = 0
        i = 2
        while i < p:
            if repr(i) in repr(p):
                c += 1
            i = nextprime(i)
        
        if c == n:
            return p
        p = nextprime(p)

def main():
    tab = [2, 13, 23, 113, 137, 1237, 1733, 1373, 12373, 11317, 23719]

    for i in range(len(tab)):
        assert(primemem(i) == tab[i])

main()
