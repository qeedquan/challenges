#!/usr/bin/env python3

"""

Find the perimeter and area of the rectangle.

Input
Each line represents a separate test and contains the length n and the width m (1≤n,m≤1000) of the rectangle.

Output
For each test, print the perimeter and area of the rectangle in one line.

Examples

Input #1
3 1
5 3
10 7

Answer #1
8 3
16 15
34 70

"""

def solve(n, m):
    return ((n + m) * 2, n * m)

def main():
    assert(solve(3, 1) == (8, 3))
    assert(solve(5, 3) == (16, 15))
    assert(solve(10, 7) == (34, 70))

main()
