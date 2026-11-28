#!/usr/bin/env python3

"""

The Goldbach conjecture states that every even number greater than two can be expressed as the sum of two primes. For example,

4 = 2 + 2
6 = 3 + 3
8 = 5 + 3
However, once we get to 10 something interesting happens. Not only can 10 be written as

5 + 5
but it can also be written as

7 + 3
Since 10 can be expressed as the sum of two primes two ways, we say that the "Goldbach partition" of 10 is 2. Or more generally,

The Goldbach partition of a number is the total number of distinct ways of writing n = p + q where p and q are primes and p >= q

Your challenge is to write a program or function that finds the Goldbach partition of a number. Now, technically the term "Goldbach partition" is used only to refer to even numbers. However, since the odd integer p + 2 can also be expressed as the sum of two primes if p > 2 is prime, we will extend this to all positive integers (A061358).

You may safely assume that your input will always be a positive integer, and you may take input and output in any of our default allowed methods, for example function arguments and return value, STDIN and STDOUT, reading and writing to a file, etc.

The Goldbach partitions of the positive integers up to 100 are:

0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 0, 1, 1, 2, 1, 2, 0, 2, 1, 2, 1, 3, 0, 3, 1,
3, 0, 2, 0, 3, 1, 2, 1, 4, 0, 4, 0, 2, 1, 3, 0, 4, 1, 3, 1, 4, 0, 5, 1, 4,
0, 3, 0, 5, 1, 3, 0, 4, 0, 6, 1, 3, 1, 5, 0, 6, 0, 2, 1, 5, 0, 6, 1, 5, 1,
5, 0, 7, 0, 4, 1, 5, 0, 8, 1, 5, 0, 4, 0, 9, 1, 4, 0, 5, 0, 7, 0, 3, 1, 6

As usual, standard loopholes apply, and the shortest answer in bytes wins!

"""

from sympy import primerange, isprime

# https://oeis.org/A061358
def ways(n):
    r = 0
    for p in primerange(2, n//2 + 1):
        r += isprime(n - p)
    return r

def main():
    tab = [
        0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 0, 1, 1, 2, 1, 2, 0, 2, 1, 2, 1, 3, 0, 3, 1,
        3, 0, 2, 0, 3, 1, 2, 1, 4, 0, 4, 0, 2, 1, 3, 0, 4, 1, 3, 1, 4, 0, 5, 1, 4,
        0, 3, 0, 5, 1, 3, 0, 4, 0, 6, 1, 3, 1, 5, 0, 6, 0, 2, 1, 5, 0, 6, 1, 5,
        1, 5, 0, 7, 0, 4, 1, 5, 0, 8, 1, 5, 0, 4, 0, 9, 1, 4, 0, 5, 0, 7, 0, 3,
        1, 6
    ]

    for i in range(len(tab)):
        assert(ways(i + 1) == tab[i])

main()
