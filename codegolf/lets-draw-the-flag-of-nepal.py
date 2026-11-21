#!/usr/bin/env python3

"""

Nepal’s flag (Wikipedia, Numberphile) looks very different from any other. It also has specific drawing instructions (included in the Wikipedia article). I want you guys to make a program which will draw the flag of Nepal.

The user inputs the requested height of the flag (from 100 to 10000 pixels) and the program outputs the flag of Nepal. You can choose any way to draw the flag: everything from ASCII art to OpenGL.

This is a popularity contest, so the winner will be the highest voted answer on the 1st of February, so don’t worry about length of code, but remember that shorter code may get more up-votes.

There is only one requirement: you are not allowed to use web resources.

Have fun :)

https://upload.wikimedia.org/wikipedia/commons/thumb/9/9b/Flag_of_Nepal.svg/394px-Flag_of_Nepal.svg.png

"""

import turtle, sys
from math import sqrt, sin, cos, pi

# ported from @mniip solution
def nepal(width, height):
    t = turtle.Turtle()

    # the layout
    t.pencolor("#0044cc")
    t.fillcolor("#cc2244")
    t.pensize(width / 25)
    t.pendown()
    t.begin_fill()
    t.forward(width)
    t.left(135)
    t.forward(width)
    t.right(135)
    t.forward(width / sqrt(2))
    t.right(90)
    t.goto(0, height)
    t.forward(height)
    t.end_fill()
    t.penup()

    # the bottom star
    t.fillcolor("#ffffff")
    t.pencolor("#ffffff")
    t.pensize(1)
    radius = width / 5
    x = width / 4
    y = height / 4
    t.goto(x + radius, y)
    t.pendown()
    t.begin_fill()
    for i in range(24):
        t.goto(x + radius * (5 + (-1)**i) / 6 * cos(i * pi / 12), y + radius * (5 + (-1)**i) / 6 * sin(i * pi / 12))
    t.end_fill()
    t.penup()

    # the top star
    radius = width / 9
    x = width / 4
    y = height * 2 / 3
    t.goto(x + radius, y)
    t.pendown()
    t.begin_fill()
    for i in range(28):
        t.goto(x + radius * (6 + (-1)**i) / 7 * cos(i * pi / 14), y + radius * (6 + (-1)**i) / 7 * sin(i * pi / 14))
    t.end_fill()
    t.penup()

    # the moon
    radius = width / 5
    x = width / 4
    y = height / sqrt(2)
    t.goto(x + radius, y)
    t.pendown()
    t.begin_fill()
    for i in range(30):
        t.goto(x + radius * cos(i * pi / 30), y - radius * sin(i * pi / 30))
    for i in range(30):
        t.goto(x - radius * cos(i * pi / 30), y - radius / 2 * sin(i * pi / 30))
    t.end_fill()
    t.penup()
    t.hideturtle()

def main():
    height = 200
    if len(sys.argv) > 1:
        height = int(sys.argv[1])
    width = height // 4 * 3

    turtle.title("Nepal Flag")
    turtle.screensize(width, height)
    nepal(width, height)
    turtle.mainloop()

main()
