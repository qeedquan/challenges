#!/usr/bin/env python3

"""

Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: 3

Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5

Constraints:

    The total number of nodes is in the range [0, 10^4].
    The depth of the n-ary tree is less than or equal to 1000.

"""

class Node:
    def __init__(self, val, children=[]):
        self.val = val
        self.children = children

def maxdepth(n):
    if n == None:
        return 0

    d = 0
    for p in n.children:
        d = max(d, maxdepth(p))
    return 1 + d

def main():
    t1 = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
    t2 = Node(3, [Node(2), Node(3, [Node(6), Node(7, [Node(11, [Node(14)])])]), Node(4, [Node(8, [Node(12)])]), Node(5, [Node(9, [Node(13)]), Node(10)])])

    assert(maxdepth(t1) == 3)
    assert(maxdepth(t2) == 5)

main()
