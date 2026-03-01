#!/usr/bin/env python3

"""

Challenge
Given two line segments, your goal is to write a function which determines if they intersect using only the operations given below:

Multiplication: x*y
Division: x/y
Addition: x+y
Subtraction: x-y
Negation: -x (this can be thought of as multiplying by -1)
Assignment: new_var = x
You are also allowed any of the following comparisons:

Equality: x==y
Inequality: x!=y
Greater than: x>y
Greater than or equal: x>=y
Less than: x<y
Less than or equal: x<=y
Operations and comparisons cost 1 score each. This is code-golf, so the lowest score wins.

Assumptions
For simplicity you may take the line segments as four points A, B, C, D where the segments are from A to B and from C to D. Indexing these points (i.e. A[0] for the x coordinate of A) does not add to your score (in reality the function could simply take each coordinate as an input for 8 total inputs). Returning, branching, operation ordering (parentheses), and constants are all free as well.

You may additionally assume that all inputs are integers, and that both segments have non-zero length. The division operation is infinitely accurate (imagine some sort of symbolic math library is used), however, your function should avoid any possibility of dividing by zero.

The output for intersecting lines should be True, and the output for non-intersecting lines should be False.

Scored example
To demonstrate the scoring, I'll provide an example which solves a different problem: determining whether two lines are parallel.

Score: 7

def is_parallel(A, B, C, D):
    if ((A[0] - B[0]) * (C[1] - D[1])) == ((A[1] - B[1]) * (C[0] - D[0])):  # 6 operations, 1 comparison
        return True
    else:
        return False
Test cases
Note that the line segments' endpoints are included for intersection.

[0, 0], [9, 9], [0, 9], [9, 0] -> True
[-9, -9], [-1, 1], [-7,2], [2,-5] -> True
[0, 0], [0, 9], [0, 5], [5, 5] -> True
[0, 0], [0, 9], [0, 0], [5, 5] -> True
[0, 0], [-1, -1], [0, 0], [5, 5] -> True
[2, 3], [5, 1], [3, 2], [0, 4] -> False
[2, 3], [5, 1], [3, 1], [-6, 1] -> False
[2, 3], [5, 1], [3, 2], [0, 0] -> False

"""

# https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection 
def intersect(p1, p2, p3, p4):
    x1, y1 = p1[0], p1[1]
    x2, y2 = p2[0], p2[1]
    x3, y3 = p3[0], p3[1]
    x4, y4 = p4[0], p4[1]

    if p1 == p3 or p1 == p4:
        return True
    if p2 == p3 or p2 == p4:
        return True

    t = (x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)
    u = (x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)
    d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)
    if d == 0:
        return False

    t = t / d
    u = -u / d
    return (0 <= t and t <= 1) and (0 <= u and u <= 1)

def main():
    assert(intersect([0, 0], [9, 9], [0, 9], [9, 0]) == True)
    assert(intersect([-9, -9], [-1, 1], [-7, 2], [2, -5]) == True)
    assert(intersect([0, 0], [0, 9], [0, 5], [5, 5]) == True)
    assert(intersect([0, 0], [0, 9], [0, 0], [5, 5]) == True)
    assert(intersect([0, 0], [-1, -1], [0, 0], [5, 5]) == True)
    assert(intersect([2, 3], [5, 1], [3, 2], [0, 4]) == False)
    assert(intersect([2, 3], [5, 1], [3, 1], [-6, 1]) == False)
    assert(intersect([2, 3], [5, 1], [3, 2], [0, 0]) == False)

main()
