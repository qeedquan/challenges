#!/usr/bin/env python3

"""

Implement sinusoidal positional encodings as described in "Attention Is All You Need" to inject sequence order into token embeddings.

Given a sequence length and model dimension, compute the positional encoding matrix using the sin/cos formulation.

Mathematical Definition
For position pos and dimension index i:

PE(pos, 2i)     = sin(pos / base^(2*i/d_model))
PE(pos, 2i + 1) = cos(pos / base^(2*i/d_model))

Even-indexed columns use sine, odd-indexed columns use cosine, and the frequency decreases with dimension index.

Examples
Input: seq_len = 3, d_model = 4

Output: [[0.0000, 1.0000, 0.0000, 1.0000], [0.8415, 0.5403, 0.0100, 0.9999], [0.9093, -0.4161, 0.0200, 0.9998]]

Explanation: Columns alternate sine and cosine values. For the second frequency, the divisor is 100, producing the smaller angles 0.01 and 0.02.

Input: seq_len = 5, d_model = 7, base = 10000.0

Output: NumPy array of shape (5, 7)

Hint 1
Build positions with shape (seq_len, 1) and frequencies with shape (1, ceil(d_model / 2)) for broadcasting.

Hint 2
Fill even columns with sine values and odd columns with the corresponding cosine values.

Requirements
Fully vectorized (no Python loops over positions or dimensions)
Support any seq_len ≥ 1 and d_model ≥ 1
For odd d_model, the last column should be the sin column
Return dtype=float for stable downstream use
Constraints
Sequence lengths up to 10,000
Model dimensions up to 2,048
Use NumPy only
Time limit: 300 ms

"""

import numpy as np

def positional_encoding(seq_len: int, d_model: int, base: float = 10000.0) -> np.ndarray:
    mat = np.zeros((seq_len, d_model))
    for i in range(d_model):
        for pos in range(seq_len):
            if i%2 == 0:
                mat[pos, i] = np.sin(pos / base**(i/d_model))
            else:
                mat[pos, i] = np.cos(pos / base**((i-1)/d_model))
    return mat

np.printoptions(precision=5, suppress=True)
print(positional_encoding(3, 4))
print(positional_encoding(5, 7, 10000))
