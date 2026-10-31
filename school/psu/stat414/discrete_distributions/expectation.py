#!/usr/bin/env python3

"""

Expectation is the mean of a set of sample from a distributions as the set of samples grows to infinity
The properties of expectations applies to the finite sample means too

Expectation known as the first moment about the origin

"""

import numpy as np

"""

Expectation is linear, which means:

X = random values from a distribution
E[c*X] = c*E[X]

E[aX + bY] = aE[X] + bE[Y]

"""
def test_properties():
    c = np.random.randint(100)
    x = np.random.randint(10000, size=10000)
    y = c*x

    X = np.mean(x)
    Y = np.mean(y)
    assert(np.allclose(c*x, y))

    a = np.random.randint(100)
    b = np.random.randint(5000)
    x = np.random.randint(10000, size=10000)
    y = np.random.randint(50000, size=10000)
    M = np.mean(a*x + b*y)
    N = a*np.mean(x) + b*np.mean(y)
    assert(np.allclose(M, N))

def main():
    for i in range(1000):
        test_properties()

main()
