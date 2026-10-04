#!/usr/bin/env python3

"""

For the celebration, the Professor bought balloons of three colors: blue, red, and yellow. In total, he bought n balloons.
The number of yellow and blue balloons is a, and the number of red and blue balloons is b.

Determine how many blue, red, and yellow balloons the Professor bought.

Input
Three positive integers n, a, b.

Output
Print in one line the number of blue, red, and yellow balloons bought by the Professor.

Examples
Input #1
10 6 8

Answer #1
4 4 2

"""

def solve(n, a, b):
    z = n - b
    x = a - z
    y = b - x
    return (x, y, z)

def main():
    assert(solve(10, 6, 8) == (4, 4, 2))

main()
