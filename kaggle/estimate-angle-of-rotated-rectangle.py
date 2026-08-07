#!/usr/bin/env python3

"""

Given a set of points of a rotated rectangle, we want to find the angle of rotation

One horrible way to do this is to use PCA
PCA will generate eigenvectors that correspond to the basis of the rotation matrix, but the basis vectors of that forms the PCA rotation matrix does not necessarily represent the original rotation matrix
The basis can be flipped on one axis or both axis depending on how much points we are given in the X/Y direction (If number of X samples > number of Y samples, then the basis vector of XY will be swapped with YX)
If we sample the same number of points on the X/Y direction (a square), then PCA will always return the basis vectors that can form an identity matrix, so it is important to use uneven samples in XY
Note that we do not need alot of samples to get a good PCA estimate

Although the sign of the basis vectors are different and the basis vectors might have to swap with each other when forming the rotation matrix, it is in the ballpark in the sense we can brute force the sign/row swapping to figure out the original rotation matrix

"""

import sys
import numpy as np
from sklearn.decomposition import PCA

def gen(width, height, degrees):
    t = np.radians(degrees)
    c = np.cos(t)
    s = np.sin(t)
    R = np.array(((c, -s), (s, c)))
    r = []
    for y in range(height):
        for x in range(width):
            px = x - width/2
            py = y - height/2
            r.append(np.dot(R, np.array([px, py])))
    return R, np.array(r)

def main():
    N0 = 10
    N1 = 5
    if len(sys.argv) == 3:
        N0 = int(sys.argv[1])
        N1 = int(sys.argv[2])

    for degree in range(360):
        R, P0 = gen(N0, N1, degree)
        _, P1 = gen(N1, N0, degree)
        _, P2 = gen(max(N0, N1), max(N0, N1), degree)

        pca = PCA(n_components=2)
        
        pca.fit(P0)
        RP0 = pca.components_
        
        pca.fit(P1)
        RP1 = pca.components_

        pca.fit(P2)
        RP2 = pca.components_

        print(degree)
        print(R)
        print(RP0)
        print(RP1)
        print(RP2)
        print()

        if N0 > N1:
            RP1[[0, 1]] = RP1[[1, 0]]
        else:
            RP0[[0, 1]] = RP0[[1, 0]]

        assert(np.allclose(abs(R), abs(RP0)))
        assert(np.allclose(abs(R), abs(RP1)))

main()
