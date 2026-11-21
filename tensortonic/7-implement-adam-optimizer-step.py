#!/usr/bin/env python3

"""

Implement one update step of the Adam optimizer.
Given current parameter(s), gradient(s), and running first/second moments,
return the updated parameter(s) and updated moments.

Step 1: Update First Moment
m[t] = B_1*m[t-1] + (1 - B_1)*g[t]

Step 2: Update Second Moment
v[t] = B_2*v[t-1] + (1 - B_2)*g[t]^2

Step 3: Bias Correction
m'[t] = m[t] / (1 - B[t]_1)

v'[t] = v[t] / (1 - B[t]_2)

Step 4: Parameter Update
p[t] = p[t-1] - lr*m'[t]/(sqrt(v'[t] + eps)

Examples
Input: param = [1.0, 2.0], grad = [0.0, 0.0], m = [0.0, 0.0], v = [0.0, 0.0], t = 1, lr = 0.001

Output: ([1.0, 2.0], [0.0, 0.0], [0.0, 0.0])

Explanation: A zero gradient leaves the parameters and both running moments unchanged.

Input: param = [0.0], grad = [0.1], m = [0.0], v = [0.0], t = 1, lr = 0.001

Output: ([-0.001], [0.01], [0.00001])

Hint 1
Update the first and second moments before computing their bias-corrected values.

Hint 2
Use the one-based timestep in bias correction and add eps inside the update denominator.

Requirements
param, grad, m, and v are Python lists with matching shapes
Perform all elementwise calculations with NumPy
Apply bias correction using the provided one-based timestep t
Return (param_new, m_new, v_new) as NumPy arrays with the corresponding input shapes
Do not use an external machine learning library
Constraints
Inputs up to shape ~ (10⁵)
Time limit: 500 ms; Memory: 128 MB
Allowed library: NumPy only

"""

import numpy as np

def adam_step(
    param: list,
    grad: list,
    m: list,
    v: list,
    t: int,
    lr: float = 1e-3,
    beta1: float = 0.9,
    beta2: float = 0.999,
    eps: float = 1e-8,
) -> tuple[np.ndarray, np.ndarray, np.ndarray]:
    m_new = beta1*m + (1 - beta1)*grad
    v_new = beta2*v + (1 - beta2)*grad**2
    mp = m_new / (1 - beta1)
    vp = v_new / (1 - beta2)
    param_new = param - lr*(mp/np.sqrt(vp + eps))
    return (param_new, m_new, v_new)

print(adam_step(
    param=np.array([1.0, 2.0]),
    grad=np.array([0.0, 0.0]),
    m=np.array([0.0, 0.0]),
    v=np.array([0.0, 0.0]),
    t=1,
    lr=0.001
))

print(adam_step(
    param=np.array([0.0]),
    grad=np.array([0.1]),
    m=np.array([0.0]),
    v=np.array([0.0]),
    t=1,
    lr=0.001
))
