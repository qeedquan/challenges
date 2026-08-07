#!/usr/bin/env python3

"""

You are given two sets.
Set A = {1,2,3,4,5,6}
Set B = {2,3,4,5,6,7,8}

What is the total number of ordered pairs present in the Cartesian Product AxB?

"""

from itertools import product

A = [1, 2, 3, 4, 5, 6]
B = [2, 3, 4, 5, 6, 7, 8]
P = list(product(A, B))
print(len(P))

