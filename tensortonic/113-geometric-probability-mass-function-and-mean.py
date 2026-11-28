#!/usr/bin/env python3

"""

A Geometric random variable X counts the number of trials needed to obtain the first success.
Evaluate its PMF at every value in k:

P(X = k) = (1-p)^(k-1) * p

Its expected number of trials is:

E[x] = 1/p


Here, p is the success probability and every k is a positive integer.
Return a dictionary containing pmf as a NumPy array and mean as a Python float.

Examples
Input: k = [1, 2, 3], p = 0.2

Output: {"pmf": [0.2, 0.16, 0.128], "mean": 5.0}

Explanation: Each additional failure multiplies the next PMF value by 0.8, while the expected waiting time is 1 divided by 0.2.

Input: k = [1], p = 0.5

Output: {"pmf": [0.5], "mean": 2.0}

Hint 1
Use (1.0 - p) ** (k - 1) * p for the vectorized PMF.

Hint 2
The distribution mean is 1.0 / p.

Requirements
Evaluate the Geometric PMF for every value in k
Compute the distribution mean
Return exactly pmf and mean in a dictionary
pmf must be a NumPy array and mean must be a Python float
Constraints
k is a nonempty list of positive integers
p is greater than 0 and at most 1
Use NumPy only

"""

def geometric_pmf_mean(k, p):
    pmf = []
    for k in k:
        pmf.append((1-p)**(k-1) * p)

    return {
        "pmf": pmf,
        "mean": 1/p,
    }

def main():
    print(geometric_pmf_mean([1, 2, 3], 0.2))
    print(geometric_pmf_mean([1], 0.5))

main()
