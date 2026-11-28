#!/usr/bin/env python3

"""

Description
You are given four tuples. In each tuple there is coordinates x and y of a point. There is one and only one line, that goes through two points, so with four points you can have two lines: first and second tuple is two points of a first line, thirs and fourth tuple is two points of the second line. Your task is to find and return a tuple with x and y coordinates of lines crossing point.

Numbers can be positive as well as negative, integer or floats. Your answer shouldn't be rounded!!

Note, that if two lines are the same ( have infinite crossing points ) or parallel ( have no crossing points ), you will need to return None/Nothing depending on language.

https://justpaste.it/img/a6760541d86f232527c516f6882c28dc.png

Examples
find_the_crossing((5,3), (10,4), (5,7.5), (10,7)) => (20, 6) #from the graphic above
find_the_crossing((5,3), (10,4), (20,6), (0,2)) => None #edge case for two identical lines
find_the_crossing((5,3), (10,4), (5,5), (10,6)) => None #edge case for two parallel lines

Tests
There will be example tests, random tests and tests on big numbers.

Example tests are pre programmed tests for debugging.

Random tests are generated randomly, where -1000 ≤ x ≤ 1100. There is still will some with parallel and identical lines.

Tests on big numbers are random tests where -1000000000 ≤ x ≤ 1000000000

"""

import numpy as np

def crossing(p1, p2, p3, p4):
    (x1, y1) = p1
    (x2, y2) = p2
    (x3, y3) = p3
    (x4, y4) = p4

    d = (x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4)
    if d == 0:
        return None
   
    a = x1*y2 - y1*x2
    b = x3*y4 - y3*x4
    x = a*(x3 - x4) - b*(x1 - x2)
    y = a*(y3 - y4) - b*(y1 - y2)

    return (x/d, y/d)

def main():
    assert(np.allclose(crossing((5, 3), (10, 4), (5, 7.5), (10, 7)), (20, 6)))
    assert(np.allclose(crossing((0, 0), (4, 4), (2, 1), (4.5, -4)), (1.6666666666666667, 1.6666666666666667)))
    assert(crossing((5, 3), (10, 4), (20, 6), (0, 2)) == None)
    assert(crossing((5, 3), (10, 4), (5, 5), (10, 6)) == None)

main()
