#!/usr/bin/env python3

"""

If you're not into math, you might want to skip this kata.

Property
Some rectangles have a recurring ratio of side lengths (the most famous example is A-series paper). For some of them, when removing a number of inner squares (each such square must have the side length of the smallest side of the rectangle), the ratio a / b is the same as b / c.

Task
Given the number of inner squares to remove from such rectangle n, what is value of the ratio of the longer side over the smaller side? Don't round your result.

1 ≤ n ≤ 1000

"""

from numpy import allclose
from math import sqrt

def ratio(n):
    return (sqrt(n**2 + 4) + n) / 2

def main():
    assert(allclose(ratio(1), 1.618033988749895))
    assert(allclose(ratio(10), 10.099019513592784))
    assert(allclose(ratio(15), 15.06637297521078))
    assert(allclose(ratio(20), 20.04987562112089))
    assert(allclose(ratio(100), 100.00999900019994))

main()
