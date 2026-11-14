#!/usr/bin/env python3

"""

A prime is weak if the closest other prime is smaller than it. If there is a tie the prime is not weak.

For example 73 is a weak prime because 71 is prime but 75 is composite.

Task
Write some computer code that when given a prime greater than 2 as input will determine if it is a weak prime. This is a standard decision-problem so you should output two unique values for each of the two cases (e.g. weak and not weak).

This is code-golf so standard rules for the tag apply.

OEIS
Here are the first 47 weak primes:

3, 7, 13, 19, 23, 31, 43, 47, 61, 73, 83, 89, 103, 109, 113, 131, 139, 151, 167, 181, 193, 199, 229, 233, 241, 271, 283, 293, 313, 317, 337, 349, 353, 359, 383, 389, 401, 409, 421, 433, 443, 449, 463, 467, 491, 503, 509, 523, 547, 571, 577, 601, 619, 643, 647

Here is the OEIS for weak primes (should return weak) OEIS A051635

Here is the OEIS for balanced primes (should return not weak) OEIS A006562

Here is the OEIS for strong primes (should return not weak) OEIS A051634

"""

from sympy import *

# https://oeis.org/A051635
def weakprime(n):
    if n < 3 or not isprime(n):
        return False

    p0 = prevprime(n)
    p1 = nextprime(n)
    return abs(n - p0) < abs(n - p1)

def gen(n):
    r = []
    i = 3
    while len(r) < n:
        if weakprime(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [3, 7, 13, 19, 23, 31, 43, 47, 61, 73, 83, 89, 103, 109, 113, 131, 139, 151, 167, 181, 193, 199, 229, 233, 241, 271, 283, 293, 313, 317, 337, 349, 353, 359, 383, 389, 401, 409, 421, 433, 443, 449, 463, 467, 491, 503, 509, 523, 547, 571, 577, 601, 619, 643, 647]

    assert(gen(len(tab)) == tab)

main()
