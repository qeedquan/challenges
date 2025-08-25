#!/usr/bin/env python3

"""

Consider a sequence made up of the consecutive prime numbers. This infinite sequence would start with:

"2357111317192329313741434753596167717379..."
You will be given two numbers: a and b, and your task will be to return b elements starting from index a in this sequence.

For example:
solve(10,5) == `19232` Because these are 5 elements from index 10 in the sequence.
Tests go up to about index 20000.

"""

from sympy import nextprime

def solve(a, b):
    r = ""
    p = 2
    while len(r) <= a + b:
        r += str(p)
        p = nextprime(p)
    return r[a:a+b]

def main():
    assert(solve(10, 5) == "19232")
    assert(solve(2, 2) == "57")
    assert(solve(10, 3) == "192")
    assert(solve(20, 9) == "414347535")
    assert(solve(30, 12) == "616771737983")
    assert(solve(40, 8) == "83899710")
    assert(solve(50, 6) == "031071")
    assert(solve(10000, 5) == "02192")
    assert(solve(20000, 5) == "09334")

main()
