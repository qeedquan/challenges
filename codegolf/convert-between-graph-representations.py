#!/usr/bin/env python3

r"""

Let's say I have this graph:

   1
    \
     \
2     3
 \   /
  \ /
   4

I can represent it in 2 ways:

A list of connected vertices. [[1,3],[2,4],[3,4]]
A boolean matrix which shows where edges are:
c |1 2 3 4
--|-------
1 |0 0 1 0
2 |0 0 0 1
3 |1 0 0 1
4 |0 1 1 0
----- or -----
[[0,0,1,0],[0,0,0,1],[1,0,0,1],[0,1,1,0]]

Task
Your code should take input in the form of 1 (as a vertex list) and output it as 2 (as an adjacency matrix)
The graph is not directed (aka it is an undirected graph).
You can also accept input which is 0-indexed. For example: [[0,2],[1,3],[2,3]]
This is code golf, shortest answer wins.
You can also output 2 different values instead of 1 and 0.
Test cases
[[1,2],[3,4]] -> [[0,1,0,0],[1,0,0,0],[0,0,0,1],[0,0,1,0]]
[[1,3],[2,4],[3,4]] -> [[0,0,1,0],[0,0,0,1],[1,0,0,1],[0,1,1,0]]
[[1,2],[2,3],[5,6]] -> [[0,1,0,0,0,0],[1,0,1,0,0,0],[0,1,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,1],[0,0,0,0,1,0]]
[[1,2]] -> [[0,1],[1,0]]
[[1,2],[4,5]] -> [[0,1,0,0,0],[1,0,0,0,0],[0,0,0,0,0],[0,0,0,0,1],[0,0,0,1,0]]
[[4,5]] -> [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,1],[0,0,0,1,0]]
[[4,5],[2,1]] -> [[0,1,0,0,0],[1,0,0,0,0],[0,0,0,0,0],[0,0,0,0,1],[0,0,0,1,0]]

"""

def adjacency(v):
    n = max(max(v))
    m = [[0 for i in range(n)] for j in range(n)]
    for e in v:
        i, j = e[0] - 1, e[1] - 1
        m[i][j] = m[j][i] = 1
    return m

def main():
    assert(adjacency([[1, 2], [3, 4]]) == [[0, 1, 0, 0], [1, 0, 0, 0], [0, 0, 0, 1], [0, 0, 1, 0]])
    assert(adjacency([[1, 3], [2, 4], [3, 4]]) == [[0, 0, 1, 0], [0, 0, 0, 1], [1, 0, 0, 1], [0, 1, 1, 0]])
    assert(adjacency([[1, 2], [2, 3], [5, 6]]) == [[0, 1, 0, 0, 0, 0], [1, 0, 1, 0, 0, 0], [0, 1, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 1, 0]])
    assert(adjacency([[1, 2]]) == [[0, 1], [1, 0]])
    assert(adjacency([[1, 2], [4, 5]]) == [[0, 1, 0, 0, 0], [1, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 1], [0, 0, 0, 1, 0]])
    assert(adjacency([[4, 5]]) == [[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 1], [0, 0, 0, 1, 0]])
    assert(adjacency([[4, 5], [2, 1]]) == [[0, 1, 0, 0, 0], [1, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 1], [0, 0, 0, 1, 0]])

main()
