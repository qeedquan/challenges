#!/usr/bin/env python3

"""

Compute the angle in radians between two 3D vectors. First obtain their cosine:

c = dot(v, w) / (norm(v)*norm(w))

Then recover the angle:

θ = arccos(c)

Clamp c to [-1, 1] before applying arccos to protect against floating-point error.
If either vector has zero norm, the angle is undefined, so return np.nan.
Otherwise return a Python float in [0, pi]

Examples
Input: v = [1, 0, 0], w = [0, 1, 0]

Output: 1.570796

Explanation: Orthogonal vectors have cosine zero and an angle of pi divided by two.

Input: v = [1, 2, 3], w = [2, 4, 6]

Output: 0

Hint 1
Use np.dot(v, w) for the numerator and squared sums for both norms.

Hint 2
Pass np.clip(cosine, -1.0, 1.0) to np.arccos.

Requirements
Compute both Euclidean norms and the dot product
Return np.nan when either norm is zero
Clamp the cosine before applying np.arccos
Return a Python float
Constraints
Both inputs contain exactly three numeric values
Use NumPy only

"""

import numpy as np

def angle_between_3d(v: list, w: list) -> float:
    a = np.dot(v, w)
    b = np.linalg.norm(v) * np.linalg.norm(w)
    if b == 0:
        return np.nan
    c = np.clip(a/b, -1, 1)
    return np.acos(c)

def main():
    print(angle_between_3d([1, 0, 0], [0, 1, 0]))
    print(angle_between_3d([1, 2, 3], [2, 4, 6]))

main()
