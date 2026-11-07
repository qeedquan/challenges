#!/usr/bin/env python3

"""

The problem of absolute orientation is to recover the transformation A that transform x to y.
The restriction is that A is of the form: rotation + scale + translation matrix

"""

import numpy as np
from scipy.stats import special_ortho_group
from scipy.spatial.transform import Rotation

"""

Scale:

ys = Sum[i=0, n] dot((y[i] - y0)^T, (y[i] - y0))
ys = Sum[i=0, n] dot((x[i] - x0)^T, (x[i] - x0))
y0 = mean(y)
x0 = mean(x)
S = sqrt(ys/xs)

Rotation:
H = covariance matrix of X and Y
U, _, V = SVD(H)
R = U * V^T

Translation:
T = y0 - R*S*x0

"""
def estimate_absolute_orientation(dim, x, y):
    N = len(y)

    x0 = np.mean(x, axis=0)
    y0 = np.mean(y, axis=0)

    # recover scale
    ys = 0
    xs = 0
    for i in range(N):
        ys += np.dot(np.transpose(y[i] - y0), y[i] - y0)
        xs += np.dot(np.transpose(x[i] - x0), x[i] - x0)
    S = np.sqrt(ys / xs)

    # compute covariance matrix
    # https://gist.github.com/atandrau/847214/882418ab34737699a6b1394d3a28c66e2cc0856f
    H = np.zeros((dim, dim))
    for i in range(dim):
        for j in range(dim):
            for k in range(N):
                H[i][j] += (x[k][i] - x0[i]) * (y[k][j] - y0[j])
            H[i][j] /= (N - 1)
    
    # SVD to get rotation
    U, _, Vh = np.linalg.svd(np.transpose(H))
    R = np.dot(U, Vh)
    
    # get translation last by undoing rotation and scale
    T = y0 - np.dot(R*S, x0)

    return R, S, T

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

    RP, SP, TP = estimate_absolute_orientation(dim, x, y)
    print(S)
    print(SP)

    print(R)
    print(RP)
    if dim == 3:
        print(Rotation.from_matrix(R).as_euler("xyz", degrees=dim))
        print(Rotation.from_matrix(RP).as_euler("xyz", degrees=dim))

    print(T)
    print(TP)

    print()

def main():
    test_estimate(2)
    test_estimate(3)

main()
