#!/usr/bin/env python3

"""

The question's pretty much described by the title: write a program or function that takes a positive integer n as input, and returns the smallest positive output which has all integers from 1 to n as factors. (Another way of looking at this is that you're looking for the least common multiple of the integers from 1 to n.)

This is a code-golf challenge, so the shortest entry in bytes wins.

Inspired by this challenge. (This challenge is basically the inverse of that one.)

Test cases
Input: 1; Output: 1
Input: 6; Output: 60
Input: 19; Output: 232792560
Input: 22; Output: 232792560
You don't need to worry about integer precision issues (unless your language has integers so small that this would trivialise the problem). If your language does have bignums, though, you might also want to test your program on this case, just for fun:

Input: 128; Output: 13353756090997411579403749204440236542538872688049072000

"""

from functools import reduce
from operator import mul
from sympy import sieve

def integerlog(n, b):
    kmin, kmax = 0, 1
    while b**kmax <= n:
        kmax *= 2
    while True:
        kmid = (kmax+kmin)//2
        if b**kmid > n:
            kmax = kmid
        else:
            kmin = kmid
        if kmax-kmin <= 1:
            break
    return kmin

# https://oeis.org/A003418
def f(n):
    return reduce(mul, (p**integerlog(n, p) for p in sieve.primerange(1, n+1)), 1)

def main():
    tab = [
        1, 1, 2, 6, 12, 60, 60, 420, 840, 2520, 2520, 27720, 27720, 360360,
        360360, 360360, 720720, 12252240, 12252240, 232792560, 232792560,
        232792560, 232792560, 5354228880, 5354228880, 26771144400, 26771144400,
        80313433200, 80313433200, 2329089562800, 2329089562800
    ]

    assert(f(1) == 1)
    assert(f(6) == 60)
    assert(f(19) == 232792560)
    assert(f(22) == 232792560)
    assert(f(128) == 13353756090997411579403749204440236542538872688049072000)

    for i in range(len(tab)):
        assert(f(i) == tab[i])

main()
