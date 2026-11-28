#!/usr/bin/env python3

"""

Synteny Blocks Have Orientations

In “Enumerating Gene Orders”, we introduced synteny blocks for two different species, which are very similar areas of two species genomes that have been flipped and moved around by rearrangements. In that problem, we used the permutation to model the order of synteny blocks on a single chromosome.

However, each strand of a DNA molecule has an orientation (as RNA transcription only occurs in one direction), and so to more prudently model chromosomes using synteny blocks, we should provide each block with an orientation to indicate the strand on which it is located. Adding orientations to synteny blocks requires us to expand our notion of permutation so that each index in the permutation has its own orientation.

Problem
A signed permutation of length n is some ordering of the positive integers {1,2,…,n} in which each integer is then provided with either a positive or negative sign (for the sake of simplicity, we omit the positive sign).
For example, π=(5,−3,−2,1,4) is a signed permutation of length 5.

Given: A positive integer n≤6.

Return: The total number of signed permutations of length n, followed by a list of all such permutations (you may list the signed permutations in any order).

Sample Dataset
2

Sample Output
8
-1 -2
-1 2
1 -2
1 2
-2 -1
-2 1
2 -1
2 1

"""

from math import factorial
from itertools import permutations

# https://oeis.org/A000165 (length of signed permutations)
def solve(n):
    L1 = []
    for i in range(n):
        L1.extend([i+1, -i-1])
    
    L2 = list(permutations(L1, n))
    L3 = []
    for x in L2:
        s = set()
        for i in x:
            s.add(abs(i))
        if len(s) < len(x):
            L3.append(x)

    L = list(set(L2) ^ set(L3))
    print(len(L))
    for x in L:
        print(x)

def main():
    solve(2)

main()
