#!/usr/bin/env python3

"""

Satan-Primes
who are they?
they are Primes containing 666
these are Satan-Primes:[46663,266677,666599,666683,616669]
these are NOT :[462667,665669,36363631,555]

Plot
Every number bigger than 6661 has Satan-Primes behind him

The Challenge
Given an integer n>6661 find the Satan-Prime behind (or equal) and closest to itself.

Examples
Integer n=30000 has 3 Satan-Primes(SP) behind it:[6661, 16661, 26669].
Your code must return 26669 which is the closest behind it

Test Cases
Input->Output

6662->6661
10000->6661
66697->66697 (a SP returns himself)
328765->326663
678987->676661
969696->966677

Rules
Yor code should work for any n in the range of your language.

This is code-golf, so the shortest answer in bytes wins!

"""

from sympy import *

def is_satan_prime(n):
    return "666" in str(n) and isprime(n)

def closest_satan_prime(n):
    p = max(n, 6661)
    while p > 6661:
        if is_satan_prime(p):
            break
        p = prevprime(p)
    
    q = n
    while abs(n - p) > abs(n - q):
        if is_satan_prime(q):
            p = q
            break
        q = nextprime(q)

    return p

def main():
    assert(closest_satan_prime(6662) == 6661)
    assert(closest_satan_prime(10000) == 6661)
    assert(closest_satan_prime(66697) == 66697)
    assert(closest_satan_prime(328765) == 326663)
    assert(closest_satan_prime(678987) == 676661)
    assert(closest_satan_prime(969696) == 966677)

main()
