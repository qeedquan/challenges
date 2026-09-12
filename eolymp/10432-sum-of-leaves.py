#!/usr/bin/env python3

"""

Given an array of integers. Create a Binary Search Tree from these numbers. If the number is already in the tree, do not insert it (no duplicates).

Find the sum of all leaves in a tree.

Input
The first line contains number n (1≤n≤1000). The second line contains n integers.

Output
Create the Binary Search Tree from input data. Print the sum of all leaves in a tree.

Examples

https://static.e-olymp.com/content/15/15e10dd59d19107d5f36f26a53af32eb9c13fce0.gif

The sum of leaves equals to 1+5+11=17.

Input #1
7
7 3 5 7 1 11 1

Answer #1
17

"""

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if root is None:
        return Node(val)
    if val < root.val:
        root.left = insert(root.left, val)
    elif val > root.val:
        root.right = insert(root.right, val)
    return root

def sum_of_leaves(root):
    if root is None:
        return 0
    if root.left is None and root.right is None:
        return root.val
    return sum_of_leaves(root.left) + sum_of_leaves(root.right)

def solve(numbers):
    root = None
    for num in numbers:
        root = insert(root, num)
    return sum_of_leaves(root)

def main():
    assert(solve([7, 3, 5, 7, 1, 11, 1]) == 17)

main()

