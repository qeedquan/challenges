#!/usr/bin/env python3

"""

Bertrand's Postulate states that for every integer n ≥ 1 there is at least one prime p such that n < p ≤ 2n. In order to verify this theorem for n < 4000 we do not have to check 4000 cases: The Landau trick says it is sufficient to check that

2, 3, 5, 7, 13, 23, 43, 83, 163, 317, 631, 1259, 2503, 5003
are all prime. Because each of these numbers is less than twice its predecessor each interval {y : n < y ≤ 2n} contains at least one of those prime numbers.

This sequence of numbers are the Bertrand Primes (OEIS A006992) and they are defined as follows:

a(1) = 2
a(n) = largest prime below 2a(n-1)
Challenge
Implement this sequence. You may write

a function or program that given some n returns a(n) (0 or 1 indexed),
a function or program that given some n returns the first n (or n-1 or n+1) entries of this sequence,
an infinite list or stream or generator or similar equivalent in your language.

"""

from sympy import prevprime

# https://oeis.org/A006992
def bertrand_primes(n):
    if n < 1:
        return []

    r = [2]
    while len(r) < n:
        r.append(prevprime(2 * r[-1]))
    return r[:n]

def main():
    tab = [2, 3, 5, 7, 13, 23, 43, 83, 163, 317, 631, 1259, 2503, 5003, 9973, 19937, 39869, 79699, 159389, 318751, 637499, 1274989, 2549951, 5099893, 10199767, 20399531, 40799041, 81598067, 163196129, 326392249, 652784471, 1305568919, 2611137817]

    assert(bertrand_primes(len(tab)) == tab)

main()
