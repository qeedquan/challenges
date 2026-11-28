#!/usr/bin/env python3

"""

Mix root priors with a supplied Dirichlet noise sample. Priors and noise are nonnegative NumPy weight arrays, not necessarily normalized; legal_mask is a Boolean NumPy array.
For each legal action a,

P'[a] = (1 - e)*P[a] + e*n[a]

Here, P'[a] is the mixed prior, e is the epsilon and P' and n' are priors and noise normalized separately over legal actions.
Illegal actions receive exactly zero. Use the supplied noise without sampling new values.
Return a new NumPy float64 array with the same shape and action order as priors.

Examples
Input: priors = [2,1,0], noise = [0,3,4], legal_mask = [true,true,false], epsilon = 0.25

Output: [0.5,0.5,0]

Explanation: Priors and noise are normalized over the first two actions before the 75 to 25 mixture.

Input: priors = [1,3,5], noise = [4,0,96], legal_mask = [true,true,false], epsilon = 1

Output: [1,0,0]

Input: priors = [10,0,2], noise = [7,8,5], legal_mask = [false,false,true], epsilon = 0.6

Output: [0,0,1]

Hint 1
Boolean indexing isolates the legal weights before summing.

Hint 2
np.zeros can hold the full action array while legal entries are filled.

Requirements
Use NumPy and return float64 values.
Keep illegal probabilities at exact zero.
Leave priors, noise, and legal_mask unchanged.
Constraints
Priors, noise weights, and the legal mask are aligned, nonempty one-dimensional arrays.
Priors and noise weights are finite and nonnegative, with positive mass on legal actions.
The legal mask contains at least one legal action.
The noise fraction lies between 0 and 1.

"""

import numpy as np

def mix_root_dirichlet_noise(
    priors: np.ndarray,
    noise: np.ndarray,
    legal_mask: np.ndarray,
    epsilon: float,
) -> np.ndarray:
    total_prior = 0
    total_noise = 0
    for i in range(len(priors)):
        if legal_mask[i]:
            total_prior += priors[i]
            total_noise += noise[i]

    result = []
    for i in range(len(priors)):
        value = 0
        if legal_mask[i]:
            value = (1 - epsilon)*(priors[i]/total_prior) + epsilon*(noise[i]/total_noise)
        result.append(value)
    return np.array(result)

print(mix_root_dirichlet_noise([2, 1, 0], [0, 3, 4], [True, True, False], 0.25))
print(mix_root_dirichlet_noise([1, 3, 5], [4, 0, 96], [True, True, False], 1))
print(mix_root_dirichlet_noise([10, 0, 2], [7, 8, 5], [False, False, True], 0.6))
