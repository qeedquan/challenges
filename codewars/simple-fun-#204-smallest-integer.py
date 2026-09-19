#!/usr/bin/env python3

"""

Task
You're given a two-dimensional array of integers matrix. Your task is to determine the smallest non-negative integer that is not present in this array.

Input/Output
[input] 2D integer array matrix

A non-empty rectangular matrix.

1 ≤ matrix.length ≤ 10

1 ≤ matrix[0].length ≤ 10

[output] an integer

The smallest non-negative integer that is not present in matrix.

Example
For

  matrix = [  [0, 2],  [5, 1]] the result should be 3

0,1,2,(3)...5

"""

def ffs(x):
    return (x & -x).bit_length() - 1

def smallest_integer(m):
    b = 0
    for i in range(len(m)):
        for j in range(len(m[i])):
            b |= 1 << m[i][j]
    return ffs(~b)

def main():
    assert(smallest_integer([[0, 2],  [5, 1]]) == 3)
    assert(smallest_integer([[1, 2, 3],  [4, 5, 6], [7, 10, 9]]) == 0)
    assert(smallest_integer([[0, 1, 2],  [3, 4, 5], [6, 10, 7]]) == 8)

main()
