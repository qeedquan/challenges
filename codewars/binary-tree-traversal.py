#!/usr/bin/env python3

"""

Given the root node of a binary tree (but not necessarily a binary search tree,) write three functions that will print the tree in pre-order, in-order, and post-order.

A Node has the following properties:

data    # A number or a string
left    # A Node, which is None if there is no left child.
right   # A Node, which is None if there is no right child.

Pre-order means that we
1.) Visit the root.
2.) Traverse the left subtree (left node.)
3.) Traverse the right subtree (right node.)

In-order means that we
1.) Traverse the left subtree (left node.)
2.) Visit the root.
3.) Traverse the right subtree (right node.)

Post-order means that we
1.) Traverse the left subtree (left node.)
2.) Traverse the right subtree (right node.)
3.) Visit the root.

Let's say we have three nodes.

a = Node("A")
b = Node("B")
c = Node("C")

a.left = b
a.right = c

Then, preOrder(a) should return ["A", "B", C"]
inOrder(a) should return ["B", "A", "C"]
postOrder(a) should return ["B", "C", A"]

What would happen if we did this?


d = Node("D")
c.left = d

preOrder(a) should return ["A", "B", "C", "D"]
inOrder(a) should return ["B", "A", "D", "C"]
postOrder(a) should return ["B", "D", "C", "A"]


"""

class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def preorder(node):
    if not node:
        return []
    return [node.data] + preorder(node.left) + preorder(node.right)

def inorder(node):
    if not node:
        return []
    return inorder(node.left) + [node.data] + inorder(node.right)

def postorder(node):
    if not node:
        return []
    return postorder(node.left) + postorder(node.right) + [node.data]

def main():
    a = Node("A")
    b = Node("B")
    c = Node("C")
    d = Node("D")
    a.left = b
    a.right = c
    print(preorder(a))
    print(inorder(a))
    print(postorder(a))

    c.left = d
    print(preorder(a))
    print(inorder(a))
    print(postorder(a))

main()
