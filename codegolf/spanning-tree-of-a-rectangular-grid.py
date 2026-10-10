#!/usr/bin/env python3

r"""

Background
A spanning tree (Wikipedia) of an undirected graph is a subgraph that is a tree which includes all of the vertices of the original graph. The following is an example of a spanning tree of a 4-by-4 grid graph.

Task
Given two positive integers w and h, output any valid spanning tree of the grid graph which has w vertices horizontally and h vertices vertically. There are lots of valid answers; just output one of them. Your code is even allowed to give different outputs across runs, as long as all of them are valid.

Input and output
The input is two positive integers w and h.

The output is a representation of a spanning tree. The output format is restricted to "a list of pairs of numbered vertices", in order to prevent various boring answers (as discussed in the sandbox). Also, the vertex numbering should be in row-major order, e.g.

0 - 1 - 2 - 3
|   |   |   |
4 - 5 - 6 - 7
|   |   |   |
8 - 9 - 10- 11
or

(0,0) - (0,1) - (0,2) - (0,3)
  |       |       |       |
(1,0) - (1,1) - (1,2) - (1,3)
  |       |       |       |
(2,0) - (2,1) - (2,2) - (2,3)
You can choose to use 0-based or 1-based indexing for vertices. Also, you may output nested or flattened arrays.

Scoring & winning criterion
The standard code-golf rules apply. The shortest valid submission in bytes wins.

Example I/O
w=3, h=2
If you want to output the following graph

+-+-+
| |
+ +-+
The list-of-vertex-pairs representation will be (using 0-based indexing for example):

[(0, 1), (0, 3), (1, 2), (1, 4), (4, 5)]
or

[((0, 0), (0, 1)),
 ((0, 0), (1, 0)),
 ((0, 1), (0, 2)),
 ((0, 1), (1, 1)),
 ((1, 1), (1, 2))]
w=1, h=1
The graph is a single vertex with no edges, and its only spanning tree is the graph itself. Your code should output an empty list (which means no edges).

"""

# Ported from @xnor solution
def span(w, h):
    t1 = list(range(w - 1)) + list(range(w * h))
    t2 = list(range(1, w * h))
    return list(zip(t1, t2))

def main():
    print(span(3, 2))
    print(span(4, 3))
    print(span(1, 1))

main()
