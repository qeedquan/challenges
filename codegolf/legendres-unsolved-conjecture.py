#!/usr/bin/env python3

"""

Legendre's Conjecture is an unproven statement regarding the distribution of prime numbers; it asserts there is at least one prime number in the interval (n^2,(n+1)^2) for all natural n.

The Challenge
Make a program which only halts if Legendre's conjecture is false. Equivalently, the program will halt if there exists n which disproves the conjecture.

Rules
This is code-golf so the shortest program in bytes wins.

No input shall be taken by the program.

The program only needs to halt or not halt in theory; memory and time constraints shall be ignored.

One may use methods other than checking every n if they can prove their program will still only halt if Legendre's conjecture is false.

"""

from sympy import *

# https://oeis.org/A014085
def count(n):
    return primepi((n + 1)**2) - primepi(n**2)

def main():
    tab = [0, 2, 2, 2, 3, 2, 4, 3, 4, 3, 5, 4, 5, 5, 4, 6, 7, 5, 6, 6, 7, 7, 7, 6, 9, 8, 7, 8, 9, 8, 8, 10, 9, 10, 9, 10, 9, 9, 12, 11, 12, 11, 9, 12, 11, 13, 10, 13, 15, 10, 11, 15, 16, 12, 13, 11, 12, 17, 13, 16, 16, 13, 17, 15, 14, 16, 15, 15, 17, 13, 21, 15, 15, 17, 17, 18, 22, 14, 18, 23, 13]

    for i in range(len(tab)):
        assert(count(i) == tab[i])

main()
