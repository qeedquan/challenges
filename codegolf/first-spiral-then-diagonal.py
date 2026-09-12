#!/usr/bin/env python3

"""

Given a positive input number n, construct a spiral of numbers from 1 to n^2, with 1 in the top-left, spiraling inward clockwise. Take the sum of the diagonals (if n is odd, the middle number n^2 is counted twice) and output that number.

Example for n=1:

1

(1) + (1) = 2
Example for n=2:

1 2
4 3

(1+3) + (4+2) = 4 + 6 = 10
Example for n=4:

 1  2  3 4
12 13 14 5
11 16 15 6
10  9  8 7

(1+13+15+7) + (10+16+14+4) = 36 + 44 = 80
Example of n=5:

 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

(1+17+25+21+9) + (13+23+25+19+5) = 73 + 85 = 158

Further rules and clarifications
This is OEIS A059924 and there are some closed-form solutions on that page.
The input and output can be assumed to fit in your language's native integer type.
The input and output can be given in any convenient format.
You can choose to either 0-index or 1-index, as I am here in my examples, for your submission. Please state which you're doing.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

"""

from math import *

# https://oeis.org/A059924
def spiralsquare(n):
    return floor((16*n**3 - 6*n**2 + 8*n + 3 - 3*(-1**n))/12)

def main():
    tab = [0, 2, 10, 34, 80, 158, 274, 438, 656, 938, 1290, 1722, 2240, 2854, 3570, 4398, 5344, 6418, 7626, 8978, 10480, 12142, 13970, 15974, 18160, 20538, 23114, 25898, 28896, 32118, 35570, 39262, 43200, 47394, 51850, 56578, 61584, 66878, 72466, 78358]

    for i in range(len(tab)):
        assert(spiralsquare(i) == tab[i])

main()
