#!/usr/bin/env python3

"""

You will take two positive integers n and x as input, and output Euler's totient function (number of positive integers less than x co-prime to x) applied n times.

Testcases
n x   result
1 10  4
2 10  2
3 10  1
1 100 40
2 100 16
3 100 8
4 100 4
5 100 2
6 100 1

"""

from sympy import *

def repeated_totient(n, x):
    for i in range(n):
        x = totient(x)
    return x

def main():
    assert(repeated_totient(1, 10) == 4)
    assert(repeated_totient(2, 10) == 2)
    assert(repeated_totient(3, 10) == 1)
    assert(repeated_totient(1, 100) == 40)
    assert(repeated_totient(2, 100) == 16)
    assert(repeated_totient(3, 100) == 8)
    assert(repeated_totient(4, 100) == 4)
    assert(repeated_totient(5, 100) == 2)
    assert(repeated_totient(6, 100) == 1)

main()
