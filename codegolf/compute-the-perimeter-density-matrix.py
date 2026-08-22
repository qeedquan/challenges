#!/usr/bin/env python3

"""

Introduction
The perimeter density matrix is an infinite binary matrix M defined as follows. Consider a (1-based) index (x, y), and denote by M[x, y] the rectangular sub-matrix spanned by the corner (1, 1) and (x, y). Suppose that all values of M[x, y] except Mx, y, the value at index (x, y), have already been determined. Then the value Mx, y is whichever of 0 or 1 that puts the average value of M[x, y] closer to 1 / (x + y). In case of a tie, choose Mx, y = 1.

This is the sub-matrix M[20, 20] with zeros replaced by dots for clarity:

1 . . . . . . . . . . . . . . . . . . .
. . . . . 1 . . . . . . . . . . . . . .
. . 1 . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . 1 . . . . . . . . . . . . . . .
. 1 . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . 1 . .
. . . . . . . . . . . . . . 1 . . . . .
. . . . . . . . . . . . 1 . . . . . . .
. . . . . . . . . . 1 . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . 1 . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . 1 . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . 1 . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . .

For example, we have M1, 1 = 1 at the upper left corner, since 1 / (1 + 1) = ½, and the average of the 1 × 1 sub-matrix M[1, 1] is either 0 or 1; that's a tie, so we choose 1.

Consider then the position (3, 4). We have 1 / (3 + 4) = 1/7, and the average of the sub-matrix M[3, 4] is 1/6 if we choose 0, and 3/12 if we choose 1. The former is closer to 1/7, so we choose M3, 4 = 0.

Here is the sub-matrix M[800, 800] as an image, showing some of its intricate structure.

The task
Given a positive integer N < 1000, output the N × N sub-matrix M[N, N], in any reasonable format. The lowest byte count wins.

"""

def dump(m):
    n = len(m)
    for i in range(n):
        for j in range(n):
            if m[i][j] == 0:
                print('.', end='')
            else:
                print(m[i][j], end='')
        print()
    print()

# ported from @Kade answer
def gen(n):
    m = [n * [0] for x in range(n)] 
    for i in range(1, n+1):  
        for j in range(1, n+1):  
            p = 1.0 * i * j  
            f = sum(sum(m[l][:j]) for l in range(i)) 
            d = 1.0 / (i + j)  
            m[i - 1][j - 1] = 0**(abs(f/p - d) < abs((f+1)/p - d))
    return m

def main():
    dump(gen(8))
    dump(gen(20))

main()

