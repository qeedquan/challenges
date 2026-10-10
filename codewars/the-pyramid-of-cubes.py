#!/usr/bin/env python3

"""

The workers of CodeLand intend to build a brand new building in the town centre after the end of the 3rd Code Wars.

They intend to build a triangle-based pyramid (tetrahedron) out of cubes.

They require a program that will find the tallest potential height of the pyramid, given a certain number of cubes.

Your function needs to return the pyramid with largest number of full layers possible with the input.

The input will be an integer of how many cubes are available, and your output should return the height of the tallest pyramid buildable with that number of cubes.

The schematic below shows a cross-section of each layer of the pyramid, top down:

Layer 1 -

          x
Layer 2 -

          x
        x   x

Layer 3 -

          x
        x   x
      x   x   x

"""

from math import comb
from sympy import integer_nthroot

# https://oeis.org/A056556
def height(n):
    if n < 1:
        return 0
    m, _ = integer_nthroot(6*(n + 1), 3)
    if n >= comb(m + 2, 3):
        return m
    return m - 1

def main():
    tab = [
        0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
        7, 7, 7, 7, 7, 7, 7, 7, 7
    ]

    for i in range(len(tab)):
        assert(height(i) == tab[i])

main()
