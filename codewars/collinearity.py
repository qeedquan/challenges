#!/usr/bin/env python3

"""

Theoretical Material
You are given two vectors starting from the origin (x=0, y=0) with coordinates (x1,y1) and (x2,y2). Your task is to find out if these vectors are collinear. Collinear vectors are vectors that lie on the same straight line. They can be directed in the same or opposite directions. One vector can be obtained from another by multiplying it by a certain number. In terms of coordinates, vectors (x1, y1) and (x2, y2) are collinear if (x1, y1) = (k*x2, k*y2) , where k is any number acting as a coefficient.

https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/collinear-vectors-1627481628.png

For more information, check out this article on collinearity.

Problem Description
Write the function collinearity(x1, y1, x2, y2), which returns a Boolean type depending on whether the vectors are collinear or not.

all coordinates are integers
-1000 <= any coordinate <= 1000
Notes
All vectors start from the origin (x=0, y=0).
Be careful when handling cases where x1, x2, y1, or y2 are zero to avoid division by zero errors.
A vector with coordinates (0, 0) is collinear to all vectors.

Examples
(1,1,1,1) ➞ true
(1,2,2,4) ➞ true
(1,1,6,1) ➞ false
(1,2,-1,-2) ➞ true
(1,2,1,-2) ➞ false
(4,0,11,0) ➞ true
(0,1,6,0) ➞ false
(4,4,0,4) ➞ false
(0,0,0,0) ➞ true
(0,0,1,0) ➞ true
(5,7,0,0) ➞ true

"""

from numpy.linalg import det

def collinear(x1, y1, x2, y2):
    return det([[x1, y1, 1], [x2, y2, 1], [0, 0, 1]]) == 0

def main():
    assert(collinear(1, 1, 1, 1) == True)
    assert(collinear(1, 2, 2, 4) == True)
    assert(collinear(1, 1, 6, 1) == False)
    assert(collinear(1, 2, -1, -2) == True)
    assert(collinear(1, 2, 1, -2) == False)
    assert(collinear(4, 0, 11, 0) == True)
    assert(collinear(0, 1, 6, 0) == False)
    assert(collinear(4, 4, 0, 4) == False)
    assert(collinear(0, 0, 0, 0) == True)
    assert(collinear(0, 0, 1, 0) == True)
    assert(collinear(5, 7, 0, 0) == True)

main()
