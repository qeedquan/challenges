#!/usr/bin/env python3

"""

Inspired in part by this Mathologer video on gorgeous visual "shrink" proofs,
and my general interest in the topic, this challenge will have you count regular polygons with integer coordinates in 3D.

You'll be provided an input n, which is a non-negative integer.
Your program should find the number of subsets of  {0,1,…,n}^3 such that the points are the vertices of a regular polygon.
That is, the vertices should be 3D coordinates with nonnegative integers less than or equal to n.

Examples
For n=4, there are 2190 regular polygons: 1264 equilateral triangles, 810 squares, and 116 regular hexagons.

An example of each:

Triangle:  (1,0,1),(0,4,0),(4,3,1)
Square:  (1,0,0),(4,3,0),(3,4,4),(0,1,4)
Hexagon:  (1,1,0),(0,3,1),(1,4,3),(3,3,4),(4,1,3),(3,0,1)

https://i.sstatic.net/HzOMO.png

The (zero-indexed) sequence begins:

0, 14, 138, 640, 2190, 6042, 13824, 28400, 53484, 94126, 156462, 248568, 380802, 564242, 813528, 1146472, 1581936, 2143878, 2857194, 3749240, 4854942, 6210442
Rules
To prevent the most naive and uninteresting kinds of brute-forcing, your program must be able to handle up to  a(5)=6042
  on TIO.

This is a code-golf challenge, so the shortest code wins.

This is now on the On-Line Encyclopedia of Integer Sequences as A338323.

"""

import itertools
import numpy as np

def is_valid_progression(points, n):
    a, b, c = points
    start = a
    while True:
        first_difference = b - a
        second_difference = c - b
        denominator = np.dot(second_difference, second_difference)

        if np.dot(first_difference, first_difference) != denominator:
            return 0

        numerator = 2 * np.dot(first_difference, second_difference) * second_difference
        next_point = c + a - b + numerator // denominator

        if np.any(numerator % denominator != 0) or np.any(next_point < 0) or np.any(next_point > n):
            return 0

        a, b, c = b, c, next_point
        if tuple(a) < tuple(start):
            return 0
        if np.array_equal(a, start):
            return 1

"""

https://oeis.org/A338323

Ported from @Peter Kagey solution

"""

def solve(n):
    points = np.indices((n + 1,) * 3).reshape(3, -1).T
    total = 0
    for triple in itertools.permutations(points, 3):
        if is_valid_progression(triple, n):
            total += 1
    return total // 2

def main():
    tab = [0, 14, 138, 640, 2190, 6042]

    for i in range(len(tab)):
        assert(solve(i) == tab[i])

main()
