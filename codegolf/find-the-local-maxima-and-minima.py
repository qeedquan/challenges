#!/usr/bin/env python3

"""

Definition
The maxima and minima of a given function are the largest and smallest values of the function either within a given range or otherwise within the entire domain of the function.

Challenge
The challenge is to find the local maxima and minima of a given polynomial function using any method you may like. Don't worry, I will try my best to explain the challenge and keep it as simple as possible.

The input will contain all the coefficients of the single variable polynomial in either decreasing or increasing order of power (up to you). For example,

[3,-7,1] will represent 3x^2 - 7x + 1
[4,0,0,-3] will represent 4x^3 - 3
How To Solve Using Derivatives
Now, let's say our input is [1,-12,45,8], which is nothing but the function x^3 - 12x^2 + 45x + 8.

The first task is to find the derivative of that function. Since it is a polynomial function, so it is indeed a simple task to do.
The derivative of xn is n*x^(n-1).
Any constant terms present with xn are simply multiplied.
Also, if there are terms added/subtracted, then their derivatives are also added or subtracted respectively.
Remember, the derivative of any constant numerical value is zero. Here are a few examples:

x^3 -> 3x^2
9x^4 -> 9*4*x^3 = 36x^3
-5x^2 -> -5*2*x = -10x
2x^3 - 3x^2 + 7x -> 6x^2 - 6x + 7
4x^2 - 3 -> 8x - 0 = 8x
Now solve the equation by equating the new polynomial to zero and get only the integral values of x.

Put those values of x in the original function and return the results. That should be the output.

Example
Let us take the example we mentioned earlier, i.e, [1,-12,45,8].

Input: [1,-12,45,8]
Function: x^3 - 12x^2 + 45x + 8
Derivative: 3x^2 - 24x + 45 + 0 -> [3,−24,45]
Solving equation: 3x^2 - 24x + 45 = 0, we get x=3 and x=5.
Now putting x=3 and x=5 in the function, we get the values (62,58).
Output: [62,58]

Assumptions
Assume that all the input coefficients are integers. They can be in increasing or decreasing order of power.

Assume the input to be at least a 2-degree polynomial. If the polynomial has no integer solutions, you can return anything.

Assume that the final result will be integers only.

You can print the results in any order. The degree of the input polynomial would not be more than 5, so that your code can handle it.

The input will be valid so that the solutions of x are not saddle points.

Also, you are not forced to do it by the derivative method. You can use any method you feel like.

Sample Input And Output
[2,-8,0] -> (-8)
[2,3,-36,10] -> (91,-34)
[1,-8,22,-24,8] -> (-1,0,-1)
[1,0,0] -> (0)

Scoring
This is code-golf so the shortest code wins.

"""

import numpy as np

def saddle(a):
    n = len(a)
    p = []
    for i in range(n - 1):
        p.append(a[i] * (n-i-1))
    
    r = []
    for v in np.roots(p):
        r.append(np.polyval(a, v))
    return r

def main():
    assert(np.allclose(saddle([1, -12, 45, 8]), [58, 62]))
    assert(np.allclose(saddle([2, -8, 0]), [-8]))
    assert(np.allclose(saddle([2, 3, -36, 10]), [91, -34]))
    assert(np.allclose(saddle([1, -8, 22, -24, 8]), [-1, 0, -1]))
    assert(np.allclose(saddle([1, 0, 0]), [0]))

main()
