#!/usr/bin/env python3

"""

Your task is to create a magic square for any positive odd integer N. The magic square contains the integers from 1 to N * N, arranged in an NxN matrix, such that the columns, rows and both main diagonals add up to the same number.

Note: use have to use the Siamese method ( https://en.wikipedia.org/wiki/Siamese_method ) for this task.

Examples:
n = 3
result = [
  [8, 1, 6],
  [3, 5, 7],
  [4, 9, 2]
]


n = 5
result = [
  [17, 24,  1,  8, 15],
  [23,  5,  7, 14, 16],
  [ 4,  6, 13, 20, 22],
  [10, 12, 19, 21,  3],
  [11, 18, 25,  2,  9]
]

"""

def magicsquare(n):
    if n < 1 or n%2 == 0:
        return []

    m = [[0]*n for _ in range(n)]
    r = 0
    c = n//2
    for i in range(1, n*n + 1):
        m[r][c] = i
        
        R = (r - 1 + n) % n
        C = (c + 1) % n
        if m[R][C]:
            r = (r + 1) % n
        else:
            r, c = R, C
    return m

def main():
    assert(magicsquare(1) == [[1]])
    assert(magicsquare(3) == [[8, 1, 6], [3, 5, 7], [4, 9, 2]])
    assert(magicsquare(5) == [[17, 24, 1, 8, 15], [23, 5, 7, 14, 16], [4, 6, 13, 20, 22], [10, 12, 19, 21, 3], [11, 18, 25, 2, 9]])

main()
