#!/usr/bin/env python3

"""

You are given an n by n ( square ) grid of characters, for example:

[['m', 'y', 'e'],
 ['x', 'a', 'm'],
 ['p', 'l', 'e']]

You are also given a list of integers as input, for example:

[1, 3, 5, 8]

You have to find the characters in these indexes of the grid if you think of the indexes as:

[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]

Remember that the indexes start from one and not zero.

Then you output a string like this:

"meal"

All inputs will be valid.

"""

def gridindex(grid, indices):
    result = ""
    size = len(grid)
    for index in indices:
        y = (index - 1) // size
        x = (index - 1) % size
        result += grid[y][x]
    return result

def main():
    assert(gridindex([['m', 'y', 'e'], ['x', 'a', 'm'], ['p', 'l', 'e']], [1, 3, 5, 8]) == "meal")

main()
