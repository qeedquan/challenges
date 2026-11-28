#!/usr/bin/env python3

"""

Build the linear noise schedule of a diffusion model with num_steps timesteps and return its three per-step arrays.

B_t = B_start + t/(T - 1)*(B_end - B_start)
a_t = 1 - B_t
a_t_bar = prod(s=0, t) a[s]

Here T is num_steps, the timestep t runs from 0 to T-1, B_start is beta_start and B_end is beta_end.
The betas are evenly spaced, so the first one equals beta_start and the last one equals beta_end.
Each a_t is the fraction of variance kept at step t, each a_t_bar is the running product of all alphas up to and including step t.
When num_steps is 1 the schedule holds the single value beta_start.

Return a dict with exactly the keys "betas", "alphas" and "alpha_bars", where each value is a float64 NumPy array of shape (num_steps,) holding 
B_t, a_t, a_t_bar, in timestep order.

Examples
Input: num_steps = 5, beta_start = 0.1, beta_end = 0.5

Output: {"betas":[0.1,0.2,0.3,0.4,0.5],"alphas":[0.9,0.8,0.7,0.6,0.5],"alpha_bars":[0.9,0.72,0.504,0.3024,0.1512]}

Explanation: The five betas are evenly spaced from 0.1 to 0.5, each alpha is one minus its beta, and each alpha_bar multiplies the alphas so far, so alpha_bars[1] = 0.9 * 0.8 = 0.72.

Input: num_steps = 4, beta_start = 0.0001, beta_end = 0.02

Output: {"betas":[0.0001,0.006733,0.013367,0.02],"alphas":[0.9999,0.993267,0.986633,0.98],"alpha_bars":[0.9999,0.993167,0.979892,0.960294]}

Input: num_steps = 1, beta_start = 0.3, beta_end = 0.9

Output: {"betas":[0.3],"alphas":[0.7],"alpha_bars":[0.7]}

Hint 1
np.linspace(start, stop, num) includes both endpoints and returns just start when num is 1.

Hint 2
np.cumprod gives an inclusive running product.

Requirements
Use NumPy array operations.
Constraints
num_steps is a Python int between 1 and 1000.
beta_start and beta_end are Python floats with 0 < beta_start <= beta_end < 1.

"""

import numpy as np

def linear_beta_schedule(num_steps: int, beta_start: float, beta_end: float) -> dict:
    betas = []
    alphas = []
    alpha_bars = []
    alpha_bar = 1
    for t in range(num_steps):
        if num_steps > 1:
            betas.append(beta_start + t/(num_steps - 1)*(beta_end - beta_start))
        else:
            betas.append(beta_start)
        alphas.append(1 - betas[-1])
        alpha_bar *= alphas[-1]
        alpha_bars.append(alpha_bar)
    return {
        "betas": betas,
        "alphas": alphas,
        "alpha_bars": alpha_bars,
    }

print(linear_beta_schedule(5, 0.1, 0.5))
print(linear_beta_schedule(4, 0.0001, 0.02))
print(linear_beta_schedule(1, 0.3, 0.9))
