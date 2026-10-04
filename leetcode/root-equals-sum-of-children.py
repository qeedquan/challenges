#!/usr/bin/env python3

"""

You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.

Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.

Example 1:

Input: root = [10,4,6]
Output: true
Explanation: The values of the root, its left child, and its right child are 10, 4, and 6, respectively.
10 is equal to 4 + 6, so we return true.

Example 2:

Input: root = [5,3,1]
Output: false
Explanation: The values of the root, its left child, and its right child are 5, 3, and 1, respectively.
5 is not equal to 3 + 1, so we return false.

"""

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def checktree(n):
    if n == None or n.left == None or n.right == None:
        return False
    return n.value == n.left.value + n.right.value

def main():
    t1 = Node(10, Node(4), Node(6))
    t2 = Node(5, Node(3), Node(1))

    assert(checktree(t1) == True)
    assert(checktree(t2) == False)

main()
