#!/usr/bin/env python3

"""

Remember the triangle of balls in billiards? To build a classic triangle (5 levels) you need 15 balls. With 3 balls you can build a 2-level triangle, etc.

For more examples,

pyramid(1) == 1

pyramid(3) == 2

pyramid(6) == 3

pyramid(10) == 4

pyramid(15) == 5

Write a function that takes number of balls (≥ 1) and calculates how many levels you can build a triangle.

"""

from math import *

# https://oeis.org/A003056
def pyramid(n):
    if n < 1:
        return 0
    return floor((sqrt(1 + 8*n) - 1) / 2)

def main():
    tab = [
        0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6,
        6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12
    ]

    for i in range(len(tab)):
        assert(pyramid(i) == tab[i])

    assert(pyramid(1) == 1)
    assert(pyramid(3) == 2)
    assert(pyramid(6) == 3)
    assert(pyramid(10) == 4)
    assert(pyramid(15) == 5)

main()
