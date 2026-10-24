#!/usr/bin/env python3

"""

See also: Wordagons
https://codegolf.stackexchange.com/questions/92297/hexagolf-wordagons

Challenge
Given a hexagon and a number n as input, output the same hexagon rotated n times.

Hexagon
The hexagon will be a string like so:

  a b c
 d d e e
f f o g g
 h h i i
  j k l
The hexagon will always be regular and will only ever contain the printable ASCII characters:

 !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
Rotation
To find how much to rotate the hexagon by, multiply n by 60 degrees to get the angle of rotation. For example, using the above hexagon, if n is 2, we multiply that by 60 to get 120 degrees. Then, we rotate the hexagon by 120 degrees:

  j h f
 k h f d
l i o d a
 i g e b
  g e c
Note that each side has moved two sides clockwise.

If n is positive, you should rotate the hexagon clockwise. If n is negative, you should rotate the hexagon anticlockwise.

n will always be an integer in the range -6 to 6 inclusive.

Examples
Input:

  . u .
 .  |  .
l - + - r
 .  |  .
  . d .
n = 3

  . d .
 .  |  .
r - + - l
 .  |  .
  . u .
Input:

  - - -
 /     \
<       >
 \     /
  - - -
n = -1

Output:

  - \ >
 -     /
-       -
 /     -
  < \ -
Input:

   h e x a
  g o n s a
 n d t r i a
n g l e s m a
 k e m e s a
  d l y m a
   d d e r
n = 6

Output:

   h e x a
  g o n s a
 n d t r i a
n g l e s m a
 k e m e s a
  d l y m a
   d d e r

Winning
The shortest program in bytes wins.

"""

from turtle import *

# ported from @mbomb007 solution
def rotagon(h, n):
    reset()
    penup()
    right(n*60)
    l = 0
    for c in h:
        write(c)
        forward(9)
        l -= 1
        if " " > c:
            forward(9*l)
            right(90)
            forward(15)
            right(270)
            l = 0
    hideturtle()

    print("Enter a key to continue")
    input()

rotagon("""  . u .
 .  |  .
l - + - r
 .  |  .
  . d .""", 3)
  
rotagon("""  - - -
 /     \\
<       >
 \\     /
  - - -""", -1)
  
rotagon("""   h e x a
  g o n s a
 n d t r i a
n g l e s m a
 k e m e s a
  d l y m a
   d d e r""", 1)
