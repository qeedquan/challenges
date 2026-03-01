#!/usr/bin/env python3

"""

Task
Write a method remainder which takes two integer arguments, dividend and divisor, and returns the remainder when dividend is divided by divisor. Do NOT use the modulus operator (%) to calculate the remainder!

Assumption
Dividend will always be greater than or equal to divisor.

Notes
Make sure that the implemented remainder function works exactly the same as the Modulus operator (%).

"""

def mod(x, y):
    q = x // y
    r = x - q*y
    return r

def main():
    for x in range(10000):
        for y in range(1, x + 1):
            assert(mod(x, y) == x%y)

main()
