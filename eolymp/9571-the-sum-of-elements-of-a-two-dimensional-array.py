#!/usr/bin/env python3

"""

Given a two-dimensional array of size n×m. Find the sum of its elements.

Input
The first line of the input contains two numbers n and m, the number of rows and the number of columns, respectively.

The following n lines each contain m numbers - the elements of the array.

Output
Output a single number, the sum of the elements of the array.

Examples

Input #1
4 5
1 3 2 4 5
4 2 7 6 5
9 2 3 5 1
7 8 1 7 2

Answer #1
84

"""

import numpy as np

def solve(m):
    return np.sum(m)

def main():
    assert(solve([[1, 3, 2, 4, 5], [4, 2, 7, 6, 5], [9, 2, 3, 5, 1], [7, 8, 1, 7, 2]]) == 84)

main()
