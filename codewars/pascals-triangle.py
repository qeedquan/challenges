#!/usr/bin/env python3

"""

In mathematics, Pascal's triangle is a triangular array of the binomial coefficients.

You can read Wikipedia article on Pascal's Triangle for more information.

Task
Write a function that, given a depth n, returns n top rows of Pascal's Triangle flattened into a one-dimensional list/array.

Example:
n = 1: [1]
n = 2: [1,  1, 1]
n = 4: [1,  1, 1,  1, 2, 1,  1, 3, 3, 1]
Note
Beware of overflow. Requested terms of a triangle are guaranteed to fit into the returned type, but depending on seleced method of calculations, intermediate values can be larger.

"""

from math import comb

def pascal_triangle(n):
    r = []
    for i in range(n):
        for j in range(i + 1):
            r.append(comb(i, j))
    return r

def main():
    assert(pascal_triangle(1) == [1])
    assert(pascal_triangle(2) == [1, 1, 1])
    assert(pascal_triangle(4) == [1, 1, 1, 1, 2, 1, 1, 3, 3, 1])

main()
