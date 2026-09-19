#!/usr/bin/env python3

"""

Related: Draw A Reuleaux Triangle!, Draw a regular polygon

A Reuleaux polygon is a curve of constant width made up of circular arcs of constant radius. The most well-known Reuleaux polygon is the Reuleaux triangle, which has three sides1. In this challenge, you will be tasked to draw a regular Reuleaux polygon of a given number of sides.

A Reuleaux polygon is constructed by taking a polygon and replacing each of its sides with an arc centered at the opposite vertex.

This sort of shape can only be constructed from a polygon with an odd number of sides, so your input will be an odd number greater than or equal to three.

https://i.sstatic.net/bZ38ufAU.png
https://i.sstatic.net/3KKgUCLl.png
https://i.sstatic.net/AJBuKkC8.png
https://i.sstatic.net/2es8LqM6.png
https://i.sstatic.net/6hsI6.png
https://i.sstatic.net/y9brv.png

The circles in the first row are shown to demonstrate the construction; Your program's output should be closer to that of the second row (though the center mark is optional.)

Given an odd number ≥ 3 and, optionally, an arc radius, draw a regular Reuleaux polygon with that many sides. If you do not take an arc radius as input, ensure that the image is at a high enough resolution that the curves can be deciphered.

This is code-golf; the shortest solution in each language wins.

1 A curve can't have "sides" by the standard definition where each side is a line, but for the purposes of this task I am using the term "side" everywhere for simplicity.

"""

from turtle import *

"""

@Albert.Lang

How?
Observing that the arc lengths always sum to half a full circle we let the turtle draw a circle omitting every other of a total of 2n equal length arcs

"""

def regular_reuleaux_polygon(turtle, sides, step):
    for angle in range(sides * 8):
        turtle.left(45.0 / sides)
        turtle.forward((angle & 4)*step / sides)

def main():
    turtle = Turtle()
    turtle.speed(5)
    regular_reuleaux_polygon(turtle, 7, 40)
    mainloop()

main()
