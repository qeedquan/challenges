#!/usr/bin/env python3

"""

A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

Example:

Input:

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 6

Explanation: Given three people living at (0,0), (0,4), and (2,2):
             The point (0,2) is an ideal meeting point, as the total travel distance
             of 2+2+2=6 is minimal. So return 6.

"""

# https://www.geeksforgeeks.org/best-meeting-point-2d-binary-array/
def minimize(g):
    m = len(g)
    n = len(g[0])
    
    I = [i for i in range(m) for j in range(n) if g[i][j]]
    J = [j for j in range(n) for i in range(m) if g[i][j]]

    return count(I) + count(J)

def count(l):
    r = 0
    i = 0
    j = len(l) - 1
    while i < j:
        r += l[j] - l[i]
        i += 1
        j -= 1
    return r

def main():
    assert(minimize([[1, 0, 0, 0, 1], [0, 0, 0, 0, 0], [0, 0, 1, 0, 0]]) == 6)
    assert(minimize([[1, 0, 1, 0, 1], [0, 1, 0, 0, 0], [0, 1, 1, 0, 0]]) == 11)

main()
