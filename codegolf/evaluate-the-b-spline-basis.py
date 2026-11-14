#!/usr/bin/env python3

"""

B-splines are defined using a set of "knots", "control points", and degree. For the purposes of this challenge, the control points are not needed.

The knots are simply a list of strictly increasing real values (note that real B-splines may have repeated knots, for the purposes of this challenge assume knots are all unique). The degree is a non-negative integer.

The set of polynomial basis functions are recursively defined as (image credit):

N[i, 0] = 1 if u[i] <= u < u[i+1]
          0 otherwise

N[i, p](u) = N[i, p-1](u)*(u-u[i])/(u[i+p]-u[i]) + N[i+1,p-1](u)*(u[i+p+1]-u)/(u[i+p+1]-u[i+1])

where i is the i-th basis function, and p is the degree of the basis function. u is the curve parameterization, and u_j is the j'th knot.

The goal of this challenge is to evaluate all the basis functions for a curve of degree m at location u.

Input
Your program/function should take as input 3 parameters:

A real value for the location u
A non-negative integer for the curve degree m
A list of strictly increasing real values for the knots vector u_j
You may take these parameters in any order desired and may mutate the inputs as long as no additional information is added (for example, you may take the knots vector to be a combination of a real pointer and integer length).

The input may come from any source desired (stdio, function parameter, etc.).

You may assume the input describes a valid B-spline and that u is in the range of the knots vector.

Output
Your program/function should output a list of real numbers describing what the basis functions evaluate to. That is, you should output enter image description here for all 0 <= i <= n-1-m, where n is the number of knots (For 1-based indexing, then 1 <= i <= n - m). The output must be accurate to within 1% or 1000 ULP of the true value, whichever is greater. The output may be to any sink desired (stdout, return value, etc.)

Examples
All examples are formatted as such:

u
m
u_0 u_1 u_2 ...
N_{0,m}(u) N_{1,m}(u) N_{2,m}(u) ...
case 1:

.5
0
0 0.5 1
0 1
case 2:

.5
1
-1 0 1 2
0.5 0.5
case 3:

 0.9
 1
 -1 0 1 2 3
 0.1 0.9 0
case 4:

 1.1
 1
 -1 0 1 2 3
 0 0.9 0.1
case 7:

 3
 3
 -1 0 1 2 3 8 10 12 15 20
 0 0.5952381 0.38392857 0.02083333 0 0

Hints
Notice that N_{p} depends only on N_{p-1}. That means rather than recursing from the top-down, you could start at the base case and work up. While this is faster execution-wise, I'm not sure if this will necessarily produce the shortest code.

Here's a reference implementation using Python3+NumPy for the bottom-up approach:

from numpy import *

def basis(knots, m, u):
    # base case
    Ns = 1.*logical_and(knots[:-1] <= u, u < knots[1:])
    # work backwards, starting at the base case up to p=m
    for p in range(1,m+1):
        Ns = (u - knots[:-1-p]) * Ns[:-1] / (knots[p:-1] - knots[:-p-1]) \
             + (knots[p+1:] - u) * Ns[1:] / (knots[p+1:]- knots[1:-p])
    return Ns

Scoring
This is code golf; shortest answer in bytes wins. Standard loopholes are prohibited. You are welcome to use any built-ins desired.

"""

import numpy as np

def basis(K, m, u):
    N = 1.0 * np.logical_and(K[:-1] <= u, u < K[1:])
    for p in range(1, m + 1):
        N = (u-K[:-1-p])*N[:-1]/(K[p:-1]-K[:-p-1]) + (K[p+1:]-u)*N[1:]/(K[p+1:]-K[1:-p])
    return N

def test(K, m, u, R):
    assert(np.allclose(basis(np.array(K), m, u), R))

def main():
    test([0, 0.5, 1], 0, 0.5, [0, 1])
    test([-1, 0, 1, 2], 1, 0.5, [0.5, 0.5])
    test([-1, 0, 1, 2, 3], 1, 0.9, [0.1, 0.9, 0])
    test([-1, 0, 1, 2, 3], 1, 1.1, [0, 0.9, 0.1])
    test([-1, 0, 1, 2, 3, 8, 10, 12, 15, 20], 3, 3, [0, 0.5952381, 0.38392857, 0.02083333, 0, 0])

main()
