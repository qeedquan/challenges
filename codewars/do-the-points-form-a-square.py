#!/usr/bin/env python3

"""

You are given a list of four points (x, y). Each point is a tuple

Your task is to write a function which takes an array of points and returns whether they form a is_squareuare.

If the array doesn't contain 4 points, return False.

All points coordinates are integers.

Squares can be rotated using a random degree.

Examples
((1,1), (3,3), (1,3), (3,1)) -> True
((0, 0), (0,2), (2,0), (2,1)) -> False
([]) -> False

Constraints:
1 <= x, y <= 1000

Note:

Performance does not enforced in this kata.

"""

def distance2(p1, p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

def is_square(p):
    if len(p) != 4:
        return False

    d = []
    for i in range(4):
        for j in range(i + 1, 4):
            d.append(distance2(p[i], p[j]))
    d.sort()
    
    return (
        d[0] > 0 and
        d[0] == d[1] and d[1] == d[2] and d[2] == d[3] and d[4] == d[5] and
        d[4] == 2*d[0]
    )

def main():
    assert(is_square([(1, 1), (3, 3), (1, 3), (3, 1)]) == True)
    assert(is_square([(0, 0), (0, 2), (2, 0), (2, 1)]) == False)
    assert(is_square([]) == False)
    assert(is_square([(0, 0), (0, 2), (2, 0), (2, 1)]) == False)
    assert(is_square([(1, 1), (3, 3), (1, 3), (3, 1)]) == True)
    assert(is_square([(1, 1), (2, 3), (4, 2), (3, 0)]) == True)
    assert(is_square([(0, 2), (0, -2), (1,0), (-1, 0)]) == False)
    assert(is_square([(0, 0), (0, 1), (0, 1), (0, 2)]) == False)
    assert(is_square([(0, 0), (0, 0), (2, 0), (2, 0)]) == False)
    assert(is_square([]) == False)
    assert(is_square([(0, 0), (0, 0), (0, 0), (0, 0)]) == False)
        
main()
