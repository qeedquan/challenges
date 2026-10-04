#!/usr/bin/env python3

"""

Take the numbers 0, 1, 2, 3, 4, ... and arrange them in a clockwise spiral, starting downward, writing each digit in its own separate square.

Then, given one of four distinct and consistent ASCII characters (your choice) representing an axis, and an input integer n, output the first n terms of the sequence described by selecting squares along the corresponding axis.

For example, below is the arranged spiral up to partway through 29. Suppose we use u / d / l / r for our four characters, representing up / down / left / right. Then, given u as input, we output 0, 5, 1, 4 ... (the positive y-axis) up to the nth term. If we were instead given l as input, then it would be 0, 3, 1, 1 ... up to the nth term.

  2---3---2---4---2---5---2
  |                       |
  2   1---3---1---4---1   6
  |   |               |   |
  2   2   4---5---6   5   2
  |   |   |       |   |   |
  1   1   3   0   7   1   7
  |   |   |   |   |   |   |
  2   1   2---1   8   6   2
  |   |           |   |   |
  0   1---0---1---9   1   8
  |                   |   |
  2---9---1---8---1---7   2
These are sequences on OEIS:

http://oeis.org/A033953 for the positive x-axis
http://oeis.org/A033988 for the positive y-axis
http://oeis.org/A033989 for the negative x-axis
http://oeis.org/A033990 for the negative y-axis

Examples
d 19
[0, 1, 1, 8, 3, 7, 6, 2, 1, 5, 1, 1, 6, 2, 2, 1, 3, 4, 0]

r 72
[0, 7, 1, 7, 4, 2, 8, 1, 1, 3, 1, 2, 0, 2, 3, 1, 3, 4, 6, 5, 5, 5, 7, 7, 8, 8, 9, 6, 8, 1, 1, 1, 2, 3, 1, 8, 0, 6, 1, 7, 0, 9, 2, 8, 4, 3, 2, 1, 1, 7, 2, 6, 2, 1, 3, 3, 5, 5, 3, 2, 2, 0, 4, 3, 2, 5, 4, 6, 5, 0, 5, 1]

u 1
[0]
Rules
If applicable, you can assume that the input/output will fit in your language's native Integer type.
If you're using integers to represent the four axes, you can use negative integers without breaking the rules.
The input and output can be given by any convenient method.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

"""

from math import *

# https://oeis.org/A033307
def champernowne(n):
    if n < 1:
        return "0"

    s = ""
    for i in range(1, n+1):
        s += str(i)
    return s

"""

https://oeis.org/A033953 (right)
https://oeis.org/A033988 (up)
https://oeis.org/A033989 (left)
https://oeis.org/A033990 (down)

"""
def spiral(d, n):
    if d not in "udlr":
        return None

    if n < 0:
        return []

    r = [0]
    c = champernowne(4*n*n + 3*n + 1)
    for i in range(1, n):
        if d == 'u':
            p = 4*i*i + i
        elif d == 'd':
            p = 4*i*i - 3*i
        elif d == 'l':
            p = 4*i*i - i
        elif d == 'r':
            p = 4*i*i + 3*i
        r.append(int(c[p-1]))
    return r

def main():
    assert(spiral('d', 19) == [0, 1, 1, 8, 3, 7, 6, 2, 1, 5, 1, 1, 6, 2, 2, 1, 3, 4, 0])
    assert(spiral('r', 72) == [0, 7, 1, 7, 4, 2, 8, 1, 1, 3, 1, 2, 0, 2, 3, 1, 3, 4, 6, 5, 5, 5, 7, 7, 8, 8, 9, 6, 8, 1, 1, 1, 2, 3, 1, 8, 0, 6, 1, 7, 0, 9, 2, 8, 4, 3, 2, 1, 1, 7, 2, 6, 2, 1, 3, 3, 5, 5, 3, 2, 2, 0, 4, 3, 2, 5, 4, 6, 5, 0, 5, 1])
    assert(spiral('u', 105) == [0, 5, 1, 4, 3, 7, 8, 0, 4, 7, 7, 1, 2, 6, 2, 1, 8, 7, 4, 2, 6, 1, 8, 9, 2, 7, 6, 0, 6, 5, 1, 2, 0, 4, 1, 5, 8, 5, 1, 8, 8, 8, 2, 1, 2, 3, 2, 4, 9, 0, 2, 8, 9, 9, 3, 3, 2, 0, 3, 7, 9, 3, 4, 2, 8, 8, 4, 7, 1, 5, 5, 3, 7, 4, 5, 9, 7, 5, 6, 5, 9, 8, 7, 1, 5, 3, 7, 8, 4, 0, 8, 5, 6, 9, 9, 3, 1, 0, 9, 8, 1, 1, 6, 9, 9])
    assert(spiral('l', 105) == [0, 3, 1, 1, 3, 2, 7, 9, 1, 1, 6, 9, 4, 7, 9, 1, 2, 1, 2, 1, 6, 7, 4, 3, 6, 1, 2, 9, 5, 1, 1, 0, 9, 3, 1, 3, 6, 6, 1, 8, 6, 9, 2, 5, 0, 2, 2, 4, 6, 6, 2, 5, 6, 0, 3, 8, 9, 5, 3, 3, 6, 9, 4, 0, 5, 4, 4, 9, 8, 0, 5, 0, 4, 5, 5, 3, 3, 1, 6, 8, 5, 8, 6, 5, 1, 4, 7, 4, 9, 1, 8, 5, 1, 9, 9, 8, 6, 6, 9, 1, 1, 6, 4, 8, 1])

main()
