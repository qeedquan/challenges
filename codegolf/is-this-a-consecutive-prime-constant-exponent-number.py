#!/usr/bin/env python3

"""

A while ago, I had a look at the prime factorization of 27000:

27000 = 23 × 33 × 53

There are two special things about that:

consecutive-prime: The primes are consecutive: 2 is the 1st prime, 3 is the 2nd prime, 5 is the 3rd prime.
constant-exponent: The exponent is the same for every prime (always 3)
Mathematically expressed:

An integer x is a consecutive-prime/constant-exponent number if there exist strictly positive integers n, k, m such that x = pnm × pn+1m × ... × pn+km, where pj is the j-th prime

Your task is to test if a positive integer fulfills these conditions.

Input:
A positive integer > 1, in any reasonable form.

Output:
One of two values, at least one of which has to be constant, indicating whether the input is a consecutive-prime/constant-exponent number.

Edge cases:
primes are truthy, as the factorization for prime p is p1
other numbers that can be written as pm where p is a prime are also truthy.
Rules:
Standard loopholes apply.
No worries about integer overflow, but numbers up to 255 must work.
Shortest code in bytes wins.

Test cases:

Truthy:

2
3
4
5
6
7
8
9
11
13
15
27000
456533

Falsy:

10
12
14
72
10000000
Here is a python script generating some test cases.

The fact that I accepted an answer does not mean that the challenge is over the winner can still change!

"""

from sympy import *

def cpce(n):
    if n < 2:
        return False

    f = factorint(n)
    x = -1
    for i in f:
        if x < 0:
            x = f[i]
        if x != f[i]:
            return False

    p = list(f)
    for i in range(len(p) - 1):
        if nextprime(p[i]) != p[i + 1]:
            return False

    return True

def main():
    assert(cpce(2) == True)
    assert(cpce(4) == True)
    assert(cpce(5) == True)
    assert(cpce(6) == True)
    assert(cpce(7) == True)
    assert(cpce(8) == True)
    assert(cpce(9) == True)
    assert(cpce(11) == True)
    assert(cpce(13) == True)
    assert(cpce(15) == True)
    assert(cpce(27000) == True)
    assert(cpce(456533) == True)

    assert(cpce(10) == False)
    assert(cpce(12) == False)
    assert(cpce(14) == False)
    assert(cpce(72) == False)
    assert(cpce(10000000) == False)

main()
