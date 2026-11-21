#!/usr/bin/env python3

"""

The King of Ruritania seeks for a way to reduce funding on road maintenance in his kingdom.

Kingdom of Ruritania consists of several cities connected by several roads. Each road connects only two cities, and for any pair of cities there exists at least one way between them (the way could be a chain of several roads).

The King just have come to the bright idea - if there is any cycle (or loop) in the road network, then between some cities there exist more than one way (for example between two cities in this cycle you can travel either clockwise or counterclockwise) - so, obviously, at least one road could be removed and cities will nevertheless remain connected.

Your task is to help the King in finding whether the road map contains cycles or not.

Input data contains the amount of test-cases in the first line.
Next lines contain one road map each - it starts with the number of roads in this map followed by road descriptions in form A-B meaning that the road connects cities A and B (all places are named with a single capital letter).
Answer should have 0 for maps with no cycles and 1 for maps which could be "optimized". As usual, separate values with spaces.

Note: there will be no roads connecting the city to itself.

Example:

input data:
3
3 A-B B-C B-D
4 A-B B-D D-C A-C
4 A-B B-C C-A A-D

answer:
0 1 1

"""

import numpy as np

def make_adjacency_matrix(roads):
    ids = {}
    paths = []
    for road in roads.split(' '):
        edges = road.split('-')
        if len(edges) != 2:
            continue
        for edge in edges:
            if edge not in ids:
                ids[edge] = len(ids)
        paths.append((ids[edges[0]], ids[edges[1]]))
    
    n = len(ids)
    A = np.zeros((n, n))
    for u, v in paths:
        A[u][v] = 1
        A[v][u] = 1
    return A

def make_degree_matrix(A):
    n = len(A)
    D = np.zeros((n, n))
    for i in range(n):
        for j in range(n):
            if i == j and A[i][j] != 0:
                D[i][i] += 2
            elif A[i][j] != 0:
                D[i][i] += 1
    return D

"""

https://en.wikipedia.org/wiki/Laplacian_matrix
https://en.wikipedia.org/wiki/Degree_matrix
https://stackoverflow.com/questions/16436165/detecting-cycles-in-an-adjacency-matrix
https://math.stackexchange.com/questions/910931/determine-cycle-from-adjacency-matrix/911040#911040

The adjacency graph generated from the problem is an undirected graph.
Use the Laplacian matrix and the following fact to determine if it has a cycle:

G is acyclic if and only if 0.5*trace(L)=rank(L). Equivalently, G has a cycle if and only if 0.5*trace(L) >= rank(L)+1.

Note:
For directed graphs, the degree matrix can be split into an in-degree/out-degree matrix, more than one degree matrix is possible,

"""

def solve(roads):
    A = make_adjacency_matrix(roads)
    D = make_degree_matrix(A)
    L = D - A
    return np.trace(L) >= 2*(np.linalg.matrix_rank(L) + 1)

def main():
    assert(solve("A-B B-C B-D") == 0)
    assert(solve("A-B B-D D-C A-C") == 1)
    assert(solve("A-B B-C C-A A-D") == 1)

main()
