#!/usr/bin/env python3

from fractions import Fraction

def solve(v1, d1, v2, d2):
    p = Fraction(d1, v1)
    q = Fraction(d2, v2)
    r = (p + q) * Fraction(1, 2)
    if p < q:
        print("You owe me a beer!")
    else:
        print("No beer for the captain.")
    print("Avg. arrival time: %s" % (r))
    print()

def main():
    solve(2, 4, 1, 3)
    solve(1, 3, 2, 4)
    solve(4, 7, 4, 9)

main()

