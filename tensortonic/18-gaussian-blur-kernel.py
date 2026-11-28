#!/usr/bin/env python3

"""

Generate a normalized square Gaussian blur kernel.
For every position, measure offsets x and y from the center and compute:

G(x, y) = exp(-(x^2 + y^2) / (2*sigma^2))

Here, sigma is the supplied standard deviation.
Divide every weight by the sum of all unnormalized weights so the final kernel sums to one.
Return the kernel as a two-dimensional list of floats.

Examples
Input: size = 3, sigma = 1

Output: [[0.075114, 0.123841, 0.075114], [0.123841, 0.20418, 0.123841], [0.075114, 0.123841, 0.075114]]

Explanation: The center receives the largest weight, the kernel is symmetric, and all weights sum to one.

Input: size = 1, sigma = 1

Output: [[1]]

Hint 1
Use size // 2 as the center coordinate.

Hint 2
Accumulate all unnormalized weights before dividing each value by their total.

Requirements
Center coordinates around the middle kernel element
Compute one Gaussian weight per position
Normalize all weights by their total
Return a square two-dimensional list
Constraints
Size is a positive odd integer
Sigma is positive

"""

import numpy as np

def gaussian_kernel(size: int, sigma: float) -> list:
    G = np.zeros((size, size))
    center = size//2
    total = 0
    for y in range(size):
        for x in range(size):
            G[y, x] = np.exp(-((x-center)**2 + (y-center)**2) / (2*sigma**2))
            total += G[y, x]
    G /= total
    return G

def main():
    print(gaussian_kernel(3, 1))
    print(gaussian_kernel(1, 1))

main()
