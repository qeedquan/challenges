#!/usr/bin/env python3

"""

Description

A pretty straight forward task, calculate the number of primes between 2 integers.

Given 2 integers A ≤ B < 10^5 what’s the number of primes in range from A to B inclusive.

Note: A prime number is a positive integer greater than 1 and is divisible by 1 and itself only. For N to be prime it is enough to test the divisibility of numbers less than or equal to square root of N.

Input

As many as 1000 lines, each line contains 2 integers A and B separated by a space. Input is terminated when A = B = -1 (Do not process this line).

Output

For every line in input – except for the last line where A = B = -1 - print the number of prime numbers between A and B inclusive.

Sample Input

0 9999
1 5
-1 -1

Sample Output

1229
3

Source

Seventh ACM Egyptian National Programming Contest

"""

from sympy import *

def primes(a, b):
    return primepi(b) - primepi(a - 1)

def main():
    assert(primes(0, 9999) == 1229)
    assert(primes(1, 5) == 3)
    assert(primes(2, 5) == 3)
    assert(primes(3, 9) == 3)

main()
