#!/usr/bin/env python3

"""

Problem

Given a value n, imagine a mountain landscape inscribed in a reference (0, 0) to (2n, 0). There musn't be white spaces between slopes and also the mountain musn't descend below the x axis. The problem to be solved is: given n (which defines the size of the landscape) and the number k of peaks (k always less than or equal to n), how many combinations of mountains are possible with k peaks?

Input

n who represents the width of the landscape and k which is the number of peaks.

Output

Just the number of combinations possible.

Example

Given n=3 and k=2 the answer is 3 combinations.

Just to give a visual example, they are the following:

   /\     /\      /\/\
/\/  \   /  \/\  /    \
are the 3 combinations possible using 6 (3*2) positions and 2 peaks.

Edit: - more examples -

n  k  result
2  1  1
4  1  1
4  3  6
5  2  10
Winning condition

Standard code-golf rules apply. The shortest submission in bytes wins.

"""

from math import *

"""

https://en.wikipedia.org/wiki/Narayana_number
https://oeis.org/A001263

"""

def mountains(n, k):
    return (comb(n, k) * comb(n, k - 1)) // n

def main():
    assert(mountains(2, 1) == 1)
    assert(mountains(4, 1) == 1)
    assert(mountains(4, 3) == 6)
    assert(mountains(5, 2) == 10)

main()
