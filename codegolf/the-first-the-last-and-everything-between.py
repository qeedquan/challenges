#!/usr/bin/env python3

"""

Given two integers, output the two integers, and then the range between them (excluding both).

The order of the range must be the same as the input.

Examples:
 Input        Output
 0,  5   ->   [0, 5, 1, 2, 3, 4]
-3,  8   ->   [-3, 8, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7]
 4,  4   ->   [4, 4]
 4,  5   ->   [4, 5]
 8,  2   ->   [8, 2, 7, 6, 5, 4, 3]
-2, -7   ->   [-2, -7, -3, -4, -5, -6]

"""

def gen(a, b):
    x, y, z = a+1, b, 1
    if a > b:
        x, z = a-1, -1
    return [a, b] + list(range(x, y, z))

def main():
    assert(gen(0, 5) == [0, 5, 1, 2, 3, 4])
    assert(gen(-3, 8) == [-3, 8, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7])
    assert(gen(4, 4) == [4, 4])
    assert(gen(4, 5) == [4, 5])
    assert(gen(8, 2) == [8, 2, 7, 6, 5, 4, 3])
    assert(gen(-2, -7) == [-2, -7, -3, -4, -5, -6])

main()
