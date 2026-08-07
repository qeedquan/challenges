#!/usr/bin/env python3

"""

You are given two integers n and m which represent the size of a 1-indexed grid.
You are also given an integer k, a 1-indexed integer array source and a 1-indexed integer array dest,
where source and dest are in the form [x, y] representing a cell on the given grid.

You can move through the grid in the following way:

You can go from cell [x1, y1] to cell [x2, y2] if either x1 == x2 or y1 == y2.
Note that you can't move to the cell you are already in e.g. x1 == x2 and y1 == y2.
Return the number of ways you can reach dest from source by moving through the grid exactly k times.

Since the answer may be very large, return it modulo 10^9 + 7.

Example 1:

Input: n = 3, m = 2, k = 2, source = [1,1], dest = [2,2]
Output: 2
Explanation: There are 2 possible sequences of reaching [2,2] from [1,1]:
- [1,1] -> [1,2] -> [2,2]
- [1,1] -> [2,1] -> [2,2]
Example 2:

Input: n = 3, m = 4, k = 3, source = [1,2], dest = [2,3]
Output: 9
Explanation: There are 9 possible sequences of reaching [2,3] from [1,2]:
- [1,2] -> [1,1] -> [1,3] -> [2,3]
- [1,2] -> [1,1] -> [2,1] -> [2,3]
- [1,2] -> [1,3] -> [3,3] -> [2,3]
- [1,2] -> [1,4] -> [1,3] -> [2,3]
- [1,2] -> [1,4] -> [2,4] -> [2,3]
- [1,2] -> [2,2] -> [2,1] -> [2,3]
- [1,2] -> [2,2] -> [2,4] -> [2,3]
- [1,2] -> [3,2] -> [2,2] -> [2,3]
- [1,2] -> [3,2] -> [3,3] -> [2,3]


Constraints:

2 <= n, m <= 10^9
1 <= k <= 10^5
source.length == dest.length == 2
1 <= source[1], dest[1] <= n
1 <= source[2], dest[2] <= m

"""

import numpy as np
from numpy.linalg import matrix_power

def ways(n, m, k, src, dst):
    M = np.array([
        [0, m - 1, n - 1, 0],
        [1, m - 2, 0, n - 1],
        [1, 0, n - 2, m - 1],
        [0, 1, 1, (n - 2) + (m - 2)],
    ])
    
    x = np.array([0, 0, 0, 0])
    if src == dst:
        x[0] = 1
    elif src[0] == dst[0]:
        x[1] = 1
    elif src[1] == dst[1]:
        x[2] = 1
    else:
        x[3] = 1

    r = np.dot(x, matrix_power(M, k))
    return r[0]

def main():
    assert(ways(3, 2, 2, [1, 1], [2, 2]) == 2)
    assert(ways(3, 4, 3, [1, 2], [2, 3]) == 9)

main()

