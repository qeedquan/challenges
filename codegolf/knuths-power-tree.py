#!/usr/bin/env python3

"""

In The Art of Computer Programming, Knuth describes an algorithm to compute short addition chains. The algorithm works by computing a tree known as the Power Tree. The tree is rooted at 1, and each level is computed from the previous. Suppose we've computed level k. Then, for each node (n) in level k, and each ancestor (or self) a = 1, 2, ..., n of n, add the node n+a to level k+1 if it is not already in the tree; the parent of n+a is n.

Three important things to note:

nodes should be visited in the order that they are created
levels are to be computed one at a time (not recursively)
traverse the ancestors from smallest to largest (or you end up a familiar, but less optimal tree)
A picture of the tree

Perhaps drawing this tree would be fun to golf? Hmm. At the least, the result would probably be a better-drawn tree. FWIW, 10 has 4 children.

             1
             |
             2
            / \
           3   4
          /\    \
         /  \    \
        5    6    8
       / \    \\   \
      /  |     \\   \
     /   |      \\   \
    7    10     9 12  16
   /   / /\ \    \ \   \\
  /   / /  \ \    \ \   \\
14  11 13  15 20  18 24 17 32
Naive Python Implementation

Since my verbose description of the tree seems to be lacking, here's a naive Python implementation. I store the tree as a dictionary here, parent(x) := tree[x]. There's lots of fun optimization to be had here.

def chain(tree,x):
    c = [x]
    while x!=1:
        x=tree[x]
        c.append(x)
    return c[::-1]

tree = {1:None}
leaves = [1]
levels = 5
for _ in range(levels):
    newleaves = []
    for m in leaves:
        for i in chain(tree,m):
            if i+m not in tree:
                tree[i+m] = m
                newleaves.append(i+m)
    leaves = newleaves
Requirements

Your program should take one argument n, compute the complete tree with all integer nodes i with 0 <= i <= n, and then take input from the user. For each input, print out the path from the root to that input. If an input isn't an integer between 0 and n (inclusive), behavior is undefined. Terminate if the user inputs zero.

Example Session

./yourprogram 1000
?1000
1 2 3 5 10 15 25 50 75 125 250 500 1000
?79
1 2 3 5 7 14 19 38 76 79
?631
1 2 3 6 12 24 48 49 97 194 388 437 631
?512
1 2 4 8 16 32 64 128 256 512
?997
1 2 3 5 7 14 28 31 62 124 248 496 501 997
?0

"""

from math import *

def chain(tree, x):
    c = [x]
    while x != 1:
        x = tree[x]
        c.append(x)
    return c[::-1]

def mktree(levels):
    tree = {1: None} 
    leaves = [1]
    for _ in range(levels):
        newleaves = []
        for m in leaves:
            for i in chain(tree, m):
                if i+m not in tree:
                    tree[i+m] = m
                    newleaves.append(i+m)
        leaves = newleaves
    return tree

def path(n):
    if n < 1:
        return []
    
    l = int(ceil(log2(n))) * 2
    return chain(mktree(l), n)

def main():
    assert(path(1000) == [1, 2, 3, 5, 10, 15, 25, 50, 75, 125, 250, 500, 1000])
    assert(path(79) == [1, 2, 3, 5, 7, 14, 19, 38, 76, 79])
    assert(path(631) == [1, 2, 3, 6, 12, 24, 48, 49, 97, 194, 388, 437, 631])
    assert(path(512) == [1, 2, 4, 8, 16, 32, 64, 128, 256, 512])
    assert(path(997) == [1, 2, 3, 5, 7, 14, 28, 31, 62, 124, 248, 496, 501, 997])
    assert(path(0) == [])

main()
