#!/usr/bin/env python3

"""

The Recursively Prime Primes is are sequence of primes such that

p(1) = 2
p(n) = the p(n-1)th prime
Here is an example of how one might calculate the 4th Recursively Prime Prime.

p(4) = the p(3)th prime
p(3) = the p(2)th prime
p(2) = the p(1)th prime
p(1) = 2
p(2) = the 2nd prime
p(2) = 3
p(3) = the 3rd prime
p(3) = 5
p(4) = the 5th prime
p(4) = 11
You should write a program or function that when given n, outputs the nth Recursively Prime Prime.

You may choose to use 0 based indexing if you wish in which case you must indicate so in your answer.

This is code-golf so the goal is to minimize your byte count.

Test Cases
1 -> 2
2 -> 3
3 -> 5
4 -> 11
5 -> 31
6 -> 127
7 -> 709
8 -> 5381
9 -> 52711

Relevant OEIS entry: OEIS A007097

"""

from sympy import *

# https://oeis.org/A007097
def primeth(n):
    if n < 0:
        return 0
    if n == 0:
        return 1

    p = 2
    for i in range(1, n):
        p = prime(p)
    return p

def main():
    tab = [1, 2, 3, 5, 11, 31, 127, 709, 5381, 52711, 648391, 9737333]

    for i in range(len(tab)):
        assert(primeth(i) == tab[i])

main()
