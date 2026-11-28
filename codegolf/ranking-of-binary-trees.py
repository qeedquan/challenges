#!/usr/bin/env python3

r"""

Let N = [0,1,2,...n-1] be the initial segment of the natural numbers of length n, then all permutations of N can be sorted lexicographically, starting with the identity. The index into this sorted array is known as the rank of the permutation.

For example, the permutations for n = 3 can be seen in RosettaCode, where also various algorithms for the ranking are described in different languages.

But N can also be written as a binary tree by going level by level from top to bottom and from left to right and filling the tree nodes with the elements of N keeping their natural order. For n = 5, this tree is

     0
    / \
   1   2
  / \
 3   4
Once you have the tree, you can traverse it in various ways. Here we look at the pre-order traversal. In the example, this is the sequence [0,1,3,4,2]. The rank of this sequence, seen as a permutation, is 3.

Some more examples:

 n -> traversal of binary tree as permutation -> rank
 6 -> [0, 1, 3, 4, 2, 5]                      -> 8
 8 -> [0, 1, 3, 7, 4, 2, 5, 6]                -> 222
10 -> [0, 1, 3, 7, 8, 4, 9, 2, 5, 6]          -> 8442
TASK

Given n, construct the binary tree as described above for [0,1,2,...n-1], and return the rank of the permutation provided by the pre-order traversal of this tree. Provide evidence by showing the ranks for n = 4,5,...,9.

Scoring: This is code-golf, so the shortest code for each language wins!

"""

from sympy.combinatorics import Permutation

r"""

https://oeis.org/A379905

@Unrelated String

Intuition:
If you label the nodes with [1,n] instead of [0,n-1], the labels at each "tier" of the tree all have the same length in bits:

                    1
                .../ \...
           ..../         \....
          /                   \
         10                   11
        /  \                 /  \
       /    \               /    \
      /      \             /      \
     /        \           /        \
   100        101       110        111
  /   \      /   \     /   \      /   \
1000 1001  1010 1011 1100 1101  1110 1111

and not only that, but the tree is a prefix tree of the binary representations--the direct children of every node are labeled with precisely its label with either 0 or 1 appended.
Hence, lexicographic comparison of the bits will sort correctly within each tier, sort all nodes after their immediate parents, and sort all nodes before later nodes than their parents in their parents' tier.

"""

def rank(n):
    p = Permutation(sorted(range(n + 1), key=bin))
    return p.rank()

def main():
    assert(rank(6) == 8)
    assert(rank(8) == 222)
    assert(rank(10) == 8442)

main()
