#!/usr/bin/env python3

"""

Input
A non-empty binary matrix consisting of 3x3 sub-matrices put side by side.

Task
Your task is to identify valid dice patterns (as described below) among the 3x3 sub-matrices. Each valid pattern is worth the value of the corresponding dice. Invalid patterns are worth 0.

Output
The sum of the valid dice values.

Dice patterns
1 - [0 0 0]
    [0 1 0]
    [0 0 0]

2 - [1 0 0] or [0 0 1]
    [0 0 0]    [0 0 0]
    [0 0 1]    [1 0 0]

3 - [1 0 0] or [0 0 1]
    [0 1 0]    [0 1 0]
    [0 0 1]    [1 0 0]

4 - [1 0 1]
    [0 0 0]
    [1 0 1]

5 - [1 0 1]
    [0 1 0]
    [1 0 1]

6 - [1 0 1] or [1 1 1]
    [1 0 1]    [0 0 0]
    [1 0 1]    [1 1 1]

Example
The expected output for the following matrix is 14 because it contains the dice 5, 6 and 3, followed by an invalid pattern (from left to right and from top to bottom).

[1 0 1 1 1 1]
[0 1 0 0 0 0]
[1 0 1 1 1 1]
[1 0 0 0 0 0]
[0 1 0 0 1 0]
[0 0 1 0 1 0]

Rules
Both the width and the height of the matrix are guaranteed to be multiples of 3.
You must ignore sub-matrices that are not properly aligned on the grid (see the 3rd test case). More formally and assuming 0-indexing: the coordinates of the top-left cell of each sub-matrix to be considered are of the form  (3x,3y).
This is code-golf.
Test cases
// 0
[ [ 1,0,0 ],
  [ 0,0,1 ],
  [ 1,0,0 ] ]

// 2
[ [ 0,0,1 ],
  [ 0,0,0 ],
  [ 1,0,0 ] ]

// 0 (0 + 0)
[ [ 0,0,1,0,1,0 ],
  [ 0,0,0,1,0,0 ],
  [ 0,0,1,0,1,0 ] ]

// 9 (3 + 3 + 3)
[ [ 1,0,0,0,0,1,1,0,0 ],
  [ 0,1,0,0,1,0,0,1,0 ],
  [ 0,0,1,1,0,0,0,0,1 ] ]

// 6 (6 + 0)
[ [ 1,0,1 ],
  [ 1,0,1 ],
  [ 1,0,1 ],
  [ 1,0,1 ],
  [ 1,0,0 ],
  [ 1,0,1 ] ]

// 14 (5 + 6 + 3 + 0)
[ [ 1,0,1,1,1,1 ],
  [ 0,1,0,0,0,0 ],
  [ 1,0,1,1,1,1 ],
  [ 1,0,0,0,0,0 ],
  [ 0,1,0,0,1,0 ],
  [ 0,0,1,0,1,0 ] ]

// 16 (1 + 2 + 3 + 4 + 0 + 6)
[ [ 0,0,0,1,0,0,1,0,0 ],
  [ 0,1,0,0,0,0,0,1,0 ],
  [ 0,0,0,0,0,1,0,0,1 ],
  [ 1,0,1,1,1,1,1,0,1 ],
  [ 0,0,0,1,0,1,1,0,1 ],
  [ 1,0,1,1,1,1,1,0,1 ] ]

"""

def mat2dice(m, i, j):
    lut = {16: 1, 257: 2, 68: 2, 273: 3, 84: 3, 325: 4, 341: 5, 455: 6, 365: 6}
    s = "".join(str(e) for c in m[3*i : 3*i + 3] for e in c[3*j : 3*j + 3])
    return lut.get(int(s, 2), 0)

# Ported from @Kateba solution
def solve(m):
    r = 0
    for i in range(len(m)//3):
        for j in range(len(m[i])//3):
            r += mat2dice(m, i, j)
    return r

m1 = [[1, 0, 0], [0, 0, 1], [1, 0, 0]]
m2 = [[0, 0, 1], [0, 0, 0], [1, 0, 0]]
m3 = [[0, 0, 1, 0, 1, 0], [0, 0, 0, 1, 0, 0], [0, 0, 1, 0, 1, 0]]
m4 = [
    [1, 0, 0, 0, 0, 1, 1, 0, 0],
    [0, 1, 0, 0, 1, 0, 0, 1, 0],
    [0, 0, 1, 1, 0, 0, 0, 0, 1],
]
m5 = [[1, 0, 1], [1, 0, 1], [1, 0, 1], [1, 0, 1], [1, 0, 0], [1, 0, 1]]
m6 = [
    [1, 0, 1, 1, 1, 1],
    [0, 1, 0, 0, 0, 0],
    [1, 0, 1, 1, 1, 1],
    [1, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 1, 0],
    [0, 0, 1, 0, 1, 0],
]
m7 = [
    [0, 0, 0, 1, 0, 0, 1, 0, 0],
    [0, 1, 0, 0, 0, 0, 0, 1, 0],
    [0, 0, 0, 0, 0, 1, 0, 0, 1],
    [1, 0, 1, 1, 1, 1, 1, 0, 1],
    [0, 0, 0, 1, 0, 1, 1, 0, 1],
    [1, 0, 1, 1, 1, 1, 1, 0, 1],
]

assert(solve(m1) == 0)
assert(solve(m2) == 2)
assert(solve(m3) == 0)
assert(solve(m4) == 9)
assert(solve(m5) == 6)
assert(solve(m6) == 14)
assert(solve(m7) == 16)
