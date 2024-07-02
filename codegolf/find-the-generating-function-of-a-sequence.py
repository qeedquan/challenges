#!/usr/bin/env python3

"""

Given a set of space-delimited integers, you've gotta either return a function that can generate that sequence, or return "There isn't any such function".

Sample input:

"1 11 41 79"
 - x^3+x^2-1

"12 38 78"
 - 7x^2 + 5x
The operations that the functions can contain are: +-/* and exponentiation.

If anyone has any other ideas LMK. As this is a code-golf, the shortest code will win.

"""

from sympy import interpolate
from sympy.abc import x

def test(a):
    f = interpolate(a, x)
    print(f)
    for i in range(len(a)):
        assert(f.subs(x, i + 1) == a[i])

def main():
    test([1, 11, 41, 79])
    test([12, 38, 78])
    test([1, 2, 3, 4, 5])
    test([10, 30, 53, 450])

main()
