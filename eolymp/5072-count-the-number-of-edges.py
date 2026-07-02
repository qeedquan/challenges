#!/usr/bin/env python3

"""

The directed graph is given with an adjacency matrix. Find the number of edges in a graph.

Input
The first line contains the number of vertices in the graph n(1≤n≤100).
Then follow n lines with n numbers each, equal to 0 or 1 — the adjacency matrix of the graph.

Output
Print the number of edges in a graph.

https://static.e-olymp.com/content/f6/f6252c9ff7784dea1613accaf4a7f16ea7bbd4cb.gif

Examples

Input #1
3
0 1 1
1 0 1
0 1 1

Answer #1
6

"""

def solve(m):
    r = 0
    for i in range(len(m)):
        for j in range(len(m[i])):
            r += m[i][j]
    return r

def main():
    assert(solve([[0, 1, 1], [1, 0, 1], [0, 1, 1]]) == 6)

main()
