#!/usr/bin/env python3

"""

In this kata, we simply want to expand a matrix with some padding. For simplicity, we will take a square nxn matrix and expand it to a 2nx2n matrix. By expand I mean:

.------ n          .------------------2n
|       |          |  fill            |
|       |     ===> |                  |
|       |          |    .--------n    |
n------ n          |    |        |    |
                   |    |        |    |
                   |    |        |    |
                   |    n--------n    |
                   |                  |
                   2n-----------------2n

in python the function signature is def expand(matrix, fill) matrix is the nxn matrix that you need to expand and fill is the value you should use for padding

Oh and by the way, n is divisible by 2 and n >= 2

Finally, I give you print_mat(m) which will print matrix m for you in the console.

"""

def expand(maze, fill):
    n = len(maze)
    h = n // 2
    res = [[fill]*(2*n) for _ in range(2*n)]
    for i, row in enumerate(maze):
         res[h + i][h:h + n] = row
    return res

def dump(maze):
    for row in maze:
        print(row)

dump(expand([[1, 2], [3, 4]], 0))

