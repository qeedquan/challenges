#!/usr/bin/env python3

"""

There are quite a large number of prime generating functions. Pretty much all of them are constructed and are based on the sieve of Eratosthenes, the Möbius function or the Wilson's theorem and are generally infeasible to compute in practice. But there are also generators, that have a very easy structure and were found by accident.

In 2003 Stephen Wolfram explored a class of nested recurrence equations in a live computer experiment at the NKS Summer School. A group of people around Matthew Frank followed up with additional experiments and discovered an interesting property of the simply recurrence

a(n) = a(n-1) + gcd(n,a(n-1))
with the start value of a(1) = 7. The difference a(n) - a(n-1) = gcd(n,a(n-1)) always seemed to be 1 or a prime. The first few differences are (OEIS A132199):

1, 1, 1, 5, 3, 1, 1, 1, 1, 11, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 23, 3, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 47, 3, 1, 5, 3, ...
If we only omit the 1s we get the following sequence (OEIS A137613):

5, 3, 11, 3, 23, 3, 47, 3, 5, 3, 101, 3, 7, 11, 3, 13, 233, 3, 467, 3, 5, 3,
941, 3, 7, 1889, 3, 3779, 3, 7559, 3, 13, 15131, 3, 53, 3, 7, 30323, 3, ...
Eric S. Rowland proved the primeness of each element in this list a few years later. As you can see, the primes are mixed and some of them appear multiple times. It also has been proven, that the sequence includes infinitely many distinct primes. Furthermore it is conjectured, that all odd primes appear.

Because this prime generator was not constructed but simply found by accident, the prime generator is called "naturally occurring". But notice that in practice this generator is also quite infeasible to compute. As it turns out, a prime p appears only after (p–3)/2 consecutive 1s. Nevertheless implementing this prime generator will be your task.

Challenge:
Write a function or a program that prints the first n elements of the sequence A137613 (the sequence without the 1s). You can read the input number n >= 0 via STDIN, command-line argument, prompt or function argument. Output the first n elements in any readable format to STDOUT, or return an array or a list with these values.

This is code-golf. Therefore the shortest code wins.

"""

from functools import lru_cache
from math import gcd

# https://oeis.org/A106108
@lru_cache(maxsize=None)
def A106108(n):
    if n < 1:
        return 0
    if n == 1:
        return 7
    x = A106108(n - 1)
    return gcd(n, x) + x

# https://oeis.org/A132199
@lru_cache(maxsize=None)
def A132199(n):
    if n < 0:
        return 0
    if n == 1:
        return 1 
    return A106108(n) - A106108(n - 1)

# https://oeis.org/A137613
def A137613(n):
    m = 0
    i = 0
    r = 0
    while m < n:
        r = A132199(i)
        if r != 1:
            m += 1
        i += 1
    return r

def main():
    A106108tab = [7, 8, 9, 10, 15, 18, 19, 20, 21, 22, 33, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 69, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 141, 144, 145, 150, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168]

    A132199tab = [1, 1, 1, 5, 3, 1, 1, 1, 1, 11, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 23, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 47, 3, 1, 5, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 101, 3, 1, 1]

    A137613tab = [5, 3, 11, 3, 23, 3, 47, 3, 5, 3, 101, 3, 7, 11, 3, 13, 233, 3, 467, 3, 5, 3, 941, 3, 7, 1889, 3, 3779, 3, 7559, 3, 13, 15131, 3, 53, 3, 7, 30323, 3, 60647, 3, 5, 3, 101, 3, 121403, 3, 242807, 3, 5, 3, 19, 7, 5, 3, 47, 3, 37, 5, 3, 17, 3, 199, 53, 3, 29, 3, 486041, 3, 7, 421, 23]

    for i in range(len(A106108tab)):
        assert(A106108(i + 1) == A106108tab[i])

    for i in range(len(A132199tab)):
        assert(A132199(i + 2) == A132199tab[i])

    for i in range(len(A137613tab)):
        assert(A137613(i + 2) == A137613tab[i])

main()
