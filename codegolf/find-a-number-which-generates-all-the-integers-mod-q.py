#!/usr/bin/env python3

"""

Consider the integers modulo q where q is prime, a generator is any integer 1 < x < q so that x^1, x^2, ..., x^(q-1) covers all q-1 of the integers between 1 and q-1. For example, consider the integers modulo 7 (which we write as Z_7). Then 3, 3^2 mod 7 = 2, 3^3 = 27 mod 7 = 6, 3^4 = 81 mod 7 = 4, 3^5 = 243 mod 7 = 5, 3^6 = 729 mod 7 = 1 covers all the values 3, 2, 6, 4, 5, 1 covers all the integers 1..6 as required.

The task is to write code that takes an input n and outputs a generator for Z_n. You cannot use any builtin or library that does this for you of course.

The only restriction on the performance of your code is that you must have tested it to completion with n =  4257452468389.

Note that 2^n means 2 to the power of n. That is ^ represents exponentiation.

"""

from sympy import *

def is_primitive_root(x, p):
    m = {}
    for i in range(1, p):
        v = x**i % p
        if v in m:
            return False
        m[v] = True
    return True

"""

https://oeis.org/A001918

@isaacg


If p is the input, we know that g^(p-1) = 1 mod p, so we just need to check that g^a != 1 mod p for any smaller a.
But a must be a factor of p-1 for that to be possible, and any multiple of an a with that property will also have that property, so we only need to check that g^((p-1)/q) != 1 mod p for all prime factors q of p-1.
So, we check all integers g in increasing order until we find one that works.

"""

def generator(p):
    f = list(factorint(p-1))
    for g in range(1, p):
        e = False
        for q in f:
            if (g**((p-1)//q))%p == 1:
                e = True
                break
        if not e:
            return g
    return -1

def test(p):
    x = generator(p)
    print(p, x)
    assert(is_primitive_root(x, p))

def main():
    p = primerange(1000)
    for x in p:
        test(x)

main()
