#!/usr/bin/env python3

"""

The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?

"""

from sympy import *

def distinct(p, n):
    for v in p:
        if len(v) != n:
            return False
    return True

def solve(n):
    x = []
    p = []
    for i in range(n):
        x.append(2 + i)
        p.append(primefactors(2 + i))
    
    i = x[-1] + 1
    while True:
        if distinct(p, n):
            return x

        i += 1
        x = x[1:]
        p = p[1:]
        x.append(i)
        p.append(primefactors(i))

def main():
    print(solve(2))
    print(solve(3))
    print(solve(4))

main()
