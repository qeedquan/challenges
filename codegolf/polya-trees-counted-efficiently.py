#!/usr/bin/env python3

"""

The number of unlabeled rooted trees with n nodes is a fundamental sequence in graph theory and in discrete mathematics in general. Some authors call these trees 'Polya trees'. The number of these trees is one of the 'core' sequences in the OEIS A000081.

A natural refinement of the enumeration asks how many of these trees have a given height. This is investigated in A034781 (has keyword 'nice'). In practice, a third sequence arises: one would like to know how many of these trees with a given number of vertices do not exceed a certain height. This sequence is to be implemented here.

Formally, we deviate a little from the presentation in A034781: We consider n vertices with n >= 0 (as is also done in A000081) and differentiate with respect to the level. The level of a vertex is the number of vertices in the path from the root to the vertex (this is just one more than the depth of the vertex), and the level of the root is 1.

The enumeration can be written as a lower triangular matrix, where the row index indicates the number of vertices. So A000081 is found in the main diagonal.

0: [0]
1: [0, 1]
2: [0, 0, 1]
3: [0, 0, 1,  2]
4: [0, 0, 1,  3,  4]
5: [0, 0, 1,  5,  8,   9]
Task:

Write a function T(n, k) that implements the above matrix. It is about the efficiency of the algorithm. To do this, calculate the first b rows of the triangle:

Row(n) = [T(n, k) for k in 0..n],
Triangle(b) = [Row(n) for n in 0..b-1].
For b = 64 and b = 128, measure the time required t(b). The competition criterion is the quotient t(128)/t(64) [the smaller the better]; the computing time is unimportant. Roughly speaking, the criterion measures by what the computing time multiplies when the number of rows doubles. The smallest quotient in a programming language wins.

Note: The function should be kept completely general and must not contain any instructions for special parameter values. Wait or sleep instructions are not allowed. The quotient a(n)/a(m) for two different values ​​n, m must represent the ratio of the execution times in a fair manner.

I wrote a reference implementation for Python. The quotient on my computer is 15.78; thus the computing time roughly increases by a factor of 2^4 when the number of rows is doubled.

"""

import functools

# Ported from @Jonathan Allan solution

@functools.lru_cache(None)
def divisors(n):
    return [d for d in range(n, 0, -1) if n % d == 0]

@functools.lru_cache(None)
def divisor_weighted_tree_count(nodes, max_height):
    return sum(d * tree_count(d, max_height) for d in divisors(nodes))

@functools.lru_cache(None)
def tree_count(nodes, max_height):
    if nodes == 1:
        return int(max_height > 0)
    if max_height == 0:
        return 0
    next_height = max_height - 1
    return sum(
        tree_count(i, max_height) * divisor_weighted_tree_count(nodes - i, next_height)
        for i in range(1, nodes)
    ) // (nodes - 1)

for i in range(6):
    for j in range(i + 1):
        print(tree_count(i, j), end=' ')
    print()
