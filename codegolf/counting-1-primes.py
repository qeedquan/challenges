#!/usr/bin/env python3

"""

Define that the natural number p is a +1 prime of the natural number n if p is a prime number and the standard binary representation (i.e., without leading zeroes) of p can be obtained by adding (i.e., prepending, appending or inserting) a single 1 to the standard binary representation of n.

For example, the binary representation of 17 is 100012. The distinct natural numbers that can be formed by adding a 1 to 100012 are 1100012 or 49, 1010012 or 41, 1001012 or 37, and 1000112 or 35.

Among these, 41 and 37 are prime numbers, so 17 has two +1 primes.

Task
Write a program or function that accepts a strictly positive integer n as input and prints or returns the number of distinct +1 primes of n.

Input and output must either be an integer, or its decimal or unary string representation.

Standard code-golf rules apply.

Test cases
Input:  4
Output: 0

Input:  1
Output: 1

Input:  17
Output: 2

Input:  33
Output: 3

Input:  553
Output: 4

Input:  3273
Output: 5

Input:  4145
Output: 6

Input:  4109
Output: 7

Input:  196869
Output: 8

"""

from sympy import *

def oneprimes(n):
    s = bin(n)[2:]
    m = {}
    c = 0
    for i in range(len(s) + 1):
        x = int(s[:i] + "1" + s[i:], 2)
        if x not in m and isprime(x):
            m[x], c = True, c + 1
    return c

def main():
    assert(oneprimes(4) == 0)
    assert(oneprimes(1) == 1)
    assert(oneprimes(17) == 2)
    assert(oneprimes(33) == 3)
    assert(oneprimes(553) == 4)
    assert(oneprimes(3273) == 5)
    assert(oneprimes(4145) == 6)
    assert(oneprimes(4109) == 7)
    assert(oneprimes(196869) == 8)

main()

