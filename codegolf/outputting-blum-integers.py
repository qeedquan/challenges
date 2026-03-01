#!/usr/bin/env python3

"""

According to Wikipedia,

In mathematics, a natural number n is a Blum integer if n=p×q is a semiprime for which p and q are distinct prime numbers congruent to 3 mod 4.
That is, p and q must be of the form 4t+3, for some integer t.
Integers of this form are referred to as Blum primes.
This means that the factors of a Blum integer are Gaussian primes with no imaginary part.

The first few Blum integers are:

21, 33, 57, 69, 77, 93, 129, 133, 141, 161, 177, 201, 209, 213, 217, 237, 249, 253, 301, 309, 321, 329, 341, 381, 393, 413, 417, 437, 453, 469, 473, 489, 497, 501, 517, 537, 553, 573, 581, 589, 597, 633, 649, 669, 681, 713, 717, 721, 737, 749, 753, 781, 789

This is OEIS A016105

Your task is to make a program that does one of the following:

Take an index n and output the nth Blum integer, either 0 or 1 indexing.
Take a positive integer n and output the first n Blum integers.
Output all Blum integers infinitely.
This is code-golf so shortest answer wins.

"""

from sympy import *

# https://oeis.org/A016105
def blum(n):
    f = factorint(n)
    s = sum(f.values())
    if len(f) != s or s != 2:
        return False
    
    for v in f:
        if v%4 != 3:
            return False
    return True

def gen(n):
    r = []
    i = 1
    while len(r) < n:
        if blum(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [21, 33, 57, 69, 77, 93, 129, 133, 141, 161, 177, 201, 209, 213, 217, 237, 249, 253, 301, 309, 321, 329, 341, 381, 393, 413, 417, 437, 453, 469, 473, 489, 497, 501, 517, 537, 553, 573, 581, 589, 597, 633, 649, 669, 681, 713, 717, 721, 737, 749, 753, 781, 789]

    assert(gen(len(tab)) == tab)

main()
