#!/usr/bin/env python3

"""

The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagram:

A chess knight can move as indicated in the chess diagram below:
https://assets.leetcode.com/uploads/2020/08/18/chess.jpg

We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).
https://assets.leetcode.com/uploads/2020/08/18/phone.jpg

Given an integer n, return how many distinct phone numbers of length n we can dial.
https://assets.leetcode.com/uploads/2020/08/18/phone.jpg

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 10^9 + 7.

Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.

Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]

Example 3:

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.

Constraints:

1 <= n <= 5000

"""

import numpy as np

def knight_dialer(n):
    if n < 1:
        return 0

    T = np.array([
        [0, 0, 0, 0, 1, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
        [0, 0, 0, 0, 1, 0, 0, 0, 1, 0],
        [1, 0, 0, 1, 0, 0, 0, 0, 0, 1],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 1, 0, 0, 0, 1, 0, 0, 0],
        [0, 1, 0, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 1, 0, 0, 0, 0, 0],
    ], dtype=object)
    
    T = np.linalg.matrix_power(T, n - 1)
    return sum(map(sum, T)) % 1_000_000_007

# https://oeis.org/A327692
def knight_dialer_dp(n):
    if n < 1:
        return 0

    d = ((4, 6), (6, 8), (7, 9), (4, 8), (3, 9, 0), (), (1, 7, 0), (2, 6), (1, 3), (2, 4))
    m = [[0] * 10 for _ in range(n)]
    m[0] = [1] * 10
    for i in range(1, n):
        for j in range(10):
            for k in d[j]:
                m[i][k] += m[i-1][j]
    return sum(m[-1]) % 1_000_000_007

def main():
    tab = [
        10, 20, 46, 104, 240, 544, 1256, 2848, 6576, 14912, 34432, 78080, 180288,
        408832, 944000, 2140672, 4942848, 11208704, 25881088, 58689536, 135515136,
        307302400, 709566464, 1609056256, 3715338240, 8425127936, 19453763584
    ]

    assert(knight_dialer(1) == 10)
    assert(knight_dialer(2) == 20)
    assert(knight_dialer(3131) == 136006598)
    for i in range(len(tab)):
        assert(knight_dialer(i + 1) == tab[i] % 1_000_000_007)

    for i in range(1000):
        assert(knight_dialer(i) == knight_dialer_dp(i))

main()

