#!/usr/bin/env python3

"""

A linear Diophantine equation in two variables is an equation of the form ax + by = c, where a, b and c are constant integers and x and y are integer variables.

For many naturally occurring Diophantine equations, x and y represent quantities that cannot be negative.

Task
Write a program or function that accepts the coefficients a, b and c as input and returns an arbitrary pair of natural numbers (0, 1, 2, …) x and y that verify the equation ax + by = c, if such a pair exists.

Additional rules
You can choose any format for input and output that involves only the desired integers and, optionally, array/list/matrix/tuple/vector notation of your language, as long as you don't embed any code in the input.

You may assume that the coefficients a and b are both non-zero.

Your code must work for any triplet of integers between -260 and 260; it must finish in under a minute on my machine (Intel i7-3770, 16 GiB RAM).

You may not use any built-ins that solve Diophantine equations and thus trivialize this task, such as Mathematica's FindInstance or FrobeniusSolve.

Your code may behave however you want if no solution can be found, as long as it complies with the time limit and its output cannot be confused with a valid solution.

Standard code-golf rules apply.

Examples
The examples below illustrate valid I/O for the equation 2x + 3y = 11, which has exactly two valid solutions ( (x,y) = (4,1) and (x,y) = (1,3) ).

Input:  2 3 11
Output: [4 1]

Input:  (11 (2,3))
Output: [3],(1)
The only valid solution of 2x + 3y = 2 is the pair (x,y) = (1,0).

The examples below illustrate valid I/O for the equation 2x + 3y = 1, which has no valid solutions.

Input:  (2 3 1)
Output: []

Input:  1 2 3
Output: -1

Input:  [[2], [3], [1]]
Output: (2, -1)
For (a, b, c) = (1152921504606846883, -576460752303423433, 1), all correct solutions (x,y) satisfy that (x,y) = (135637824071393749 - bn, 271275648142787502 + an) for some non-negative integer n.

"""

from sympy import symbols
from sympy.solvers.diophantine import diophantine

def solve(a, b, c):
    x, y = symbols('x y', integer=True, positive=True)
    return diophantine(a*x + b*y - c)

def main():
    print(solve(2, 3, 11))
    print(solve(2, 3, 2))
    print(solve(1, 2, 3))
    print(solve(1152921504606846883, -576460752303423433, 1))

main()
