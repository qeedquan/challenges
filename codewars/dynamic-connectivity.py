#!/usr/bin/env python3

"""

The Dynamic Connectivity Problem

Given a set of of N objects, is there a path connecting the two objects?

Implement an class that implements the following API:

Takes n as input, initializing a data-structure with N objects (0...N-1)
Implements a Union command that adds a connection between point p and point q
Implements a Connected command that returns a boolean and asks is there a connection between point p and point q

As a simple example: Imagine you initialize an data structure filled with integers from 0 to 9 (N = 10)

  results1 = DynamicConnectivity(10)

You will receive a series of union commands linking various points

  results1.union(4,3)
  results1.union(3,8)
  results1.union(6,5)
  results1.union(9,4)
  results1.union(2,1)

This should result in 5 groups of connections:

3,4,8,9
5,6
2,1
0
7

All members of a groups (set) are conected to every other member If you asked is 0 connected to 7, it should return False If you asked is 8 connected to 9 you should return True even if 8,9 wern't directly joined. (8 is connected to 3 which is connected to 4 which is connected to 9)

  results1.connected(0,7) == False
  results1.connected(8,9) == True

For the purposes of this problem, you do not have to mainatin the order of the connections, you just have to know that the connection is there.

Hint: There is a naive implenetation that takes time proportional to O(n^2) (Quadratic Funtion) This will time out the problem (Because every time you double the input like from 50 nodes to 100 nodes, the function takes 4 times as long) Test will check that you are able to outrun this naive implementation. If you can't that means that your code is too slow

There is a solution that takes linearitmic time or faster O(n * lg n)

Hint Two: (Take it or leave it) If you find yourself nesting a loop inside a loop, you are creating a quadratic function

Implementation must be able to handle initializing 1 million nodes, and creating connections between those nodes.

Full Tests before submission generate random connections to make sure you can't hard code the connections into your class.

"""

# https://en.wikipedia.org/wiki/Disjoint-set_data_structure
class DynamicConnectivity(object):
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x):
        while x != self.parent[x]:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x

    def union(self, p, q):
        a, b = self.find(p), self.find(q)
        if a == b:
            return
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.parent[b] = a
        self.size[a] += self.size[b]

    def connected(self, p, q):
        return self.find(p) == self.find(q)

results1 = DynamicConnectivity(10)
results1.union(4, 3)
results1.union(3, 8)
results1.union(6, 5)
results1.union(9, 4)
results1.union(2, 1)
assert(results1.connected(0, 7) == False)
assert(results1.connected(8, 9) == True)
