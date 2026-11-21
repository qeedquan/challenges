#!/usr/bin/env python3

"""

Write a program which takes an input (which may or may not be prime), and lists the immediate prime following and preceding it.

Example input:

1259
Example output:

1249 1277
Shortest program wins. Must execute within 10 seconds on a modern desktop PC. Inputs will be limited to 10,000 maximum.

"""

from sympy import *

def nearby_primes(n):
    if n < 2:
        return (2, 3)
    if n == 2:
        return (3, 5)
    a = prevprime(n)
    b = nextprime(n)
    return (a, b)

def main():
    print(nearby_primes(2))
    print(nearby_primes(3))
    print(nearby_primes(997))
    print(nearby_primes(1259))

main()
