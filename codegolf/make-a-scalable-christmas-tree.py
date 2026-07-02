#!/usr/bin/env python3

"""

Your challenge: Make a Christmas tree. The size must be choosable by some input method, but doesn't have to be directly related to any part of the tree; however, larger inputs should produce a larger tree.

How can you make it? You can make the tree any way you like, other than by printing the unicode character for the tree, such as ouputting an image, ascii art, with other aspects, etc.
Whatever you do, remember that this is a popularity-contest, so be creative.

The answer with the most upvotes by the end of December wins, but I'll accept another if it gets higher

"""

from turtle import *

"""

ported from @Keith Randall solution

"""

def star(n):
    speed("fastest")
    left(90)
    forward(3 * n)
    color("orange", "yellow")
    begin_fill()
    left(126)
    for i in range(5):
        forward(n / 5)
        right(144)
        forward(n / 5)
        left(72)
    end_fill()
    right(126)

    color("dark green")
    backward(n * 4.8)

def tree(d, s):
    if d <= 0:
        return
    forward(s)
    tree(d - 1, s * .8)
    right(120)
    tree(d - 3, s * .5)
    right(120)
    tree(d - 3, s * .5)
    right(120)
    backward(s)

def draw(n):
    star(n)
    tree(15, n)
    backward(n / 2)

def main():
    draw(50)

main()
