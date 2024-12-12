#!/usr/bin/env python3

"""

We've had a couple of challenges about the Ulam spiral. But that's not enough.

In this challenge we will plot a triangular Ulam spiral (as opposed to the usual, square Ulam spiral). Here's a sketch of what the spiral looks like.

https://i.stack.imgur.com/n4BpX.png

As we know, the Ulam spiral arranges all natural numbers in an outward spiral, and marks only those that are prime. So in the above sketch only the numbers that appear in black (the primes) would be shown.

The challenge
Accept a number N as input and display the triangular Ulam spiral up to that number.

Input can be stdin or function argument.
The spiral should turn in the positive direction (that is, counter-clockwise), as in the above figure.
Any of the 120-degree turns of the above figure would be valid, and the turn may be different for different inputs. But the lowest side of the implied triangles should be horizontal, as the only allowed turns are (multiples of) 120 degrees.
The code should run theoretically (given enough time and memory) for any N up to what is allowed by any intermediate calculations you do with your default data type. double is enough; no need for large integer types.
All built-in functions allowed.
I won't accept my own answer (not that I think it would be the shortest anyway...).
Output formats
Choose any of the following.

Display a graph with a marker (dot, circle, cross, whatever you prefer) at prime numbers, and nothing at non-prime numbers. Scale need not be the same for the two axes. That is, the implied triangles need not be equilateral. Axes, grid lines and axis labels are optional. Only the markers at the prime numbers are required.

An example output for N = 12 would be as follows (compare with the above sketch). The second plot is a more interesting example, corresponding to N = 10000.

https://i.stack.imgur.com/sCN3u.png
https://i.stack.imgur.com/Dkq3j.png

Produce an image file with the above, in any well known image format (such as png, tiff, bmp).
Display the spiral as ASCII art, using a single character of your choice for primes and blank space for non-primes, with a blank space to separate number positions in the same row. Leading or trailing spaces or newlines are allowed. For example, the N = 12 case using o as character would be

             o
            · ·
           · o ·
            o · ·
           · o · o
where of course only the o mark at primes would actually be displayed. The · at non-primes is shown here for reference only.

Winning criterion
The actual reward is seeing for yourself those amazing patterns Code golf, shortest code wins.

"""

from matplotlib.pyplot import *
from math import *

# Base on @lambruscoAcido solution
def triangular_ulam_spiral(n):
    s = []
    X = []
    Y = []
    i = x = y = 0
    while len(s) < n:
        i += 1
        s += [(i%3)*pi*2 / 3] * i
    for i in range(n):
        x += cos(s[i])
        y += sin(s[i])
        j = i + 2
        if all(map(lambda a: j % a >= 1, range(2, int(sqrt(j) + 1)))):
            X += [x]
            Y += [y]
    scatter(X, Y)
    show()

def main():
    triangular_ulam_spiral(100000)

main()
