#!/usr/bin/env python3

import numpy as np
from scipy.stats import poisson

"""

Moments:

Mean: lambda
Variance: lambda
Skewness: 1/sqrt(lambda)
Kurtosis: 1/lambda

Note the distribution has the special property that variance is equal to the mean

"""

def test_moments():
    mu = 0
    for i in range(10000):
        (skew, kurtosis) = poisson.stats(mu, moments='sk')
        assert(np.allclose(poisson.var(mu), mu))
        assert(np.allclose(poisson.std(mu), np.sqrt(mu)))
        if mu != 0:
            assert(np.allclose(skew, 1/np.sqrt(mu)))
            assert(np.allclose(kurtosis, 1/mu))
        mu += 1e-3

"""

A poisson random variable with mean mu can be constructed as a sum of poisson random variables with mean of 1

Sum[i=1, mu] poisson_random_variable(mean=1)

If this is a continuous random variable, the sum becomes an integral

"""

def test_unity_generation():
    N = 11
    S = 1000
    for mu in range(N):
        x = []
        for i in range(S):
            p = 0
            for j in range(mu):
                p += poisson.rvs(1)
            x.append(p)
        assert(np.allclose(np.mean(x), mu, atol=1))

test_moments()
test_unity_generation()
