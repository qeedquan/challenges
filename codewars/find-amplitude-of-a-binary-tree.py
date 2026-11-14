#!/usr/bin/env python3

r"""

A binary tree is a data structure in which every node has at most two children (https://en.wikipedia.org/wiki/Binary_tree). A possible implementation in python of a binary tree is:

class Tree(object):

  def __init__(self, data, left=None, right=None):
    self.data = data
    self.left = left
    self.right = right

A path of a tree is a sequence of consecutive nodes, starting from the root node and ending in a leaf. The amplitude of a path is the biggest difference between two node values in a path. The amplitude of a tree is the biggest amplitude of all paths. An empty tree has the amplitude 0.

Consider this tree:

    5
   / \
  1   2
 / \
3   9

This tree has the paths [5, 1, 3] (amplitude 4), [5, 1, 9] (amplitude 8) and [5, 2] (amplitude 3). Hence, its amplitude is 8.

In this Kata you have to write a function which takes the root node of a tree (defined as in the example) as an argument and returns its amplitude.

"""

class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def recurse(node, lo, hi):
    if not node:
        return hi - lo
    lo = min(lo, node.data)
    hi = max(hi, node.data)
    if not node.left and not node.right:
        return hi - lo
    return max(recurse(node.left, lo, hi), recurse(node.right, lo, hi))

def tree_amplitude(root):
    if not root:
        return 0
    return recurse(root, root.data, root.data)

def main():
    tree = Node(5, Node(1, Node(3), Node(9)), Node(2))
    
    assert(tree_amplitude(tree) == 8)

main()

