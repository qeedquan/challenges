#!/usr/bin/env python3

"""

Returns across multiple periods compound multiplicatively. Begin with a wealth factor of 1.0 and update it after each period:

W[t] = W[t-1]*(1 + r[t]
R[t] = W[t] - 1

Here, r_t is the return for period t, W_t is wealth relative to the starting value, and R_t is cumulative return. Return R_t after every period.

Examples
Input: returns = [0.1, 0.05, -0.02]

Output: [0.1, 0.155, 0.1319]

Explanation: The wealth factors become 1.1, 1.155, and 1.1319 after compounding.

Input: returns = [-0.5, 1.0]

Output: [-0.5, 0.0]

Hint 1
Maintain one running wealth value rather than adding returns.

Hint 2
Append wealth - 1 immediately after processing each return.

Requirements
Begin with a wealth factor of 1.0.
Multiply the running wealth by 1 + r for each period.
Append the running wealth minus 1 after every update.
Return a list with the same length as returns.
Constraints
returns is nonempty.
Every return is greater than -1.
Time limit: 300 ms.

"""

def cumulative_returns(returns: list) -> list:
    result = []
    wealth = 1
    for i in range(len(returns)):
        wealth *= (1 + returns[i])
        result.append(wealth - 1)
    return result

print(cumulative_returns([0.1, 0.05, -0.02]))
print(cumulative_returns([-0.5, 1.0]))
