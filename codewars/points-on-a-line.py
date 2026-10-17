#!/usr/bin/env python3

"""

Given some points (cartesian coordinates), return true if all of them lie on a line. Treat both an empty set and a single point as a line.

onLine([[1,2], [7, 4], [22, 9]]);                 // returns true
onLine([[1,2], [-3, -14], [22, 9]]);              // returns false

"""

from numpy.linalg import det

def collinear(x1, y1, x2, y2, x3, y3):
    return det([[x1, y1, 1], [x2, y2, 1], [x3, y3, 1]]) == 0

def online(points):
    for i in range(2, len(points)):
        x1, y1 = points[i - 2][0], points[i - 2][1]
        x2, y2 = points[i - 1][0], points[i - 1][1]
        x3, y3 = points[i - 0][0], points[i - 0][1]
        if not collinear(x1, y1, x2, y2, x3, y3):
            return False
    return True

def main():
    assert(online([[1, 2], [7, 4], [22, 9]]) == True)
    assert(online([[1, 2], [-3, -14], [22, 9]]) == False)
    assert(online([[1, 0], [2, 0], [3, 0], [4, 0], [5, 0], [6, 0], [7, 0]]) == True)
    assert(online([[1, 0], [2, 0], [3, 0], [4, 0], [5, 0], [6, 0], [7, 1]]) == False)

main()
