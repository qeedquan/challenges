#!/usr/bin/env python3

"""

Given an array of integers. Create a Binary Search Tree from these numbers. If the inserted value equals to the current node, insert it to the right subtree.

Write methods Min and Max that find a minimum and a maximum element in a tree.

https://static.e-olymp.com/content/ff/ff76f493eac07dc1d6933d45186cbc1811ed9dd1.gif

Write the code according to the next interface:

// C++
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree 
{
public:
    TreeNode *head;
    Tree() : head(NULL) {};
    void Insert(int val); // Insert number val to Binary Search Tree
    int Min(void); // Return minimum in a tree
    int Max(void); // Return maximum in a tree
};

You can create (use) additional methods if needed.

Input
The first line contains number n (1≤n≤100). The second line contains n integers.

Output
Create the Binary Search Tree from input data. Print in one line the Minimum and the Maximum element in a tree.

Examples
Input #1
6
14 9 1 14 20 13

Answer #1
1 20

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

def minimum(root):
    result = 0
    while root is not None:
        result = root.val
        root = root.left
    return result

def maximum(root):
    result = 0
    while root is not None:
        result = root.val
        root = root.right
    return result

def solve(numbers):
    root = None
    for num in numbers:
        root = insert(root, num)
    return (minimum(root), maximum(root))

def main():
    assert(solve([14, 9, 1, 14, 20, 13]) == (1, 20))

main()

