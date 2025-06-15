#!/usr/bin/env python3

"""

Challenge
Create a program that outputs a square grid showing visible and non-visible points (x,y) from the origin based on their greatest common divisor (GCD).

A point (x,y) is considered visible from the origin (0,0) if the gcd(x,y)=1. Otherwise, it's non-visible.

https://i.stack.imgur.com/kf2YF.png

Input

An integer n, representing the radius of the square grid from the origin along both x and y axes.

Output

A square grid centered at the origin, where each cell is:

". " (dot followed by a space) for a visible point
"
" (two spaces) for a non-visible point

Examples
Length from the origin: n = 6

  .       .   .       .
.   . . . .   . . . .   .
  .   .   .   .   .   .
  . .   . .   . .   . .
  .   .   .   .   .   .
. . . . . . . . . . . . .
          .   .
. . . . . . . . . . . . .
  .   .   .   .   .   .
  . .   . .   . .   . .
  .   .   .   .   .   .
.   . . . .   . . . .   .
  .       .   .       .
Length from the origin: n = 5

  . . . .   . . . .
.   .   .   .   .   .
. .   . .   . .   . .
.   .   .   .   .   .
. . . . . . . . . . .
        .   .
. . . . . . . . . . .
.   .   .   .   .   .
. .   . .   . .   . .
.   .   .   .   .   .
  . . . .   . . . .
Length from the origin: n = 4

  .   .   .   .
.   . .   . .   .
  .   .   .   .
. . . . . . . . .
      .   .
. . . . . . . . .
  .   .   .   .
.   . .   . .   .
  .   .   .   .
Length from the origin: n = 3

  . .   . .
.   .   .   .
. . . . . . .
    .   .
. . . . . . .
.   .   .   .
  . .   . .
Length from the origin: n = 2

  .   .
. . . . .
  .   .
. . . . .
  .   .
Length from the origin: n = 1

. . .
.   .
. . .

References
Visible Points in a Lattice

Visible Point -- from Wolfram MathWorld

Lattice points visible from the origin

"""

from math import *

def lattice(n):
    print("n=%d" % (n))
    for y in range(-n, n+1):
        for x in range(-n, n+1):
            if gcd(x, y) == 1:
                print(". ", end="")
            else:
                print("  ", end="")
        print()
    print()

def main():
    for i in range(6, 0, -1):
        lattice(i)

main()
