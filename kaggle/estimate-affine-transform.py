#!/usr/bin/env python3

"""

Given x and y as vectors, find the affine transformation matrix A that transforms x to y as close as possible
Ax = y

Since the matrix A is affine, it can recover rotations, scales, translations, shears, etc 

If we restrict it to rotations/scales/translations, this problem is known as the absolute orientation problem

https://en.wikipedia.org/wiki/Random_sample_consensus
https://www.eecs.yorku.ca/course_archive/2012-13/F/6338/lectures/LeastMedianOfSquares.pdf
https://www.ipb.uni-bonn.de/html/teaching/photo12-2021/2021-pho2-08-absolute-orient.pptx.pdf

"""

import cv2
import numpy as np
from scipy.stats import special_ortho_group

def test_estimate(dim, N=10000):
    R = special_ortho_group.rvs(dim)
    S = np.random.randint(1000)
    T = np.array(np.random.rand(1, dim) * 10000)[0]
    x = np.array(np.random.rand(N, dim))
    y = []
    for p in x:
        q = np.array(np.dot(R, S*p)) + T
        y.append(q)
    y = np.array(y)

    if dim == 2:
        M, _ = cv2.estimateAffine2D(x, y)
    elif dim == 3:
        _, M, _ = cv2.estimateAffine3D(x, y)

    # These should match closely
    print(M)
    print(R*S)
    print(T)
    print()

def main():
    np.set_printoptions(precision=6, suppress=True)
    test_estimate(2)
    test_estimate(3)

main()
