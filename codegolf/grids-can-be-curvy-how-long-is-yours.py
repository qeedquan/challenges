#!/usr/bin/env python3

"""

Consider depicting a simple, open, two-dimensional curve on a W wide by H high grid of text where X represents part of the curve and . represents empty space and no other characters are used.

Every grid space has 8 neighboring grid spaces, its Moore neighborhood. Grid spaces beyond the borders are considered empty.

A grid contains a curve if it has exactly one X OR if it has more than one X where:

Exactly two Xs have only one neighboring X. These are the curve's endpoints.
Every X besides the endpoints neighbors exactly two Xs. These form the bulk of the curve.
For example, this grid where W = 9 and H = 4 contains a curve:

....X....
.X.X.X.X.
X..X..X.X
.XX.....X
Likewise, these grids (W = 4, H = 3) have curves:

....  .X..  ....  ....  .X.X
....  X..X  ..X.  XX..  X.X.
..X.  .XX.  .X..  ....  ....
These grids, however, do not contain a curve:

....  .XX.  ...X  XX..  ....  X.X.
....  X..X  ..XX  XX..  .X.X  .X..
....  .XX.  .X..  ....  ...X  X.X.
We can find the length of a curve by summing the distances between all neighboring pairs of Xs:

The distance between two orthogonally neighboring Xs is 1 unit.

XX
X
X
The distance between two diagonally neighboring Xs is √2 units.

X.
.X
.X
X.
For example, the length of the curve in the grid

XXX.
...X
..X.
can be visualized as

https://i.sstatic.net/fBmek.png
so we can see it is 1 + 1 + √2 + √2 = 4.828427...

The length of a curve with only one X is zero.

When a grid does not form a curve its length is not well defined.

Challenge
Given a grid of text of Xs and .s, output the length of the curve it contains, or else output something such as -1 or Null to indicate the grid has no curve.

For input you may use other characters than X and . if desired, and H and W may be taken as input if needed. Input as a nested list or matrix filled with 1s and 0s instead of a string is also fine.

You may output a float for the curve length or alternatively two integers A and B where length = A + B*√2.

The shortest code in bytes wins.

Test Cases
XXX.
...X
..X.
2 + 2*√2 = 4.828427...

....X....
.X.X.X.X.
X..X..X.X
.XX.....X
3 + 8*√2 = 14.313708...

....
....
..X.
0 + 0*√2 = 0

.X..
X..X
.XX.
1 + 3*√2 = 5.242640...

....
..X.
.X..
0 + 1*√2 = 1.414213...

....
XX..
....
1 + 0*√2 = 1

.X.X
X.X.
....
0 + 3*√2 = 4.242640...

....
....
....
....
-1

.XX.
X..X
.XX.
-1

...X
..XX
.X..
-1

....
.X.X
...X
-1

X.X.
.X..
X.X.
-1

"""

"""

Ported from @nile solution

How it works:

d,R,C are 1. a list of lists with 1 as curve and 0 as background, 2. row and column count
Insert a row of 0's before and after and a column of 0's before and after d so we don't have to worry about the edge of the 2d array
For every 1 in the 2d array, scan the neighbourhood for 1's and add (1,0) to a list if the relation is diagonal, else add (0,1)
Sum all tuples, so that (n,m) represents the number of diagonal and non-diagonal neighbours, respectively
Check if the number of relations is exactly the number of 1's minus one; if not, not a curve.
Thanks to @Helka Homba for pointing out a missing case. Thanks to @TuukkaX and @Trelzevir for the golfing tips.

"""
def solve(grid, rows, cols):
    padded = ([[0] * (cols + 2)] + [[0, *row, 0] for row in grid] + [[0] * (cols + 2)])
    directions = []
    for col in range(1, cols + 1):
        for row in range(1, rows + 1):
            if not padded[row][col]:
                continue

            cell_directions = []
            for row_offset in (-1, 0, 1):
                for col_offset in (-1, 0, 1):
                    if not (row_offset or col_offset):
                        continue

                    if not padded[row + row_offset][col + col_offset]:
                        continue

                    direction = ((1, 0) if row_offset * col_offset == 0 else (0, 1))
                    cell_directions.append(direction)

            directions.append(cell_directions)

    all_directions = [
        direction
        for cell in directions
        for direction in cell
    ]

    if all_directions:
        totals = [sum(component)/2 for component in zip(*all_directions)]
    else:
        totals = [0, 0]

    grid_sum = sum(map(sum, padded))
    too_many_ones = sum(len(cell) == 1 for cell in directions) > 2

    if sum(totals) != grid_sum-1 or too_many_ones:
        return -1

    return totals

grid = [[1, 1, 1, 0], [0, 0, 0, 1], [0, 0, 1, 0]]
print(solve(grid, len(grid), len(grid[0])))

grid = [
    [0, 0, 0, 0, 1, 0, 0, 0, 0],
    [0, 1, 0, 1, 0, 1, 0, 1, 0],
    [1, 0, 0, 1, 0, 0, 1, 0, 1],
    [0, 1, 1, 0, 0, 0, 0, 0, 1],
]
print(solve(grid, len(grid), len(grid[0])))

grid = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 1, 0]]
print(solve(grid, len(grid), len(grid[0])))

grid = [[0, 1, 0, 0], [1, 0, 0, 1], [0, 1, 1, 0]]
print(solve(grid, len(grid), len(grid[0])))

grid = [[0, 0, 0, 0], [0, 0, 1, 0], [0, 1, 0, 0]]
print(solve(grid, len(grid), len(grid[0])))

grid = [[0, 0, 0, 0], [1, 1, 0, 0], [0, 0, 0, 0]]
print(solve(grid, len(grid), len(grid[0])))

grid = [[0, 1, 0, 1], [1, 0, 1, 0], [0, 0, 0, 0]]
print(solve(grid, len(grid), len(grid[0])))

grid = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
print(solve(grid, len(grid), len(grid[0])))

grid = [[0, 1, 1, 0], [1, 0, 0, 1], [0, 1, 1, 0]]
print(solve(grid, len(grid), len(grid[0])))

grid = [[0, 0, 0, 1], [0, 0, 1, 1], [0, 1, 0, 0]]
print(solve(grid, len(grid), len(grid[0])))

grid = [[0, 0, 0, 0], [0, 1, 0, 1], [0, 0, 0, 1]]
print(solve(grid, len(grid), len(grid[0])))

grid = [[1, 0, 1], [0, 1, 0], [1, 0, 1]]
print(solve(grid, len(grid), len(grid[0])))
