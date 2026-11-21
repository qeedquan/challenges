#!/usr/bin/env python3

"""

Compute the Wasserstein critic loss from raw critic scores:

L = 1/Nf*Sum(D(xfake)) - 1/Nr*Sum(D(xreal))

Here, D(x) is a raw critic score, Nf is the number of fake samples, and Nr is the number of real samples.
The two score arrays may have different lengths. Return the difference of their means as a Python float.

Examples
Input: real_scores = [2.0, 1.5, 3.0], fake_scores = [-1.0, 0.0, 0.5]

Output: -2.333333

Explanation: The fake-score mean is -0.166667 and the real-score mean is 2.166667.

Input: real_scores = [1.0, 2.0, 3.0], fake_scores = [2.0, 2.0, 2.0]

Output: 0.0

Input: real_scores = [0.0, 0.0], fake_scores = [1.0, 2.0, 3.0]

Output: 2.0

Hint 1
Use np.mean separately on the real and fake arrays.

Hint 2
Return float(mean_fake - mean_real).

Requirements
Compute the fake-score mean and real-score mean independently
Subtract the real mean from the fake mean
Return the result as a Python float
Constraints
real_scores and fake_scores are nonempty finite numeric lists
The two lists may have different lengths
Use raw scores without applying an activation
Use NumPy only

"""

import numpy as np

def wasserstein_critic_loss(real_scores: list, fake_scores: list) -> float:
    return np.mean(fake_scores) - np.mean(real_scores)

def main():
    print(wasserstein_critic_loss([2, 1.5, 3], [-1, 0, 0.5]))
    print(wasserstein_critic_loss([1, 2, 3], [2, 2, 2]))
    print(wasserstein_critic_loss([0, 0], [1, 2, 3]))

main()

