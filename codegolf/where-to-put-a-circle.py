#!/usr/bin/env python3

"""

Consider an n×n grid of integers which is part of an infinite grid. The top left coordinate of the n×n grid of integers is (0,0).

The task is to find a circle which when overlaid on the grid gives the largest sum of values inside it. The constraints are:

The circle has its centre at (x,x) for some value x which is not necessarily an integer. Notice that both dimensions have the same value.
The radius of the circle is r and is not necessarily an integer.
The circle must include the point (0,0) within it.
All points outside of the n×n grid contribute zero to the sum.
The center of the circle can be outside the n×n grid provided the other conditions are met.
Here is a picture of a 10×10 grid with two circles overlaid.

The larger circle has its center at (−20,−20).

The two parameters are therefore x and r.
Although there are in principle an infinite number of options, in fact only a finite subset are relevant.

The matrix in this case is:

[[ 3 -1  1  0 -1 -1 -3 -2 -2  2]
 [ 0  0  3  0  0 -1  2  0 -2  3]
 [ 2  0  3 -2  3  1  2  2  1  1]
 [-3  0  1  0  1  2  3  1 -3 -1]
 [-3 -2  1  2  1 -3 -2  2 -2  0]
 [-1 -3 -3  1  3 -2  0  2 -1  1]
 [-2 -2 -1  2 -2  1 -1  1  3 -1]
 [ 1  2 -1  2  0 -2 -1 -1  2  3]
 [-1 -2  3 -1  0  0  3 -3  3 -2]
 [ 0 -3  0 -1 -1  0 -2 -3 -3 -1]]

The winning criterion is worst case time complexity as a function of n. That is using big Oh notation, e.g.  O(n^4).

"""

def CPos(x1, y1, x2, y2):
    return (x1 * x1 - x2 * x2 + y1 * y1 - y2 * y2) / 2 / (x1 - x2 + y1 - y2)

"""

Ported from @l4m2 solution

For each point assume the circle go through it(Base[XY]), then radius decrease from infinity.
Store when the points enter/leave circle, sort it and only consider these step.

"""

def solve(A):
    n = len(A)
    if n == 0:
        return 0
    
    Ret = A[0][0]
    for baseY in range(n):
        for baseX in range(n):
            if baseY == 0 and baseX == 0:
                continue
            dBase = abs(baseX - baseY)
            Sum = 0
            Buf = [[[CPos(baseX, baseY, 0, 0), 1], 0, 0]]
            for y in range(n):
                for x in range(n):
                    d = abs(x - y)
                    if x + y <= baseX + baseY:
                        Sum = Sum + A[y][x]
                        if d > 0 and x + y < baseX + baseY:
                            Buf += [[[CPos(baseX, baseY, x, y), 2], -A[y][x]]]
                    else:
                        if d < 0:
                            Buf += [[[CPos(baseX, baseY, x, y), 0], A[y][x]]]
            Buf = sorted(Buf, key=lambda k: k[0]) # Radix sort
            
            i = 0
            if Ret < Sum:
                Ret = Sum
            while len(Buf[i]) < 3:
                Sum = Sum + Buf[i][1]
                if Buf[i][0] != Buf[i + 1][0]:
                    if Ret < Sum:
                        Ret = Sum
                i = i + 1
    return Ret


print(
    solve(
        [
            [3, -1, 1, 0, -1, -1, -3, -2, -2, 2],
            [0, 0, 3, 0, 0, -1, 2, 0, -2, 3],
            [2, 0, 3, -2, 3, 1, 2, 2, 1, 1],
            [-3, 0, 1, 0, 1, 2, 3, 1, -3, -1],
            [-3, -2, 1, 2, 1, -3, -2, 2, -2, 0],
            [-1, -3, -3, 1, 3, -2, 0, 2, -1, 1],
            [-2, -2, -1, 2, -2, 1, -1, 1, 3, -1],
            [1, 2, -1, 2, 0, -2, -1, -1, 2, 3],
            [-1, -2, 3, -1, 0, 0, 3, -3, 3, -2],
            [0, -3, 0, -1, -1, 0, -2, -3, -3, -1],
        ]
    )
)

