#!/usr/bin/env python3

"""

Given real numbers a, b, c, and d.

Determine whether a rectangle with sides c and d can be completely placed inside a rectangle with sides a and b.

Input
The first line of the input contains the real numbers a, b, c, and d, separated by one or more spaces or newline characters.

Output
Print YES if the second rectangle can fit inside the first one, otherwise print NO.

Examples

Input #1
317 10 11 23

Answer #1
NO

"""

def solve(a, b, c, d):
    if c <= a and d <= b:
        return "YES"
    if c <= b and d <= a:
        return "YES"
    return "NO"

def main():
    assert(solve(317, 10, 11, 23) == "NO")

main()
