#!/usr/bin/env python3

"""

For a Poisson distribution with rate lambda, compute the probability of exactly k events:

P(X = k) = exp(-lambda * lambda^k) / factorial(k)

Also compute the probability of at most k events:

P(X <= k) = Sum[i=0, k] P(x=i)

Here, i is a possible event count and lam represents lambda.
Return a dictionary containing pmf and cdf as Python floats.

Examples
Input: lam = 3.0, k = 2

Output: {"pmf": 0.224042, "cdf": 0.42319}

Explanation: The CDF adds the probabilities for zero, one, and two events.

Input: lam = 2.5, k = 0

Output: {"pmf": 0.082085, "cdf": 0.082085}

Input: lam = 1.0, k = 1

Output: {"pmf": 0.367879, "cdf": 0.735759}

Hint 1
Initialize the zero-event probability with math.exp(-lam).

Hint 2
Advance from count i - 1 to i by multiplying the previous probability by lam / i.

Requirements
Start with the probability of zero events
Use the recurrence between consecutive Poisson probabilities
Accumulate probabilities through k for the CDF
Return exactly pmf and cdf in a dictionary of Python floats
Constraints
lam is positive
k is an integer between 0 and 50
Use the Python standard library only

"""

from math import *

def poisson(lam: float, k: int) -> float:
    return (exp(-lam) * lam**k) / factorial(k)

def poisson_pmf_cdf(lam: float, k: int) -> dict:
    pmf = poisson(lam, k)
    cdf = 0
    for i in range(k + 1):
        cdf += poisson(lam, i)
    return {
        "pmf": pmf,
        "cdf": cdf,
    }

def main():
    print(poisson_pmf_cdf(3, 2))
    print(poisson_pmf_cdf(2.5, 0))
    print(poisson_pmf_cdf(1, 1))

main()
