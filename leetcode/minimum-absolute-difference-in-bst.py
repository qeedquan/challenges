#!/usr/bin/env python3

"""

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Example 1:
https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg
Input: root = [1,0,48,null,null,12,49]
Output: 1

Constraints:

The number of nodes in the tree is in the range [2, 10^4].
0 <= Node.val <= 10^5
 
Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

"""

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def recurse(root, prev, result):
    if not root:
        return (result, prev)

    result, prev = recurse(root.left, prev, result)
    if prev:
        result = min(result, root.value - prev.value)
    
    return recurse(root.right, root, result)

def difference(root):
    result, _ = recurse(root, None, float('inf'))
    return result

def main():
    tree1 = Node(4, Node(2, Node(1), Node(3)), Node(6))
    tree2 = Node(1, Node(0), Node(48, Node(12), Node(49)))
    
    assert(difference(tree1) == 1)
    assert(difference(tree2) == 1)

main()

