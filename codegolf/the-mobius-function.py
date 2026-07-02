#!/usr/bin/env python3

"""

The Möbius function is an important number theoretic function.

Your submission should accept a positive integer n and return the value of the Möbius function evaluated at n.

Definition
The Möbius function μ(n) is defined as follows:

μ(n)= 1, n is squarefree and has an even number of distinct prime factors
     -1, n is squarefree and has an odd number of distinct prime factors
     0, otherwise

n is called squarefree if the exponents of the prime factorization of n are all strictly less that two. (Alternatively: No prime to the power of two divides n).

Test cases
Here you can see the first 50 values of μ:

Public Domain Image from Wikipedia

The Möbius function is sequence number A008683 in the OEIS.

These are the first 77 values:

1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1, 1, 0, -1, 0, -1, 0, 1, 1, -1, 0, 0, 1, 0, 0, -1, -1, -1, 0, 1, 1, 1, 0, -1, 1, 1, 0, -1, -1, -1, 0, 0, 1, -1, 0, 0, 0, 1, 0, -1, 0, 1, 0, 1, 1, -1, 0, -1, 1, 0, 0, 1, -1, -1, 0, 1, -1, -1, 0, -1, 1, 0, 0, 1
Larger values can also easily be checked in Wolframalpha.com or in the b-file of OEIS, as suggested by @MartinBüttner.

"""

from sympy import mobius

# https://oeis.org/A008683
def main():
    tab = [1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1, 1, 0, -1, 0, -1, 0, 1, 1, -1, 0, 0, 1, 0, 0, -1, -1, -1, 0, 1, 1, 1, 0, -1, 1, 1, 0, -1, -1, -1, 0, 0, 1, -1, 0, 0, 0, 1, 0, -1, 0, 1, 0, 1, 1, -1, 0, -1, 1, 0, 0, 1, -1, -1, 0, 1, -1, -1, 0, -1, 1, 0, 0, 1]

    for i in range(len(tab)):
        assert(mobius(i + 1) == tab[i])

main()
