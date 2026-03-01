#!/usr/bin/env python3

"""

Description

Given a M×N matrix A. Aij ∈ {0, 1} (0 ≤ i < M, 0 ≤ j < N), could you find some rows that let every cloumn contains and only contains one 1.

Input

There are multiple cases ended by EOF. Test case up to 500.The first line of input is M, N (M ≤ 16, N ≤ 300). The next M lines every line contains N integers separated by space.

Output

For each test case, if you could find it output "Yes, I found it", otherwise output "It is impossible" per line.

Sample Input

3 3
0 1 0
0 0 1
1 0 0
4 4
0 0 0 1
1 0 0 0
1 1 0 1
0 1 0 0

Sample Output

Yes, I found it
It is impossible
Source

POJ Monthly Contest - 2009.08.23, MasterLuo

"""

import numpy as np

def find(m):
    if len(m) == 0 or len(m[0]) == 0:
        return "It is impossible"

    s = {}
    r, c = len(m), len(m[0])
    for i in range(r):
        for j in range(c):
            if m[i][j] == 1:
                if j in s:
                    return "It is impossible"
                s[j] = True
    return "Yes, I found it"

def main():
    assert(find([[0, 1, 0], [0, 0, 1], [1, 0, 0]]) == "Yes, I found it")
    assert(find([[0, 0, 0, 1], [1, 0, 0, 0], [1, 1, 0, 1], [0, 1, 0, 0]]) == "It is impossible")
    for i in range(1, 100):
        assert(find(np.eye(i)) == "Yes, I found it")

main()
