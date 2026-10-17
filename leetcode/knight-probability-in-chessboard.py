#!/usr/bin/env python3

"""

On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

https://assets.leetcode.com/uploads/2018/10/12/knight.png

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.



Example 1:

Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
Example 2:

Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000


Constraints:

1 <= n <= 25
0 <= k <= 100
0 <= row, column <= n - 1

"""

# https://walkccc.me/LeetCode/problems/0688/
def knight_probability(n, K, r, c):
    dirs = [(1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1), (-2, 1), (-1, 2)]

    dp = [[0] * n for _ in range(n)]
    dp[r][c] = 1

    for _ in range(K):
        nextdp = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                for dx, dy in dirs:
                    x = i + dx
                    y = j + dy
                    if 0 <= x < n and 0 <= y < n:
                        nextdp[i][j] += dp[x][y]
        dp = nextdp

    return sum(map(sum, dp)) / 8**K

def main():
    assert(knight_probability(3, 2, 0, 0) == 0.06250)
    assert(knight_probability(1, 0, 0, 0) == 1)

main()
