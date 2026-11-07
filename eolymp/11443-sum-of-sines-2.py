#!/usr/bin/env python3

"""

For the given positive integer n and real number x find the sum

sin x + sin x^2 + ⋯ + sin x^n

Input
Two numbers: one natural number n(n≤1000) and one real number x(∣x∣≤1000).

Output
Print the value of the sum with 6 decimal digits.

Examples

Input #1
3 1

Answer #1
2.524413

"""

from math import *

def solve(n, x):
    r = 0
    for i in range(1, n + 1):
        r += sin(x**i)
    return r

def main():
    print(solve(3, 1))

main()
