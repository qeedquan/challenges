#!/usr/bin/env python3

"""

Introduction
Prime numbers are simple, right? Well, now you get your chance to find out!

Challenge
You must write a program or function that takes an input n and outputs the first n prime numbers.

Example Input and Output
Input: 10
Output: 2,3,5,7,11,13,17,19,23,29

Rules
You must not include any of the following builtin functions:

A list of prime numbers

Primality testing

Next prime

Prime factorization

List of divisors

Your output must be in a convenient, unambiguous list format.

This is code-golf, so the shortest answer in bytes wins.

"""

from sympy import nextprime

def primes(n):
    r = []
    p = 2
    while len(r) < n:
        r.append(p)
        p = nextprime(p)
    return r

def main():
    assert(primes(10) == [2, 3, 5, 7, 11, 13, 17, 19, 23, 29])

main()
