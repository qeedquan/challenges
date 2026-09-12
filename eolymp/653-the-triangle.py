#!/usr/bin/env python3

"""

In Euclidean geometry, triangles can be divided into three types based on their angles.
A triangle is called acute if all three of its angles are less than 90 degrees.
A triangle is called obtuse if one of its angles is greater than 90 degrees.
Finally, a triangle is called right if one of its angles is equal to 90 degrees.

Input
A single line contains three positive integers A, B, and C separated by spaces, representing the lengths of the sides of a triangle. (1≤A,B,C≤10000)

Output
Print one of the following words:

IMPOSSIBLE – if such a triangle does not exist;

ACUTE – if the triangle is acute;

OBTUSE – if the triangle is obtuse;

RIGHT – if the triangle is right.

Examples

Input #1
3 4 5

Answer #1
RIGHT

Input #2
3 4 4

Answer #2
ACUTE

Input #3
3 4 6

Answer #3
OBTUSE

Input #4
7 4 3

Answer #4
IMPOSSIBLE

"""

def solve(a, b, c):
    if a > b:
        a, b = b, a
    if a > c:
        a, c = c, a
    if b > c:
        b, c = c, b

    if c >= a + b:
        return "IMPOSSIBLE"
    if c*c < a*a + b*b:
        return "ACUTE"
    if c*c == a*a + b*b:
        return "RIGHT"
    return "OBTUSE"

def main():
    assert(solve(3, 4, 5) == "RIGHT")
    assert(solve(3, 4, 4) == "ACUTE")
    assert(solve(3, 4, 6) == "OBTUSE")
    assert(solve(7, 4, 3) == "IMPOSSIBLE")

main()
