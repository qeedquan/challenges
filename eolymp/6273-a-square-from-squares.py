#!/usr/bin/env python3

"""

You are given three squares with side lengths a, b, and c.
Each square can be cut into rectangles.
Using all the pieces, you need to assemble the largest possible square.
What is the integer side length of this largest square?

Input
The input contains three positive integers a, b, and c, each not greater than 1000.

Output
Print the integer side length of the largest square you can assemble.

Examples

Input #1
2 3 4

Answer #1
5

"""

from math import sqrt

def solve(a, b, c):
    return int(sqrt(a*a + b*b + c*c))

def main():
    assert(solve(2, 3, 4) == 5)

main()
