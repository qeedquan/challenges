#!/usr/bin/env python3

"""
Print the transpose and the flatten matrix
"""

import numpy as np

l = np.array([[1, 2, 3], [4, 5, 6]])
print(np.transpose(l))
print(l.flatten())

l = np.array([[1, 2], [3, 4]])
print(np.transpose(l))
print(l.flatten())
