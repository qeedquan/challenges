#!/usr/bin/env python3

"""

Task

Take an input of an integer n through the console or a file.
Find the sum of the nth prime, square, triangular number, and cube. Add to that the factorial of the first decimal place of the square root of n and the xth Fibonacci number, where x is the first digit of the square of n.
Print that sum to the console or to a file.
Rules

Entries must complete the task above for all positive integers less than 100.
Standard loopholes are of course not allowed.
Any built-in function that finds primes or tests for primes in any way is not allowed.
This is code golf.
Summary of numbers to sum

nth prime (where 2 is the first)
square of n
nth triangular number (where 1 is the first)
cube of n
factorial of the first decimal place of the square root of n
xth Fibonacci number, where x is the first digit of the square of n (2 is the third Fibonacci number)

Examples

Note: The numbers being summed are included here just for clarity.

Input: 1
Output: 2 + 1 + 1 + 1 + 1 + 1 = 7

Input: 11
Output: 31 + 121 + 66 + 1331 + 6 + 1 = 1556

Input: 99
Output: 523 + 9801 + 4950 + 970299 + 362880 + 34 = 1348487

"""

from sympy import prime, fibonacci
from math import factorial, sqrt

def triangular(n):
    return n*(n + 1) // 2

def medley(n):
    n0 = int(str(sqrt(n))[0])
    n1 = int(str(n**2)[0])
    return prime(n) + n**2 + triangular(n) + n**3 + factorial(n0) + fibonacci(n1)

def main():
    assert(medley(1) == 7)
    assert(medley(11) == 1556)
    assert(medley(99) == 1348487)

main()
