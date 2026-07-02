#!/usr/bin/env python3

"""

Given the coordinates of the upper left corners of two squares and their side lengths, determine whether the squares overlap. A square includes the top and left lines, but not the bottom and right lines. That is, a point (a,b) is inside a square with side length k that starts at (x,y) if and only if x <= a < x+k and y <= b < y+k. A square with side length 0 is degenerate and will not be considered here, thus, k will be positive.

As usual, all standard rules apply. Input and output may be in whatever form is convenient, so long as it's human readable and there is no precomputation. Be sure to specify what input format you use. Your code should take six numbers and output truthy if the squares overlap and falsy otherwise.

Test Cases
x1 y1 k1  x2 y2 k2  overlap?
 1  1  1   0  1  1  false
 0  0  3   1  1  1  true
 1  1  1   0  0  3  true
 0  0  3   2  1  2  true
 0  0  2   1  1  2  true
 1  1  2   0  0  2  true
 0  1  2   1  0  2  true
 1  0  2   0  1  2  true
 2  0  2   0  2  2  false
 1  0  3   0  1  1  false
 0  2  3   0  0  2  false
All inputs will be non-negative integers. That said, I expect that many or most solutions will also be able to handle negatives and floats.

"""

"""

@xnor

lambda x,y,k,X,Y,K:k>X-x>-K<Y-y<k
Python supports chains of inequalities even when they point opposite directions.

The x-coordinate intervals [x,x+k) and [X,X+K) overlap as long as neither one is fully to the right of the other, which means that each interval's left endpoint is left of the other interval's right endpoint.

x<X+K
X<x+k
The can be combined into a joint inequality -K<X-x<k. Writing the same for y-coordinates and splicing them at -K gives the expression

k>X-x>-K<Y-y<k

"""

def overlap(x, y, k, X, Y, K):
    dx = X - x
    dy = Y - y
    return (-K < dx and dx < k) and (-K < dy and dy < k)

def main():
    assert(overlap(1, 1, 1, 0, 1, 1) == False)
    assert(overlap(0, 0, 3, 1, 1, 1) == True)
    assert(overlap(1, 1, 1, 0, 0, 3) == True)
    assert(overlap(0, 0, 3, 2, 1, 2) == True)
    assert(overlap(0, 0, 2, 1, 1, 2) == True)
    assert(overlap(1, 1, 2, 0, 0, 2) == True)
    assert(overlap(0, 1, 2, 1, 0, 2) == True)
    assert(overlap(1, 0, 2, 0, 1, 2) == True)
    assert(overlap(2, 0, 2, 0, 2, 2) == False)
    assert(overlap(1, 0, 3, 0, 1, 1) == False)
    assert(overlap(0, 2, 3, 0, 0, 2) == False)

main()
