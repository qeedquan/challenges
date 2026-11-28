#!/usr/bin/env python3

"""

Objective
Given a permutation of 4 distinct items, classify the permutation by the normal subgroup(s) it belongs.

Input/Output Format
You gotta choose the followings as the hyperparameters for your submission:

The 4 distinct items.

The permutation serving as the identity permutation.

The input format is to accept a permutation of the items you chose. The items must be computably distinguishable.

The output format is flexible; you can output anything as long as the classes are computably distinguishable.

Standard loopholes apply.

In any case, an input not fitting into your format falls into don't care situation.

Classification
For example, suppose you chose the numbers 0, 1, 2, and 3 as the 4 items, and chose the string 0123 as the identity permutation.

The identity permuation 0123 is classified as the member of the trivial group 0.

The permutations consisting of two non-overlapping swaps are classified as members of the Klein-four group K4 minus the trivial group. Those are 1032, 2301, and 3210.

The permutations that fixes exactly one item are classified as members of the alternating group A4 minus the Klein-four group. Those are 0231, 0312, 1203, 1320, 2013, 2130, 3021, and 3102.

The remaining permuations are classified as members of the symmetric group S4 minus the alternating group.

Examples
Let's say you chose the string READ as the identity permutation, and chose to output the classes as numbers 0, 1, 2, and 3, respectively to the list above.

Given the string ADER, output 3.

Given the string ADRE, output 1.

Given the string RADE, output 2.

Given the string READ, output 0.

"""

import numpy as np
from itertools import *

"""

@Albert Lang

Uses as the four distinct items the vectors [1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]. With this convention the input, conveniently, becomes a permutation matrix.

Outputs 2 x # fixed points A - # fixed points AA. This maps the identity to 4, the rest of the Klein four group to -4, the rest of the alternating group to 1 and everything else to 0.

"""
def subgroup(A):
    M = 2*A - np.dot(A, A)
    return M.trace()

def main():
    A = np.diag(4*[1])
    for *x, in permutations([0, 1, 2, 3]):
        print(x, subgroup(A[x]))

main()
