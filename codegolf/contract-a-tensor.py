#!/usr/bin/env python3

"""

Introduction
Tensor contraction is an operation that can be performed on a tensor. It is a generalization of the idea of the trace of a matrix. For example, if we have a rank-2 tensor (a matrix) and we contract along both of its axes, we take the sum of each entry in which the indices of these axes are equal. In this case we sum the entries at (0,0), (1,1), (2,2), and so on to get a rank-0 tensor (a scalar), which in this case, is the trace of the matrix.

As another example, if we have a rank-4 tensor (a 4-dimensional array), contraction will output a rank-2 tensor (a matrix). If we are contracting over the first and third axes, the axes in the result correspond to the remaining axes. The entry at (3,4) of the output is produced by summing the entries of the original at (0,3,0,4), (1,3,1,4), and so on.

Challenge
Given a rank-n tensor and two distinct axes, perform tensor contraction along those axes.

Input
You may take the tensor in any reasonable format such as an n dimensional array or list-of-lists-of-...-lists. The tensor is always guaranteed to have equal length (at least 1) along every axis. You may take the axes as either 0-indexed or 1-indexed, as well as in either direction (0 or 1 may refer to the first axis in a list-of-lists or the most nested axis).

Output
Any reasonable format for an rank-(n-2) tensor. In particular, a rank-0 scalar cannot be nested in an array.

Examples
Using 0-indexing:

[[0, 1, 2],
 [3, 4, 5],
 [6, 7, 8]], 0, 1 -> 12 # trace of the matrix

[[[4, 8, 4],
  [1, 6, 9],
  [2, 8, 2]],
 [[8, 4, 9],
  [7, 9, 2],
  [0, 4, 4]],
 [[2, 7, 7],
  [6, 3, 0],
  [3, 8, 8]]], 0, 1 -> [14, 25, 14]

[[[4, 8, 4],
  [1, 6, 9],
  [2, 8, 2]],
 [[8, 4, 9],
  [7, 9, 2],
  [0, 4, 4]],
 [[2, 7, 7],
  [6, 3, 0],
  [3, 8, 8]]], 0, 2 -> [15, 10, 14] # different answer along different axes

[[[[8, 5],
   [7, 9]],
  [[2, 0],
   [6, 0]]],
 [[[8, 3],
   [2, 2]],
  [[1, 3],
   [9, 1]]]], 0, 2 -> [[10,  7],
                       [11,  1]]

[[[[[7]]]]], 1, 4 -> [[[7]]] # contraction always reduces rank by 2

"""

import numpy as np

def contract(m, i, j):
    return m.trace(0, i, j).tolist()

def main():
    m1 = np.array([[0, 1, 2],
                   [3, 4, 5],
                   [6, 7, 8]])
    
    m2 = np.array([[[4, 8, 4],
                    [1, 6, 9],
                    [2, 8, 2]],
                   [[8, 4, 9],
                    [7, 9, 2],
                    [0, 4, 4]],
                   [[2, 7, 7],
                    [6, 3, 0],
                    [3, 8, 8]]])

    m3 = np.array([[[4, 8, 4],
                    [1, 6, 9],
                    [2, 8, 2]],
                   [[8, 4, 9],
                    [7, 9, 2],
                    [0, 4, 4]],
                   [[2, 7, 7],
                    [6, 3, 0],
                    [3, 8, 8]]])

    m4 = np.array([[[[8, 5],
                     [7, 9]],
                    [[2, 0],
                     [6, 0]]],
                   [[[8, 3],
                     [2, 2]],
                    [[1, 3],
                     [9, 1]]]])

    m5 = np.array([[[[[7]]]]])

    assert(contract(m1, 0, 1) == 12)
    assert(contract(m2, 0, 1) == [14, 25, 14])
    assert(contract(m3, 0, 2) == [15, 10, 14])
    assert(contract(m4, 0, 2) == [[10, 7], [11, 1]])
    assert(contract(m5, 0, 1) == [[[7]]])

main()
