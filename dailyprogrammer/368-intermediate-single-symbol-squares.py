#!/usr/bin/env python3

"""

Description
Given a grid size N, find an NxN layout of X's and O's such that no axis-aligned square (2x2 or larger) within the grid has the same symbol at each of its four corners. That is, if four cells of the grid form a square, they must not be either all X's or all O's.

For instance, given N = 5, the following would not be a valid output:

O O O X X
X X O O O
X O X O X
O X O O X
X O X X O
because there's a 3x3 square whose four corners are all X's:

. . . . .
. . . . .
X . X . .
. . . . .
X . X . .
Example input
5
Example output
O O O X X
X X O O O
O O X O X
O X O O X
X O X X O
Run time
To qualify as a solution to this challenge, you must actually run your program through to completion for N = 6. It's not enough to write a program that will eventually complete. Post your solution along with your code.

(If you find this too hard, try to at least complete N = 4.)

Optional Bonus 1
Find a solution for N = 10.

Optional Bonus 2
(Let's consider this to be this week's Hard problem.)

For N = 32, generate an output with as few single-symbol squares as possible. (I have no idea what's a good score here, or if 0 is even possible.)

Here's some Python that will tell you the number of single-symbol squares for a grid formatted like the example:

import sys
grid = [line.strip().split() for line in sys.stdin if line.strip()]
N = len(grid)
assert all(len(line) == N for line in grid)
# For the square with upper-left corner (x, y) with side length d+1,
# are the four corners of the square the same?
def square_is_single(x, y, d):
    corners = [grid[x+a][y+b] for a in (0, d) for b in (0, d)]
    return len(set(corners)) == 1
def squares():
    for x in range(N):
        for y in range(N):
            for d in range(1, N):
                if x + d < N and y + d < N:
                    yield x, y, d
print(sum(square_is_single(x, y, d) for x, y, d in squares()))

"""

import numpy as np

def subgrids(grid):
    l = len(grid)
    for step in range(1, l):
        for i in range(0, l - step):
            for j in range(0, l - step):
                yield [(i, j), (i, j + step), (i + step, j), (i + step, j + step)]

def is_valid(grid):
    for c in subgrids(grid):
        symbols = [grid[i][j] for (i, j) in c]
        if all(x == 1 for x in symbols) or all(y == 0 for y in symbols):
            return False
    return True

"""

@zqvt - randomly generate grids until it satisfies the constraints, works well up until size >= 7

Tight bound on N on which there are solutions:
https://www-lmpa.univ-littoral.fr/publications/articles/lmpa404.pdf

"""

def solve(size):
    grid = np.random.randint(2, size=(size, size))
    while not is_valid(grid):
        grid = np.random.randint(2, size=(size, size))
    return grid

def main():
    for i in range(2, 7):
        print(i)
        print(solve(i))
        print()

main()
