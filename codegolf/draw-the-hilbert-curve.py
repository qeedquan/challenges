#!/usr/bin/env python3

"""

A Hilbert Curve is a type of space-filling curve, and it basically maps a line to a plane.
Each point in the line corresponds to just one point in the plane, and each point in the plane corresponds to just one point on the line.
Shown are iterations 0 through 4 of the Hilbert Curve:

Iterations 0 up to 4:

https://i.sstatic.net/4nXZn.png

The objective of this task: Write code that draws the fourth iteration of the Hilbert Curve, as defined above.
Your code should be complete - in other words, if you create a function to draw the Hilbert Curve, your code must call that function.
The output can either be displayed directly on the screen, or you can write the output to an image file.
The curve may be rotated or flipped, but lines must intersect at right angles and the output cannot be stretched.
ASCII art is appreciated but will not be accepted. Shortest code in bytes wins!

"""

import turtle

def draw(seq, depth):
    for _ in range(depth):
        new_seq = ""
        for char in seq:
            if char == "a":
                new_seq += "-bF+aFa+Fb-"
            elif char == "b":
                new_seq += "+aF-bFb-Fa+"
            else:
                new_seq += char
        seq = new_seq

    for char in seq:
        if char == "F":
            turtle.forward(9)
        elif char == "+":
            turtle.right(90)
        elif char == "-":
            turtle.left(90)

def main():
    draw("a", 5)

main()
