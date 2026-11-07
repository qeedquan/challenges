#!/usr/bin/env python3

"""

Given an array of integers. Create a Binary Search Tree from these numbers. If the number is already in the tree, do not insert it (no duplicates).

Find the sum of nodes in the specified subtree.

Input
The first line contains numbers n (1≤n≤1000) and v (0≤v≤10000). The second line contains n integers.

Output
Create the Binary Search Tree from input data. Print the sum of all nodes in the subtree with root in v. If vertex v is not present in the tree, print −1.

Examples

https://static.e-olymp.com/content/9b/9bdbdfbc1506716468444de1c26ca19d6df353a8.gif

The sum of nodes in the subtree with root 5 equals 4+5+7=16.

Input #1
11 5
9 3 11 5 10 7 16 1 4 3 10

Answer #1
16

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

def sum(root):
    if root == None:
        return 0
    return root.val + sum(root.left) + sum(root.right)

def find(root, target):
    while root != None:
        if root.val == target:
            return root
        if target < root.val:
            root = root.left
        if target > root.val:
            root = root.right
    return None

def solve(numbers, target):
    root = None
    for num in numbers:
        root = insert(root, num)
    
    root = find(root, target)
    if root == None:
        return -1

    return sum(root)

def main():
    assert(solve([9, 3, 11, 5, 10, 7, 16, 1, 4, 3, 10], 5) == 16)

main()

