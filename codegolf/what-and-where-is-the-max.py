#!/usr/bin/env python3

"""

This small challenge derives from my annoyance at discovering that numpy doesn't have a built in function for it.

Input
An n by m matrix of integers.

Output
The maximum value in the matrix and the 2d coordinates of one of its occurrences. The coordinates should be in the order (row_idx, col_idx).

1-based indexing is allowed too

Examples
Input [[1, 2], [3, 4]]. Output (4, (1, 1))
Input [[-1]]. Output (-1, (0, 0))
Input [[6], [5], [4], [3], [2], [1]]. Output (6, (0, 0))
Input [[1, 2, 3, 4], [0, 2, 5, 3], [-5, -2, 3, 5]]. Output (5, (1, 2))

Note
numpy answers gratefully received too.

"""

import numpy as np

def findmax(m):
    return max((b, a) for a, b in np.ndenumerate(m))

def main():
    assert(findmax([[1, 2], [3, 4]]) == (4, (1, 1)))
    assert(findmax([[-1]]) == (-1, (0, 0)))
    assert(findmax([[6], [5], [4], [3], [2], [1]]) == (6, (0, 0)))
    assert(findmax([[1, 2, 3, 4], [0, 2, 5, 3], [-5, -2, 3, 5]]) == (5, (2, 3)))

main()
