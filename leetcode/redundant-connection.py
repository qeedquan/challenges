#!/usr/bin/env python3

"""

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Example 1:
https://assets.leetcode.com/uploads/2021/05/02/reduntant1-1-graph.jpg

Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Example 2:
https://assets.leetcode.com/uploads/2021/05/02/reduntant1-2-graph.jpg

Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.

"""

class Set:
    def __init__(self, n):
        self.id = list(range(n))
        self.rank = [0] * n

    def union(self, u, v):
        i = self.find(u)
        j = self.find(v)
        if i == j:
            return False
        if self.rank[i] < self.rank[j]:
            self.id[i] = self.id[j]
        elif self.rank[i] > self.rank[j]:
            self.id[j] = self.id[i]
        else:
            self.id[i] = self.id[j]
            self.rank[j] += 1
        return True

    def find(self, u):
        if self.id[u] != u:
            self.id[u] = self.find(self.id[u])
        return self.id[u]

def redundant_connection(edges):
    uf = Set(len(edges) + 1)
    for edge in edges:
        if not uf.union(edge[0], edge[1]):
            return edge
    return None

def main():
    assert(redundant_connection([[1, 2], [1, 3], [2, 3]]) == [2, 3])
    assert(redundant_connection([[1, 2], [2, 3], [3, 4], [1, 4], [1, 5]]) == [1, 4])

main()
