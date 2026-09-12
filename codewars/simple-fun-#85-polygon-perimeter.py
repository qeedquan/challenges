#!/usr/bin/env python3

"""

Task
You have a rectangular white board with some black cells. The black cells create a connected black figure, i.e. it is possible to get from any black cell to any other one through connected adjacent (sharing a common side) black cells.

Find the perimeter of the black figure assuming that a single cell has unit length.

Example
For

matrix = [[false, true,  true ],
          [true,  true,  false],
          [true,  false, false]]```
the output should be `12`.

 ![](https://codefightsuserpics.s3.amazonaws.com/tasks/polygonPerimeter/img/example1.png?_tm=1474901184061)

 For
matrix = [[true, true, true], [true, false, true], [true, true, true]]``` the output should be 16.

https://codefightsuserpics.s3.amazonaws.com/tasks/polygonPerimeter/img/example2.png?_tm=1474901184209

Input/Output
[input] 2D boolean array matrix

A matrix of booleans representing the rectangular board where true means a black cell and false means a white one.

Constraints:

2 ≤ matrix.length ≤ 10,

2 ≤ matrix[0].length ≤ 10.

[output] an integer

"""

def at(m, x, y, w, h):
    if x < 0 or x >= w or y < 0 or y >= h or not m[y][x]:
        return 0

    v = 0
    if y - 1 < 0 or not m[y - 1][x]:
        v += 1
    if y + 1 >= h or not m[y + 1][x]:
        v += 1
    if x - 1 < 0 or not m[y][x - 1]:
        v += 1
    if x + 1 >= w or not m[y][x + 1]:
        v += 1
    return v

def perimeter(m):
    if len(m) == 0 or len(m[0]) == 0:
        return 0

    p = 0
    w = len(m[0])
    h = len(m)
    for y in range(h):
        for x in range(w):
            p += at(m, x, y, w, h)
    return p

def main():
    assert(perimeter([[0, 1, 1], [1, 1, 0], [1, 0, 0]]) == 12)
    assert(perimeter([[1, 1, 1, 1, 1], [1, 1, 1, 1, 1]]) == 14)
    assert(perimeter([[0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]) == 0)

main()
