#!/usr/bin/env python3

"""

There have already been challenges about computing the exponential of a matrix, as well as computing the natural logarithm of a number. This challenge is about finding the (natural) logarithm of matrix.

You task is to write a program of function that takes an invertible n×n matrix A as input and returns the matrix logarithm of that matrix. The matrix logarithm of a matrix A is defined (similar to the real logarithm) to be a matrix L with exp(L)=A.

Like the complex logarithm the matrix logarithm is not unique, you can choose to return any of the possible results for a given matrix.

Examples (rounded to five significant digits):

log( [[ 1,0],[0, 1]] ) = [[0,0], [0,0]]
log( [[ 1,2],[3, 4]] ) = [[-0.3504 + 2.3911i, 0.9294 - 1.0938i], [1.3940 - 1.6406i, 1.04359 + 0.75047i]]
log( [[-1,0],[0,-1]] ) = [[0,pi],[-pi,0]] // exact
log( [[-1,0],[0,-1]] ) = [[0,-pi],[pi,0]] // also exact
log( [[-1,0],[0,-1]] ) = [[pi*i,0],[0,pi*i]] // also exact

log( [[-1,0,0],[0,1,0],[0,0,2]] ) = [[3.1416i, 0, 0], [0, 0, 0], [0, 0, 0.69315]]
log( [[1,2,3],[4,5,4],[3,2,1]] ) = [[0.6032 + 1.5708i, 0.71969, -0.0900 - 1.5708i],[1.4394, 0.87307, 1.4394],[-0.0900 - 1.5708i, 0.71969, 0.6032 + 1.5708i]]

If you want to try out more examples use the function digits 5 matrix logarithm followed by a matrix in Wolfram Alpha

Rules:

You can Input/Output matrices as nested lists
You can Input/Output complex numbers as pairs of real numbers
You can assume the logarithm of the input matrix exists
Your result should be accurate up to at least 5 significant (decimal) digits
You only have to handle matrices of sizes 2×2 and 3×3
You program may return different results when called multiple times on the same input as long as all of them are correct
Please add builtin answers (including libraries) to the community wiki instead of posting them separately
This is code-golf the shortest solution (per language) wins

"""

import numpy as np
from scipy.linalg import *

def test(M, R):
    L = logm(M)
    print(L)
    assert(np.allclose(L, R, atol=1e-3))

def main():
    test([[1, 0], [0, 1]], [[0, 0], [0, 0]])
    test([[1, 2], [3, 4]], [[-0.3504 + 2.3911j, 0.9294 - 1.0938j], [1.3940 - 1.6406j, 1.04359 + 0.75047j]])
    test([[-1, 0], [0, -1]], [[np.pi*1j, 0], [0, np.pi*1j]])
    test([[-1, 0, 0], [0, 1, 0], [0, 0, 2]], [[3.1416j, 0, 0], [0, 0, 0], [0, 0, 0.69315]])
    test([[1, 2, 3], [4, 5, 4], [3, 2, 1]], [[0.6032 + 1.5708j, 0.71969, -0.0900 - 1.5708j],[1.4394, 0.87307, 1.4394], [-0.0900 - 1.5708j, 0.71969, 0.6032 + 1.5708j]])

main()
