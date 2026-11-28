#!/usr/bin/env python3

"""

Title says it all. Two input 32-bit positive integers m, n >= 2, output gcd(m,n) in prime factorization form.

Input
Command line args or 1 line of stdin okay, whatever's better for golf.

Output
Single space delimited with exponents (no additional spaces). Output nothing if the inputs are relatively prime.

Examples:

$ ./factorize 96 162
2^1 3^1

$ ./factorize 14 15


$ ./factorize 196 294
2^1 7^2

Rules
You may not use external resources, math libraries or built-in functions for factorization or GCD. Examples: Java, no java.lang.Math. ruby, no prime_division, perl, no factor, etc.

"""

from sympy import *
from math import *

def factorize(a, b):
    f = factorint(gcd(a, b))
    s = ""
    for x in f:
        s += "%d^%d " % (x, f[x])
    if len(s) > 0:
        s = s[:len(s)-1]
    return s

def main():
    assert(factorize(96, 162) == "2^1 3^1")
    assert(factorize(14, 15) == "")
    assert(factorize(196, 294) == "2^1 7^2")

main()
