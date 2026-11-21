#!/usr/bin/env python3

"""

Apply an autoregressive mask to attention scores so position i can attend only to positions j≤i.
For every score entry, return

M[i, j] = S[i, j]   j <= i
          m         j > i

Here, 
S is the input score tensor and m is mask_value.
The final two dimensions are square attention matrices, while any preceding dimensions represent batches or heads.
Return a masked NumPy array with the same shape without modifying the input.

Examples
Input: scores = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], mask_value = -1000000000.0

Output: [[1.0, -1000000000.0, -1000000000.0], [4.0, 5.0, -1000000000.0], [7.0, 8.0, 9.0]]

Explanation: Entries above the main diagonal represent future positions and are replaced by mask_value.

Input: scores = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]], mask_value = -1000000000.0

Output: [[1.0, -1000000000.0, -1000000000.0, -1000000000.0], [5.0, 6.0, -1000000000.0, -1000000000.0], [9.0, 10.0, 11.0, -1000000000.0], [13.0, 14.0, 15.0, 16.0]]

Hint 1
np.triu(np.ones((T, T), dtype=bool), k=1) marks future positions.

Hint 2
A two-dimensional mask broadcasts across any leading batch and head dimensions.

Requirements
Support score tensors with shape (T,T) or (…,T,T)
Replace only entries above the main diagonal
Return a floating-point NumPy array with the same shape
Do not modify the input
Constraints
The final two dimensions are equal
Use NumPy only

"""

import numpy as np

def apply_causal_mask(scores: list, mask_value: float = -1e9) -> np.ndarray:
    mask = np.array(scores)
    for i in range(mask.shape[0]):
        for j in range(i + 1, mask.shape[1]):
            mask[i][j] = mask_value
    return mask

print(apply_causal_mask([[1, 2, 3], [4, 5, 6], [7, 8, 9]], -1000000000.0))
print(apply_causal_mask([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]], -1000000000.0))
