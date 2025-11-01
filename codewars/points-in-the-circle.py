#!/usr/bin/env python3

"""

You have the radius of a circle with the center in point (0,0).

Write a function that calculates the number of points in the circle where (x,y) - the cartesian coordinates of the points - are integers.

Example: for radius = 2 the result should be 13.

0 <= radius <= 1000

"""

# https://oeis.org/A000328
def points(r):
    if r < 0:
        return 0

    c = 1
    for y in range(1, r + 1):
        x = 0
        while x*x + y*y <= r*r:
            x += 1
            c += 4
    return c

def main():
    tab = [
        1, 5, 13, 29, 49, 81, 113, 149, 197, 253, 317, 377, 441, 529, 613, 709,
        797, 901, 1009, 1129, 1257, 1373, 1517, 1653, 1793, 1961, 2121, 2289,
        2453, 2629, 2821, 3001, 3209, 3409, 3625, 3853, 4053, 4293, 4513, 4777,
        5025, 5261, 5525, 5789, 6077, 6361, 6625
    ]

    for i in range(len(tab)):
        assert(points(i) == tab[i])

main()
