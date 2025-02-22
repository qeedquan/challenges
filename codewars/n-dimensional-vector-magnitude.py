#!/usr/bin/env python3

"""

Return the magnitude of a vector, given as an array of its component values.

The vector (2, 3, 5) would be represented as an array containing three values at indices 0, 1 and 2 respectively.
The array will always contain at least 2 and at most 100 elements (2 ≤ vector.Length ≤ 100), each of which will be within the range [-100, 100].
An array containing four elements represents a vector in 4D space.

More info on finding the length of a vector: http://farside.ph.utexas.edu/teaching/301/lectures/node28.html

"""

import numpy as np

def main():
    assert(np.allclose(np.linalg.norm(np.array([0, 0])), 0))
    assert(np.allclose(np.linalg.norm(np.array([2/3, 1/3, 2/3])), 1))
    assert(np.allclose(np.linalg.norm(np.array([-2, -4, 4])), 6))

main()
