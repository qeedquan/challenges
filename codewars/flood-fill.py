#!/usr/bin/env python3

"""

Task
Given a 2-dimensional grid and a zero-based (x,y) coordinate, flood-fill the area on the grid containing that coordinate with the given value. Two squares in the grid belong to the same area if they contain the same value and are adjacent either horizontally or vertically, but not diagonally.

See: https://en.wikipedia.org/wiki/Flood_fill

Grid
The grid is represented as a 2-dimensional rectangular array.

Example
A flood fill with 4 at the point (0, 1) of the following array would look like this:

   [[1, 2, 3],     [[1, 4, 3],
    [1, 2, 2],  ->  [1, 4, 4],
    [2, 3, 2]]      [2, 3, 4]]

Note: the input array can be mutated in place.

Hint
One of the test cases is quite large so make sure your solution is as efficient as possible!

"""

def floodfill(matrix, y, x, value):
    if not matrix or not matrix[0]:
        return matrix

    height, width = len(matrix), len(matrix[0])
    if x < 0 or x >= width or y < 0 or y >= height:
        return matrix

    old = matrix[y][x]
    if old == value:
        return matrix
    matrix[y][x] = value
    
    stack = [(y, x)]
    while len(stack) > 0:
        cy, cx = stack.pop()
        for ny, nx in ((cy-1, cx), (cy+1, cx), (cy, cx-1), (cy, cx+1)):
             if 0 <= ny and ny < height and 0 <= nx and nx < width and matrix[ny][nx] == old:
                 matrix[ny][nx] = value
                 stack.append((ny, nx))
    return matrix

def main():
    assert(floodfill([[1, 2, 3], [1, 2, 2], [2, 3, 2]], 0, 1, 4) == [[1, 4, 3], [1, 4, 4], [2, 3, 4]])

main()
