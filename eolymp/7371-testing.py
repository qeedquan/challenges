#!/usr/bin/env python3

"""

This year Andrew must pass testing at school including math course. He aggressively prepares himself - he already solves complex trigonometric equations, easily does stereometry, but with rational numbers (fractions) things are not looking good, especially with their addition. He is even afraid to make a mistake in writing the testing program. Do it for him. Recall that a rational number is defined as an irreducible fraction, where the numerator is an integer, and the denominator is a natural number.

Input
Four integers - the numerator and denominator of the first fraction and the numerator and denominator of the second fraction. All numbers are not greater than 10^5 by absolute value.

Output
Print the numerator and denominator of the sum of fractions.

Examples

Input #1
4 9 5 7

Answer #1
73 63

Input #2
2 3 -1 6

Answer #2
1 2

Note
https://static.e-olymp.com/content/dd/ddad079ddfc19f685b69b0bf1b8a544237972c9c.png

"""

from math import gcd

def solve(a, b, c, d):
    e = a*d + b*c
    f = b*d
    g = gcd(e, f)
    x = e // g
    y = f // g
    if y < 0:
        x, y = -x, -y
    return (x, y)

def main():
    assert(solve(4, 9, 5, 7) == (73, 63))
    assert(solve(2, 3, -1, 6) == (1, 2))

main()
