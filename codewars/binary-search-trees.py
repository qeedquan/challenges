#!/usr/bin/env python3

"""

Binary Search Trees
A Tree consists of a root, which is of type Node, possibly a left subtree of type Tree, and possibly a right subtree of type Tree. If the left subtree is present, then all its nodes are less than the parent tree's root; if the right tree is present, then all its nodes are greater than the parent tree's root.

In this kata, classes Tree and Node have been provided. However, the methods __eq__, __ne__, and __str__ are missing from the Tree class. Your job is to provide the implementation of these methods. The example test cases should provide enough information to implement these methods correctly.

As an illustrative example, here is the string representation of a tree that has two nodes, 'B' at the root and 'C' at the root of the right subtree. The left subtree is missing and the right subtree is a leaf, i.e., has no subtrees:

"[_ B [C]]"

This tree is obtained by evaluating the following expression:

Tree(Node('B'), None, Tree(Node('C')))

Notice in particular that when one subtree, but not both, is missing, an underscore is in its place, a single space separates the root node from the subtrees, and when both subtrees are missing, the root node is enclosed in brackets.

"""

class Tree(object):    
    def __init__(self, root, left=None, right=None):
        self.left = left
        self.root = root
        self.right = right
        
    def is_leaf(self):
        return not (self.left or self.right)
        
    def __str__(self):
        return f"[{self.root}]" if self.is_leaf() else f"[{self.left or '_'} {self.root} {self.right or '_'}]"

    def __eq__(self, o):
        return isinstance(o, Tree) and (self.root, self.left, self.right) == (o.root, o.left, o.right)
    
    def __ne__(self, o):
        return not self == o

class Node(object):
    def __init__(self, value, weight=1):
        self.value = value
        self.weight = weight
    
    def __str__(self):
        return str(self.value)   
    
    def __lt__(self, other):
        return self.value < other.value
    
    def __gt__(self, other):
        return self.value > other.value
    
    def __eq__(self, other):
        return self.value == other.value 

    def __ne__(self, other):
        return self.value != other.value

def main():
    assert(str(Tree(Node('B'), None, Tree(Node('C')))) == "[_ B [C]]")

main()

