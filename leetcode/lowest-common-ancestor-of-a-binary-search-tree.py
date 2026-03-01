#!/usr/bin/env python3

"""

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2

Constraints:

The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the BST. 

"""

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def lca(r, p, q):
    if not p or not q:
        return r

    s, b = sorted([p.val, q.val])
    while not (s <= r.val and r.val <= b):
        if s <= r.val:
            r = r.left
        else:
            r = r.right
    return r

def main():
    t1 = Node(6, Node(2, Node(0), Node(4, Node(3), Node(5))), Node(8, Node(7), Node(9)))
    t2 = Node(2, Node(1))

    assert(lca(t1, Node(2), Node(8)).val == 6)
    assert(lca(t1, Node(2), Node(4)).val == 2)
    assert(lca(t2, Node(2), Node(1)).val == 2)

main()

