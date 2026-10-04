#!/usr/bin/env python3

"""

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

"""

from itertools import *
from sympy import *

def solve():
    s = "123456789"
    r = 0
    for i in range(len(s)):
        for p in permutations(s[:i+1]):
            x = int(''.join(p))
            if isprime(x):
                r = max(r, x)
    return r

def main():
    print(solve())

main()
