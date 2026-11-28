#/usr/bin/env python3

"""

A linear (fully connected) layer is the most fundamental building block in neural networks. It transforms an input by multiplying with a weight matrix and adding a bias vector. This operation is also called a dense layer or an affine transformation.

Given an input matrix X (n samples, d_in features), a weight matrix W (d_in x d_out), and a bias vector b (d_out), compute the linear layer output.

Algorithm

1. For each sample i and output neuron j, compute the weighted sum plus bias:
Y[i, j] = Sum[k] X[i, k]*W[k, j] + b[j]

2. In matrix form:
Y = X*W + b

Where b is broadcast (added to every row of XW).

Return an n by d_out list containing XW plus the broadcast bias.

Examples
Input: X = [[1, 2], [3, 4]], W = [[1, 0], [0, 1]], b = [0, 0]

Output: [[1, 2], [3, 4]]

Explanation: Identity weights and zero bias leave every row unchanged.

Input: X = [[1, 2]], W = [[1], [2]], b = [3]

Output: [[8]]

Hint 1
Compute each output entry from one row of X and one column of W.

Hint 2
Add the corresponding bias value after the inner dot product.

Requirements
Compute Y = XW + b for the given inputs
X is n x d_in, W is d_in x d_out, b is a d_out vector
The bias vector b is broadcast (added to each row)
Return an n x d_out list of lists of floats
Constraints
X has at least 1 row and 1 column
W has dimensions d_in x d_out matching X's column count
b has length d_out
Return an n x d_out list of lists
Time limit: 300 ms

"""

import numpy as np

def linear_layer_forward(X: list, W: list, b: list) -> list:
    return np.array(X)@np.array(W) + np.array(b)

def main():
    print(linear_layer_forward([[1, 2], [3, 4]], [[1, 0], [0, 1]], [0, 0]))
    print(linear_layer_forward([[1, 2]], [[1], [2]], [3]))

main()
