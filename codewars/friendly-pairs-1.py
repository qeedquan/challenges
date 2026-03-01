#!/usr/bin/env python3

"""

The Abundancy (A) of a number n is defined as:

(sum of divisors of n) / n

For example:

A(8) = (1 + 2 + 4 + 8) / 8 = 15/8

A(25) = (1 + 5 + 25) / 25  = 31/25

Friendly Pairs are pairs of numbers (m, n), such that their abundancies are equal: A(n) = A(m).

Write a function that returns "Friendly!" if the two given numbers are a Friendly Pair. Otherwise return their respective abundacies as strings separated by a space, e.g. "1 15/8"

Notes:

All fractions must be written in their most reduced form (e.g. 2/3 instead of 8/12)
Every number that is being checked is under 2400
Floats should be left on without rounding when you compare the abundancies of the two numbers

Examples
n = 6, m = 28 ==> "Friendly!"

n = 3, m = 9  ==> "4/3 13/9"

"""

from sympy.functions.combinatorial.numbers import divisor_sigma
from math import gcd

def abundant(n):
    a = divisor_sigma(n)
    b = n
    c = gcd(a, b)
    return a//c, b//c

def fmt(f):
    a, b = f
    if b == 1:
        return str(a)
    return f"{a}/{b}"

# https://oeis.org/A259917
def friendly(m, n):
    am = abundant(m)
    an = abundant(n)
    if am == an:
        return "Friendly!"
    return f"{fmt(am)} {fmt(an)}"

def main():
    tab = [
        [6, 28],
        [30, 140],
        [80, 200],
        [40, 224],
        [12, 234],
        [84, 270],
        [66, 308],
        [78, 364],
        [102, 476],
        [6, 496],
        [28, 496],
        [114, 532],
        [240, 600],
        [138, 644],
        [120, 672],
        [150, 700],
        [174, 812],
        [135, 819],
        [186, 868],
        [864, 936],
        [222, 1036],
        [246, 1148],
    ]

    for m, n in tab:
        assert(friendly(m, n) == "Friendly!")
        assert(friendly(n, m) == "Friendly!")
    assert(friendly(3, 9) == "4/3 13/9")

main()
