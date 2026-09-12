#!/usr/bin/env python3

"""

You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.

https://assets.leetcode.com/uploads/2021/07/15/lc-domino.jpg

Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile.
Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

Example 1:
https://assets.leetcode.com/uploads/2021/07/15/lc-domino1.jpg
Input: n = 3
Output: 5
Explanation: The five different ways are shown above.

Example 2:
Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 1000

"""

import numpy as np

# https://oeis.org/A052980
def tilings(n):
    if n < 0:
        return 0

    mod = 1_000_000_007
    T = np.array([[1, 0, 0, 1], [1, 0, 1, 0], [1, 1, 0, 0], [1, 1, 1, 0]], dtype=object)
    p = np.array([1, 0, 0, 0], dtype=object)
    r = np.dot(p, np.linalg.matrix_power(T, n))
    return r[0] % mod

def main():
    tab = [
        1,
        1,
        2,
        5,
        11,
        24,
        53,
        117,
        258,
        569,
        1255,
        2768,
        6105,
        13465,
        29698,
        65501,
        144467,
        318632,
        702765,
        1549997,
        3418626,
        7540017,
        16630031,
        36678688,
        80897393,
        178424817,
        393528322,
        867954037,
        1914332891,
        4222194104,
        9312342245,
        20539017381,
        45300228866,
    ]
    
    for i in range(len(tab)):
        assert(tilings(i) == tab[i] % 1_000_000_007)

main()

