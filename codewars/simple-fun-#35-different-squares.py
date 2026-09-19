#!/usr/bin/env python3

"""

Task
Given a rectangular matrix containing only digits, calculate the number of different 2 × 2 squares in it.

Example
For

matrix = [[1, 2, 1],
          [2, 2, 2],
          [2, 2, 2],
          [1, 2, 3],
          [2, 2, 1]]

the output should be 6.

Here are all 6 different 2 × 2 squares:

1 2
2 2

2 1
2 2

2 2
2 2

2 2
1 2

2 2
2 3

2 3
2 1

Input/Output
[input] 2D integer array matrix

Constraints:

1 ≤ matrix.length ≤ 100,

1 ≤ matrix[i].length ≤ 100,

0 ≤ matrix[i][j] ≤ 9.

[output] an integer

The number of different 2 × 2 squares in matrix.

"""

def different_squares(matrix):
    seen = {}
    for i in range(len(matrix) - 1):
        for j in range(len(matrix[i]) - 1):
            key = (matrix[i][j], matrix[i][j + 1], matrix[i + 1][j], matrix[i + 1][j + 1])
            seen[key] = True
    return len(seen)

def main():
    assert(different_squares([[1, 2, 1], [2, 2, 2], [2, 2, 2], [1, 2, 3], [2, 2, 1]]) == 6)
    assert(different_squares([[9, 9, 9, 9, 9], [9, 9, 9, 9, 9], [9, 9, 9, 9, 9], [9, 9, 9, 9, 9], [9, 9, 9, 9, 9], [9, 9, 9, 9, 9]]) == 1)
    assert(different_squares([[3]]) == 0)
    assert(different_squares([[3, 4, 5, 6, 7, 8, 9]]) == 0)
    assert(different_squares([[3], [4], [5], [6], [7], [8], [7]]) == 0)
    assert(different_squares([[2, 5, 3, 4, 3, 1, 3, 2], [4, 5, 4, 1, 2, 4, 1, 3], [1, 1, 2, 1, 4, 1, 1, 5], [1, 3, 4, 2, 3, 4, 2, 4], [1, 5, 5, 2, 1, 3, 1, 1], [1, 2, 3, 3, 5, 1, 2, 4], [3, 1, 4, 4, 4, 1, 5, 5], [5, 1, 3, 3, 1, 5, 3, 5], [5, 4, 4, 3, 5, 4, 4, 4]]) == 54)

main()
