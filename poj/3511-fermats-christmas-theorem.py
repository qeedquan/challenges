#!/usr/bin/env python3

"""

Description

In a letter dated December 25, 1640; the great mathematician Pierre de Fermat wrote to Marin Mersenne that he just proved that an odd prime p is expressible as p = a2 + b2 if and only if p is expressible as p = 4c + 1. As usual, Fermat didn’t include the proof, and as far as we know, never wrote it down. It wasn’t until 100 years later that no one other than Euler proved this theorem. To illustrate, each of the following primes can be expressed as the sum of two squares:

5 = 22 + 12	13 = 32 + 22	17 = 42 + 12	41 = 52 + 42
Whereas the primes 11, 19, 23, and 31 cannot be expressed as a sum of two squares. Write a program to count the number of primes that can be expressed as sum of squares within a given interval.

Input

Your program will be tested on one or more test cases. Each test case is specified on a separate input line that specifies two integers L, U where L ≤ U < 1,000,000.

The last line of the input file includes a dummy test case with both L = U = −1.

Output

For each test case, write the result using the following format:

L U x y

where L and U are as specified in the input. x is the total number of primes within the interval [L, U] (inclusive), and y is the total number of primes (also within [L, U]) that can be expressed as a sum of squares.

Sample Input

10 20
11 19
100 1000
-1 -1

Sample Output

10 20 4 2
11 19 4 2
100 1000 143 69

Source

Arab and North Africa 2007

"""

from sympy import *

"""

https://oeis.org/A002144
https://oeis.org/A000720
https://oeis.org/A066339

"""

def interval(L, U):
    p = list(primerange(L, U + 1))
    f = list(filter(lambda x: (x-1)%4 == 0, p))
    return (L, U, len(p), len(f))

def main():
    assert(interval(10, 20) == (10, 20, 4, 2))
    assert(interval(11, 19) == (11, 19, 4, 2))
    assert(interval(100, 1000) == (100, 1000, 143, 69))

main()
