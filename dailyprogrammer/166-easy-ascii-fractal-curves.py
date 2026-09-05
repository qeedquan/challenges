#!/usr/bin/env python3

"""

Today we're going to set a more open-ended challenge. First, let's look at what a space-filling curve is.

A space-filling curve is a specific type of line/curve that, as you recreate it in more and more detail, fills more and more of the space that it's in, without (usually) ever intersecting itself. There are several types of space-filling curve, and all behave slightly differently. Some get more and more complex over time whereas some are the same pattern repeated over and over again.

Your challenge will be to take any space-fulling curve you want, and write a program that displays it to a given degree of complexity.

Formal Inputs and Outputs
Input Description
The input to this challenge is extremely simple. You will take a number N which will be the degree of complexity to which you will display your fractal curve. For example, this image shows the Hilbert curve shown to 1 through 6 degrees of complexity.

Output Description
You must print out your own curve to the given degree of complexity. The method of display is up to you, but try and stick with the ASCII theme - for example, see below.

Sample Inputs & Output
Sample Input
(Hilbert curve program)

3
Sample Output
# ##### ##### #
# #   # #   # #
### ### ### ###
    #     #
### ### ### ###
# #   # #   # #
# ##### ##### #
#             #
### ### ### ###
  # #     # #
### ### ### ###
#     # #     #
# ### # # ### #
# # # # # # # #
### ### ### ###

Notes
Recursive algorithms will come in very handy here. You'll need to do some of your own research into the curve of your choice.

"""

import turtle
import math
import sys

def recurse(pen, depth, maxdepth):
    if depth > maxdepth:
        return

    length = 180*((math.sqrt(2)/2)**depth)
    pen0 = pen.clone()
    pen.forward(length)
    pen.left(45)
    recurse(pen, depth+1, maxdepth)
    pen0.right(90)
    pen0.forward(length)
    pen0.left(90)
    pen0.forward(length)
    if depth != maxdepth:
        pen1 = pen0.clone()
        pen1.left(45)
        pen1.forward(180*((math.sqrt(2)/2)**(1+depth)))
        pen1.right(90)
        recurse(pen1, depth+1, maxdepth)
    pen0.left(90)
    pen0.forward(length)

# ported from @toodim solution
def pythagoras_tree(maxdepth):
    window = turtle.Screen()
    pen = turtle.Turtle()
    pen.hideturtle()
    pen.penup()
    pen.goto(-75, -225)
    pen.pendown()
    pen.speed(0)
    pen.left(90)
    recurse(pen, 1, maxdepth)
    window.exitonclick()

def main():
    if len(sys.argv) < 2:
        print("usage: <depth>")
        exit(2)

    maxdepth = int(sys.argv[1])
    pythagoras_tree(maxdepth)

main()
