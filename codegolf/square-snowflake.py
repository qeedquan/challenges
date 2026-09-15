#!/usr/bin/env python3

"""

Produce this square snowflake.

XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX
XX   X   X   X   X   X   X   X   X   X   X   X   X   X   X   XX
X XXXX   XXXXX   XXXXX   XXXXX   XXXXX   XXXXX   XXXXX   XXXX X
  XX       X X   X X       X X   X X       X X   X X       XX
X X XXX XXXX       XXXX XXXX       XXXX XXXX       XXXX XXX X X
XXX XX   X X X   X X X   X X X   X X X   X X X   X X X   XX XXX
X   X XXXX XXX   XXX XXXXX XXX   XXX XXXXX XXX   XXX XXXX X   X
      XX               X X   X   X   X X               XX
X   X X XXX XXX XXX XXXX               XXXX XXX XXX XXX X X   X
XXX XXX XX   X   X   X X X   X   X   X X X   X   X   XX XXX XXX
X X X   X XXXX   XXXXX XXX XXX   XXX XXX XXXXX   XXXX X   X X X
  XXXXX   XX       X X   X X X   X X X   X X       XX   XXXXX
X X   X X X XXX XXXX   XXXXX       XXXXX   XXXX XXX X X X   X X
XXXX XX XXX XX   X X X X   X X   X X   X X X X   XX XXX XX XXXX
X       X   X XXXX XXX XX XXXX   XXXX XX XXX XXXX X   X       X
              XX                               XX
X       X   X X XXX XXX XXX XXX XXX XXX XXX XXX X X   X       X
XXXX XX XXX XXX XX   X   X   X   X   X   X   XX XXX XXX XX XXXX
X X   X X X X   X XXXX   XXXXX   XXXXX   XXXX X   X X X X   X X
  XXXXX   XXXXX   XX       X X   X X       XX   XXXXX   XXXXX
X X X   X X   X X X XXX XXXX       XXXX XXX X X X   X X   X X X
XXX XXX XXXX XX XXX XX   X X X   X X X   XX XXX XX XXXX XXX XXX
X   X X X       X   X XXXX XXX   XXX XXXX X   X       X X X   X
      XXXXX XXX       XX               XX       XXX XXXXX
X   X X   X X X X   X X XXX XXX XXX XXX X X   X X X X   X X   X
XXX XXXX XXXX   XXX XXX XX   X   X   XX XXX XXX   XXXX XXXX XXX
X X X       X X X X X   X XXXX   XXXX X   X X X X X       X X X
  XXXXX   XXXXX   XXXXX   XX       XX   XXXXX   XXXXX   XXXXX
X X   X   X   X X X   X X X XXX XXX X X X   X X X   X   X   X X
XXXX XXX XXX XX XXXX XX XXX XX   XX XXX XX XXXX XX XXX XXX XXXX
X               X       X   X XXX X   X       X               X
                              XXX
X               X       X   X XXX X   X       X               X
XXXX XXX XXX XX XXXX XX XXX XX   XX XXX XX XXXX XX XXX XXX XXXX
X X   X   X   X X X   X X X XXX XXX X X X   X X X   X   X   X X
  XXXXX   XXXXX   XXXXX   XX       XX   XXXXX   XXXXX   XXXXX
X X X       X X X X X   X XXXX   XXXX X   X X X X X       X X X
XXX XXXX XXXX   XXX XXX XX   X   X   XX XXX XXX   XXXX XXXX XXX
X   X X   X X X X   X X XXX XXX XXX XXX X X   X X X X   X X   X
      XXXXX XXX       XX               XX       XXX XXXXX
X   X X X       X   X XXXX XXX   XXX XXXX X   X       X X X   X
XXX XXX XXXX XX XXX XX   X X X   X X X   XX XXX XX XXXX XXX XXX
X X X   X X   X X X XXX XXXX       XXXX XXX X X X   X X   X X X
  XXXXX   XXXXX   XX       X X   X X       XX   XXXXX   XXXXX
X X   X X X X   X XXXX   XXXXX   XXXXX   XXXX X   X X X X   X X
XXXX XX XXX XXX XX   X   X   X   X   X   X   XX XXX XXX XX XXXX
X       X   X X XXX XXX XXX XXX XXX XXX XXX XXX X X   X       X
              XX                               XX
X       X   X XXXX XXX XX XXXX   XXXX XX XXX XXXX X   X       X
XXXX XX XXX XX   X X X X   X X   X X   X X X X   XX XXX XX XXXX
X X   X X X XXX XXXX   XXXXX       XXXXX   XXXX XXX X X X   X X
  XXXXX   XX       X X   X X X   X X X   X X       XX   XXXXX
X X X   X XXXX   XXXXX XXX XXX   XXX XXX XXXXX   XXXX X   X X X
XXX XXX XX   X   X   X X X   X   X   X X X   X   X   XX XXX XXX
X   X X XXX XXX XXX XXXX               XXXX XXX XXX XXX X X   X
      XX               X X   X   X   X X               XX
X   X XXXX XXX   XXX XXXXX XXX   XXX XXXXX XXX   XXX XXXX X   X
XXX XX   X X X   X X X   X X X   X X X   X X X   X X X   XX XXX
X X XXX XXXX       XXXX XXXX       XXXX XXXX       XXXX XXX X X
  XX       X X   X X       X X   X X       X X   X X       XX
X XXXX   XXXXX   XXXXX   XXXXX   XXXXX   XXXXX   XXXXX   XXXX X
XX   X   X   X   X   X   X   X   X   X   X   X   X   X   X   XX
XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX XXX
TIO link, and a more square spaced-out version.

How it's made

You start with a initial crystal (cell) at the center. Then, a new crystal is formed simultaneously at each empty space that touches exactly one existing crystal, looking at the 8 cells orthogonally or diagonally adjacent to it. Crystals remain indefinitely. Here is the snowflake after 3 steps, marking the crystals added at each step.

333 333
32   23
3 111 3
  101
3 111 3
32   23
333 333
We continue this for 31 steps, making a 63-by-63 snowflake with 1833 crystals.

This process is the Life-like (totalistic) cellular automaton B1/S012345678, also known as H-trees or Christmas Life.

Output

Output or print in any 2D array format with two distinct entries for crystal and empty space, or anything that displays as such. The grid must by exactly 63 by 63, that is having no wasted margin. It's fine to have trailing spaces for non-crystals or jagged arrays truncated to the last crystal in each row. A trailing newline is also OK.

Bit representations are not valid unless they display with two distinct symbols for the bits by default.

I also posted this challenge on Anarchy Golf. It requires a strict output format of the ASCII art above of X's and spaces.

"""

import numpy as np
from scipy.signal import convolve2d

"""

ported from @xnor solution

Use convolution to grow the array. The convolution kernel used is:

[[1, 1, 1]
 [1, 9, 1]
 [1, 1, 1]]

and the criteria for living cell is:

c >= 9 or c==1
aka when the cell is already living or when there is exactly 1 neighbor.

"""

def snowflake(n):
    A = np.array([[1]])
    K = np.array([[1, 1, 1], [1, 9, 1], [1, 1, 1]])
    for _ in range(n):
        A = convolve2d(A, K)
        A = (A > 8) + (A == 1)
    return A

def output(A):
    for y in range(len(A)):
        for x in range(len(A[y])):
            if A[y][x] != 0:
                print('X', end='')
            else:
                print(' ', end='')
        print()

def main():
    output(snowflake(31))

main()
