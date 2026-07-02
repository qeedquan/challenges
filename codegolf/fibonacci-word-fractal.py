#!/usr/bin/env python3

"""

The Fibonacci word is a sequence of binary strings defined as:

F0=0
F1=01
Fn=F[n-1]*F[n-2]
The first few Fibonacci words are:

0
01
010
01001
01001010
0100101001001
010010100100101001010
...
Each of these strings is a prefix of the next, so they are all prefixes of the single infinite word
F∞=010010100100101001010010010100100101001010010010100101001001010010010100101001001010010010100101001...
(The definition above is borrowed from this sandbox challenge by pxeger.)

Now we can define a fractal curve based on the Fibonacci words.

Starting from some point on the plane, for each digit at position k of the Fibonacci word F∞:

Draw a segment with length 1 forward,
If the digit is 0:
Turn 90° to the left if k is even,
Turn 90° to the right if k is odd.
This is called the Fibonacci word fractal.

For example, the first 21 digits in F∞ are 010010100100101001010, which would give the following shape:

┌
│ ┌─┐
└─┘ │
   ┌┘
   │
   └┐
┌─┐ │
│ └─┘
To be clearer, let's mark the starting point by ^, and replace the other chars by its corresponding digit in the Fibonacci word:

0
1 010
010 1
   00
   1
   00
010 1
^ 010

Here are some more steps of the Fibonacci word fractals, taken from Wikipedia:

"""

from turtle import *

def fibword(n):
    a, b, i = [0], [90], 0
    while n > 0:
        if i >= len(b):
            a, b, n = b, b + a, n - 1

        lt(b[i]*(-1)**i)
        fd(5)
        i += 1

def main():
    speed(0)
    fibword(50)
    exitonclick()

main()
