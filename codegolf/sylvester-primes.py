#!/usr/bin/env python3

"""

Sylvester's sequence can be defined recursively S(n) = S(n-1)*(S(n-1) + 1) for n >= 1 starting S(0) = 1.

Since S(n) and S(n) + 1 have no common divisors, it follows that S(n) has at least one more prime factor than S(n-1), and thus by induction, S(n) has at least n distinct prime factors.

This simple and constructive form of Euclid's proof of the infinity of primes was formulated by Filip Saidak.

To generate the sequence, select the smallest among the prime factors of S(n) that has not yet been selected. We call the infinite sequence constructed this way the Sylvester primes.

The first few steps generating the sequence are sketched by:

  n,  selected,       factors of S(n)            a(n)
  [1] {},             {2}                     ->   2,
  [2] {2},            {2, 3}                  ->   3,
  [3] {2, 3},         {2, 3, 7}               ->   7,
  [4] {2, 3, 7},      {2, 3, 7, 43}           ->  43,
  [5] {2, 3, 7, 43},  {2, 3, 7, 13, 43, 139}  ->  13.
Summary:

Input: A positive integer n.

Output: The sequence a(1), ..., a(n) of the first n Sylvester primes.

Optional: Comment if the program can generate the sequence for n = 10 in less than a quarter of an hour.

This is code-golf, so each language's shortest code in bytes wins.

"""

from sympy import sieve
from itertools import count, islice

def smallest_new_primefactor(n, pf):
    return next(pi for i in count(1) if (pi:=sieve[i]) not in pf and n%pi==0)

def agen(): 
    p, d, w, pf = 1, set(), set(), set()
    while True:
        p = p*(p + 1)
        m = smallest_new_primefactor(p, w)
        w |= {m}
        yield m

# https://oeis.org/A375543
def gen(n):
    return list(islice(agen(), n))

def main():
    tab = [2, 3, 7, 43, 13, 139, 547, 607, 1033, 181, 1987, 73, 2287, 29881, 13999, 17881, 31051, 52387, 67003, 74203]

    assert(gen(len(tab)) == tab)

main()
