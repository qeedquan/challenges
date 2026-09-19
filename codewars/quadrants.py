#!/usr/bin/env python3

"""

Task
Given a point in a Euclidean plane (x and y), return the quadrant the point exists in: 1, 2, 3 or 4 (integer). x and y are non-zero integers, therefore the given point never lies on the axes.

Examples
(1, 2)     => 1
(3, 5)     => 1
(-10, 100) => 2
(-1, -9)   => 3
(19, -56)  => 4

Reference
https://upload.wikimedia.org/wikipedia/commons/thumb/1/1a/Cartesian_coordinates_2D.svg/300px-Cartesian_coordinates_2D.svg.png

There are four quadrants:

First quadrant, the quadrant in the top-right, contains all points with positive X and Y
Second quadrant, the quadrant in the top-left, contains all points with negative X, but positive Y
Third quadrant, the quadrant in the bottom-left, contains all points with negative X and Y
Fourth quadrant, the quadrant in the bottom-right, contains all points with positive X, but negative Y
More on quadrants: Quadrant (plane geometry) - Wikipedia

"""

def quadrant(x, y):
    if x >= 0 and y >= 0:
        return 1
    if x < 0 and y >= 0:
        return 2
    if x < 0 and y < 0:
        return 3
    return 4

def main():
    assert(quadrant(1, 2) == 1)
    assert(quadrant(3, 5) == 1)
    assert(quadrant(-10, 100) == 2)
    assert(quadrant(-1, -9) == 3)
    assert(quadrant(19, -56) == 4)

main()
