#!/usr/bin/env python3

"""

Goal
The goal of this challenge is to produce a function of n which computes the number of ways to partition the n X 1 grid into triangles where all of the vertices of the triangles are on grid points.

Example
For example, there are 14 ways to partition the 2 x 1 grid, so f(2) = 14 via the following partitions

https://i.stack.imgur.com/YLap3.png

where the partitions have 2, 2, 2, 2, 4, and 2 distinct orientations respectively.

Scoring
This is code-golf, so shortest code wins.

"""

"""

https://oeis.org/A051708

@flawr

After a drawing and programming a lot of examples, it occured to me that this is the same as the problem of the rooks:

On a (n+1)×(n+1) chessboard, how many ways are there for a rook to go from (0,0) to (n,n) by just moving right +(1,0) or up +(0,1)?

Basically you have the top and the bottom line of the 1×n grid.
Now you have to fill in the non-horizontal line.
Each triangle must have two non-horizontal lines.
Whether one of its sides is part of the top or the bottom line corresponds to the direction and length you'd go in the rooks problem.
This is OEIS A051708. As an illustration of this correspondence consider following examples.
Here the top line corresponds to up-moves, while the bottom line corresponds to right-moves.
https://i.stack.imgur.com/fUFRx.png

"""

def partitions(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if n == 1:
        return 2
    return ((10*n-6)*partitions(n-1) - 9*(n-2)*partitions(n-2)) // n

def main():
    tab = [1, 2, 14, 106, 838, 6802, 56190, 470010, 3968310, 33747490, 288654574, 2480593546, 21400729382, 185239360178, 1607913963614, 13991107041306, 122002082809110, 1065855419418690, 9327252391907790, 81744134786314410, 717367363052796678, 6303080714967178962]

    for i in range(len(tab)):
        assert(partitions(i) == tab[i])

main()
