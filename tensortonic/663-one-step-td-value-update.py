#!/usr/bin/env python3

"""

Apply one TD(0) update to a state-value array. First compute the temporal-difference error:

δ = r + γV(s_next) - V(s)

Then update only the current state:

V_new(s) = V(s) + αδ

Here, r is the observed reward, γ is the discount factor, and α is the learning rate.
Do not modify the input. Return the updated values as a NumPy array.

Examples
Input: V = [0, 0, 0], s = 0, r = 1, s_next = 1, alpha = 0.5, gamma = 0.9

Output: [0.5, 0, 0]

Explanation: The next-state estimate is zero, so the TD target is 1 and the halfway update sets V(0) to 0.5.

Input: V = [0.2, 0.8], s = 0, r = 0, s_next = 1, alpha = 1.0, gamma = 0.5

Output: [0.4, 0.8]

Hint 1
Compute target = r + gamma * values[s_next].

Hint 2
Copy with np.asarray(V, dtype=float).copy() before updating index s.

Requirements
Compute the TD target from the reward and next-state value
Update only the current-state entry
Leave the input value array unchanged
Return a NumPy array
Constraints
State indices are valid for V
0 < alpha <= 1 and 0 <= gamma <= 1
Use NumPy only

"""

import numpy as np

def td_value_update(V: list, s: int, r: float, s_next: int, alpha: float, gamma: float) -> np.ndarray:
    delta = r + gamma*V[s_next] - V[s]
    V[s] += alpha*delta
    return V

print(td_value_update([0, 0, 0], 0, 1, 1, 0.5, 0.9))
print(td_value_update([0.2, 0.8], 0, 0, 1, 1.0, 0.5))
