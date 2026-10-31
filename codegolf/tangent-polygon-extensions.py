#!/usr/bin/env python3

"""

Draw something that looks like this:

https://i.sstatic.net/DSVkX.jpg

In more precise terms, draw a circle of radius r, with n evenly-spaces tangent lines of length l.
Connect the ends of these lines to form a new n-sided regular polygon.

Rules
r = circle radius
n = number of tangent lines - must be evenly spaced around circle (n>=3)
l = side length of tangent lines

Create a program that accepts the arguments { r, n, l } and draws the required output.

Units are in pixels.

There is no restrictions to the location of the drawing, as long as all of it is visible.

The picture is pretty self-explanatory.

This is code-golf, so shortest code in bytes wins!

"""

from turtle import *
import sys

# ported from @Digital Trauma solution
def tangent_polygon(r, n, l):
    lt(90)
    for _ in range(n):
        circle(r, 360//n)
        fd(l)
        bk(l)
    fd(l)
    lt(towards(-r, 0) - 180)
    circle(distance(-r, 0), 360, n)

def main():
    r, n, l = 20, 6, 30
    if len(sys.argv) == 4:
        r, n, l = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])

    screen = Screen()
    screen.setup(640, 480)
    tangent_polygon(r, n, l)
    exitonclick()

main()
