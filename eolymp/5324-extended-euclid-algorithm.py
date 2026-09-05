#!/usr/bin/env python3

"""

Write a program that finds such x and y that a⋅x+b⋅y=1.

Input
Two positive integers a and b (1≤a,b≤10000).

Output
If x and y exist, print in the first line YES and in the second line print x and y, otherwise print in one line NO.

Examples

Input #1
2 1

Answer #1
YES
0 1

Input #2
2 2

Answer #2
NO

"""

from sympy.core.intfunc import igcdex

def solve(a, b):
    x, y, _ = igcdex(a, b)
    if a*x + b*y != 1:
        return "NO"
    return ("YES", x, y)

def main():
    print(solve(2, 1))
    print(solve(2, 2))
    print(solve(4, 9))

main()
