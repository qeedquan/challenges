#!/usr/bin/env python3

"""

A polynomial with coefficients in some field F is called irreducible over F if it cannot be decomposed into the product of lower degree polynomials with coefficients in F.

Consider polynomials over the Galois field GF(5). This field contains 5 elements, namely the numbers 0, 1, 2, 3, and 4.

Task
Given a positive integer n, compute the number of irreducible polynomials of degree n over GF(5). These are simply the polynomials with coefficients in 0-4 which cannot be factored into other polynomials with coefficients in 0-4.

Input
Input will be a single integer and can come from any standard source (e.g. STDIN or function arguments). You must support input up to the largest integer such that the output does not overflow.

Output
Print or return the number of polynomials that are irreducible over GF(5). Note that these numbers get large rather quickly.

Examples
In : Out
 1 : 5
 2 : 10
 3 : 40
 4 : 150
 5 : 624
 6 : 2580
 7 : 11160
 8 : 48750
 9 : 217000
10 : 976248
11 : 4438920

Note that these numbers form the sequence A001692 in OEIS.

"""

from sympy import sieve

# https://oeis.org/A001692
def gf5ip(n):
    if n < 0:
        return 0
    if n == 0:
        return 1

    mu = list(sieve.mobiusrange(0, n+1))
    r = 0
    for d in range(1, n+1):
        if n%d == 0:
            r += mu[d-1] * 5**(n/d) / n
    return int(r)

def main():
    tab = [1, 5, 10, 40, 150, 624, 2580, 11160, 48750, 217000, 976248, 4438920, 20343700, 93900240, 435959820, 2034504992, 9536718750]

    for i in range(len(tab)):
        assert(gf5ip(i) == tab[i])

main()
