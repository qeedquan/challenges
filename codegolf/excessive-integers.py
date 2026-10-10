#!/usr/bin/env python3

"""

For a positive integer n with the prime factorization n = p1^e1 * p2^e2 * ... pk^ek where p1,...,pk are primes and e1,...,ek are positive integers, we can define two functions:

Ω(n) = e1+e2+...+ek the number of prime divisors (counted with multiplicity) (A001222)
ω(n) = k the number of distinct prime divisors. (A001221)
With those two functions we define the excess e(n) = Ω(n) - ω(n) (A046660).
This can be considered as a measure of how close a number is to being squarefree.

Challenge
For a given positive integer n return e(n).

https://i.sstatic.net/gULhZ.png

Examples
For n = 12 = 2^2 * 3 we have Ω(12) = 2+1 and ω(12) = 2 and therefore e(12) = Ω(12) - ω(12) = 1.
For any squarefree number n we obivously have e(n) = 0. The first few terms are

1       0
2       0
3       0
4       1
5       0
6       0
7       0
8       2
9       1
10      0
11      0
12      1
13      0
14      0
15      0

Some more details in the OEIS wiki.
https://oeis.org/wiki/Omega(n),_number_of_prime_factors_of_n_(with_multiplicity)

"""

from sympy import factorint

# https://oeis.org/A046660
def excess(n):
    r = 0
    f = factorint(n)
    for p in f.values():
        r += p - 1
    return r

def main():
    tab = [
        0, 0, 0, 1, 0, 0, 0, 2, 1, 0, 0, 1, 0, 0, 0, 3, 0, 1, 0, 1, 0, 0, 0, 2,
        1, 0, 2, 1, 0, 0, 0, 4, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1, 1, 0, 0, 3,
        1, 1, 0, 1, 0, 2, 0, 2, 0, 0, 0, 1, 0, 0, 1, 5, 0, 0, 0, 1, 0, 0, 0, 3,
        0, 0, 1, 1, 0, 0, 0, 3, 3, 0, 0, 1, 0, 0, 0, 2, 0, 1, 0, 1, 0, 0, 0, 4,
        0, 1, 1, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0
    ]

    for i in range(len(tab)):
        assert(excess(i + 1) == tab[i])

main()
