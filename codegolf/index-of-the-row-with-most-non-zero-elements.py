#!/usr/bin/env python3

"""

This is a simple one: Take a matrix of integers as input, and output the index of the row with the most non-zero elements. You may assume that there will only be one row with the most non-zero elements.

Test cases:
These are 1-indexed, you may choose if you want 0 or 1-indexed.

1
0
row = 1
---
0  -1
0   0
row = 1
---
1   1   0   0   0
0   0   5   0   0
2   3   0   0   0
0   5   6   2   2
row = 4
---
0   4   1   0
0   0  -6   0
0   1   4  -3
2   0   0   8
0   0   0   0
row = 3

"""

def nonzeros(m):
    r = 0
    for i in range(len(m)):
        c = 0
        for j in range(len(m[i])):
            if m[i][j] != 0:
                c += 1
        r = max(r, c)
    return r

def main():
    assert(nonzeros([[1], [0]]) == 1)
    assert(nonzeros([[0, -1], [0, 0]]) == 1)
    assert(nonzeros([[1, 1, 0, 0, 0], [0, 0, 5, 0, 0], [2, 3, 0, 0, 0], [0, 5, 6, 2, 2]]) == 4)
    assert(nonzeros([[0, 4, 1, 0], [0, 0, -6, 0], [0, 1, 4, -3], [2, 0, 0, 8], [0, 0, 0, 0]]) == 3)

main()
