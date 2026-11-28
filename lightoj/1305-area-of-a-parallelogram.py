#!/usr/bin/env python3

"""

A parallelogram is a quadrilateral with two pairs of parallel sides. See the picture below:

https://static.lightoj.com/images/problem-1306-parallelogram-1603775703955.png?style=centerme,haveborder

Now you are given the co ordinates of A, B and C, you have to find the coordinates of D and the area of the parallelogram. The orientation of ABCD should be same as in the picture.

Input
Input starts with an integer T (≤ 1000), denoting the number of test cases.

Each case starts with a line containing six integers Ax, Ay, Bx, By, Cx, Cy where (Ax, Ay) denotes the coordinate of A, (Bx, By) denotes the coordinate of B and (Cx, Cy) denotes the coordinate of C. Value of any coordinate lies in the range [-1000, 1000]. And you can assume that A, B and C will not be collinear.

Output
For each case, print the case number and three integers where the first two should be the coordinate of D and the third one should be the area of the parallelogram.

Sample
Input	Output
3
0 0 10 0 10 10
0 0 10 0 10 -20
-12 -10 21 21 1 40

Case 1: 0 10 100
Case 2: 0 -20 200
Case 3: -32 9 1247

"""

def solve(ax, ay, bx, by, cx, cy):
    dx = ax + cx - bx
    dy = ay + cy - by
    A1 = ax*by + bx*cy + cx*dy + dx*ay
    A2 = ay*bx + by*cx + cy*dx + dy*ax
    return dx, dy, abs(A1 - A2) / 2

def main():
    print(solve(0, 0, 10, 0, 10, 10))
    print(solve(0, 0, 10, 0, 10, -20))
    print(solve(-12, -10, 21, 21, 1, 40))

main()
