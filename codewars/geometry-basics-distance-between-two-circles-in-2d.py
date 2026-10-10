#!/usr/bin/env python3

"""

This series of katas will introduce you to basics of doing geometry with computers.

Point objects have x, y attributes. Circle objects have center which is a Point, and radius which is a number.

Write a function calculating distance between Circle a and Circle b.

If they're overlapping or one is completely within the other, just return zero.

Tests round answers to 6 decimal places, so you don't need to round them yourselves.

"""

from math import hypot

def distance(x1, y1, r1, x2, y2, r2):
    d = hypot(x2 - x1, y2 - y1) - (r1 + r2)
    return max(d, 0)

def main():
    assert(distance(1, 1, 1, 1, 1, 1) == 0)

main()
