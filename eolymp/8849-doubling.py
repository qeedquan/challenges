#!/usr/bin/env python3

"""

Double each digit of the given two-digit number.

Input
A two-digit natural number.

Output
Answer to the problem.

Examples
Input #1
27

Answer #1
2277

"""

def solve(n):
    s = str(abs(n))
    a = "0"
    b = "0"
    if len(s) >= 1:
        a = s[0]
    if len(s) >= 2:
        b = s[1]

    s = s[2:] + a + a + b + b
    r = int(s)
    if n < 0:
        r = -s
    return r

def main():
    assert(solve(27) == 2277)

main()
