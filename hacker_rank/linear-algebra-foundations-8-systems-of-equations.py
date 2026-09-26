#!/usr/bin/env python3

"""

There are more than one integer values of a for which the following system of equations in x, y, z has no solutions:

ax + y + 2z = 0
x + 2y + z = b
2x + y + az = 0

What is the smallest integer value of a for which the above system has no solutions? Fill in the required integer value into the text box. Do not leave any leading or trailing spaces.

"""

import numpy as np

def solve():
    N = 100000
    for a in range(-N, N):
        M = np.array([[a, 1, 2], [1, 2, 1], [2, 1, a]])
        if np.linalg.det(M) == 0:
            return a

print(solve())
