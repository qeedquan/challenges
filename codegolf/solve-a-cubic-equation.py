#!/usr/bin/env python3

"""

Input
Your program will take in the integer coefficients of the equation a*x^3 + b*x^2 + c*x + d = 0 as inputs (a, b, c, and d).
Output
All real solutions of the input equation, with an accuracy of at least the thousandths place, sorted from smallest to largest.
Rules
Built-in equation solver are not allowed
Native math libraries that do not solve equations may be used
If you have any questions, please ask in comment

Examples.

Input:

1 2 3 4
Output:

-1.651.

Input:

1 3 0 -1
Output:

-2.879 -0.653 0.532

"""

def maxabs(a, b, c):
    return max(abs(a), abs(b), abs(c))

"""

https://en.wikipedia.org/wiki/Durand%E2%80%93Kerner_method
https://www.johndcook.com/blog/2022/11/14/simultaneous-root-finding/

"""
def findroots(f, g, tol=1e-10):
    p, q, r = 1, g, g**2
    dp = dq = dr = 1

    while maxabs(dp, dq, dr) > tol:
        dp = f(p) / ((p - q) * (p - r))
        p -= dp
        dq = f(q) / ((q - p) * (q - r))
        q -= dq
        dr = f(r) / ((r - p) * (r - q))
        r -= dr
    return p, q, r

def main():
    f1 = lambda x: x**3 + 2*x**2 + 3*x + 4
    f2 = lambda x: x**3 + 3*x**2 - 1
    print(findroots(f1, -1.6+1j))
    print(findroots(f2, 2+0j))

main()

