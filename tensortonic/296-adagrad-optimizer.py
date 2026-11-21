#!/usr/bin/env python3

"""

Implement one AdaGrad update. First accumulate the elementwise squared gradient:

G[t] = G[t-1] + g[t]^2

Then update each parameter:

w[t] = w[t-1] - lr*g[t]/sqrt(G[t] + eps)

Here, w contains parameters, g contains the current gradients, G contains accumulated squared gradients, η is lr, and ε is eps.
Return a dictionary containing new_w and new_G, both as NumPy arrays.

Examples
Input: w = [1.0, 2.0], g = [0.1, -0.2], G = [0.0, 0.0], lr = 0.1, eps = 1e-8

Output: {"new_w": [0.9, 2.1], "new_G": [0.01, 0.04]}

Explanation: Squaring the gradient updates the accumulator, then each parameter uses its accumulator-adjusted step size.

Input: w = [1.0, 2.0], g = [0.0, 0.0], G = [0.1, 0.2], lr = 0.1, eps = 1e-8

Output: {"new_w": [1.0, 2.0], "new_G": [0.1, 0.2]}

Input: w = [0.0], g = [1.0], G = [100.0], lr = 0.1, eps = 1e-8

Output: {"new_w": [-0.00995], "new_G": [101.0]}

Hint 1
Compute new_G = G + g ** 2 before updating the parameters.

Hint 2
Use np.sqrt(new_G + eps) as the elementwise denominator.

Requirements
Apply the stated accumulator and parameter equations elementwise
Return exactly new_w and new_G in a dictionary
Both returned values must be NumPy arrays with the input shape
Constraints
w, g, and G have the same nonempty numeric shape
lr and eps are positive
Use NumPy only

"""

import numpy as np

def adagrad_step(w: list, g: list, G: list, lr: float = 0.01, eps: float = 1e-8) -> dict:
    w = np.array(w)
    G = np.array(G)
    g = np.array(g)
    new_G = G + np.square(g)
    new_w = w - lr*g/np.sqrt(new_G + eps)
    return {
        "new_w": new_w,
        "new_G": new_G,
    }

print(adagrad_step([1, 2], [0.1, -0.2], [0, 0], 0.1, 1e-8))
print(adagrad_step([1, 2], [0, 0], [0.1, 0.2], 0.1, 1e-8))
print(adagrad_step([0], [1], [100], 0.1, 1e-8))
