#!/usr/bin/env python3

"""

Evaluate a Bernoulli distribution at each value in x:
P(X = x) = 1 - p     if x = 0
           p         if x = 1

Its mean and variance are:
mean = p
variance = p * (1 - p)

Here, p is the success probability.
Return a dictionary containing pmf as a NumPy array and mean and variance as Python floats.

Examples
Input: x = [0, 1, 1], p = 0.3

Output: {"pmf": [0.7, 0.3, 0.3], "mean": 0.3, "variance": 0.21}

Explanation: Failure has probability 0.7, success has probability 0.3, and the distribution moments depend only on p.

Input: x = [0, 1, 0, 1], p = 0.5

Output: {"pmf": [0.5, 0.5, 0.5, 0.5], "mean": 0.5, "variance": 0.25}

Input: x = [1], p = 0.8

Output: {"pmf": [0.8], "mean": 0.8, "variance": 0.16}

Hint 1
Use np.where(x == 1, p, 1.0 - p) for the PMF array.

Hint 2
Compute the variance with p * (1.0 - p).

Requirements
Evaluate the Bernoulli PMF for every value in x
Compute the distribution mean and variance
Return exactly pmf, mean, and variance in a dictionary
pmf must be a NumPy array and both moments must be Python floats
Constraints
x is a nonempty list containing only 0 and 1
p is between 0 and 1
Use NumPy only

"""

import numpy as np

def bernoulli_pmf_and_moments(x: list, p: float) -> dict:
    pmf = np.where(np.array(x) == 1, p, 1.0 - p)
    mean = p
    var = p * (1.0 - p)
    return {
        "pmf": pmf,
        "mean": mean,
        "variance": var,
    }

print(bernoulli_pmf_and_moments([0, 1, 1], 0.3))
print(bernoulli_pmf_and_moments([0, 1, 0, 1], 0.5))
print(bernoulli_pmf_and_moments([1], 0.8))
