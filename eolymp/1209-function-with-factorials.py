#!/usr/bin/env python3

"""

Given an even positive integer n, compute the value of the following function:

f(n) = (n-2)!/((n/2 - 1)!)^2 * (1/2)^(n-2)

Input
An even positive integer n (2≤n≤100000).

Output
Print the value of f(n) with four digits after the decimal point.

Examples

Input #1
2

Answer #1
1.0000

"""

from math import factorial

def solve(n):
    a = factorial(n - 2)
    b = factorial(n//2 - 1)**2
    c = 2**(n - 2)
    return a / (b * c)

def main():
    print(solve(2))
    print(solve(100000))

main()

