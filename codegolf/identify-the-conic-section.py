#!/usr/bin/env python3

"""

Given 5 distinct points on a two-dimensional plane, determine the type of conic section formed by the points. The output shall be one of circle, hyperbola, ellipse, or parabola.

Rules
The points will be in general linear position, meaning that no three points are collinear, and thus the conic passing through them will be unique.
The coordinates of the 5 points will be decimal numbers between -10 and 10, inclusive.
The precision for the decimal/float values should be the precision of your language's native float/decimal type. If your language/data type is arbitrary-precision, you may use 12 digits after the decimal point as the maximum required precision, rounding toward zero (e.g. 1.0000000000005 == 1.000000000000).
Capitalization of the output does not matter.
Outputting ellipse when the conic section is actually a circle is not allowed. All circles are ellipses, but you must output the most specific one.
On floating point inaccuracies and precision:

I'm trying to make this as simple as possible, so that issues with floating point inaccuracies don't get in the way. The goal is, if the data type was "magical infinite precision value" instead of float/double, then everything would work perfectly. But, since "magical infinite precision value" doesn't exist, you write code that assumes that your values are infinite precision, and any issues that crop up as a result of floating point inaccuracies are features, not bugs.

Test Cases
(0, 0), (1, 5), (2, 3), (4, 8), (9, 2) => hyperbola
(1.2, 5.3), (4.1, 5.6), (9.1, 2.5), (0, 1), (4.2, 0) => ellipse
(5, 0), (4, 3), (3, 4), (0, 5), (0, -5) => circle
(1, 0), (0, 1), (2, 1), (3, 4), (4, 9) => parabola

"""

import numpy as np
from scipy.linalg import null_space

"""

@edc65

References: General form of a conic, Five points determine a conic, System of linear equations, Determinant
https://en.wikipedia.org/wiki/Conic_section
https://en.wikipedia.org/wiki/Five_points_determine_a_conic
https://en.wikipedia.org/wiki/System_of_linear_equations
https://en.wikipedia.org/wiki/Determinant
https://math.stackexchange.com/questions/3435466/5-points-determine-uniquely-a-conic

The equation of a conic section is:
A*x*x + B*x*y + C*y*y + D*x + E*y + F = 0

having A or B or C not equal to 0 (otherwise it's a straight line)

A ... F are six unknowns to be found. With five pairs of (x,y) we can build a linear system with five equations, and scaling remove one dimension. That is, we can set one of A,B or C to 1 if it's not 0 (and we know that at least one is not 0).

I build and try to solve 3 systems: first trying A=1. If not solvable then B=1, then C. (There could be a better way, but that's my best at the time)

Having the values of A,B,C we can classify the conic looking at the discriminant d=B*B-4*A*C

d == 0 -> parabola
d > 0 -> hyperbola
d < 0 -> ellipse, particularly (A == C and B == 0) -> circle

Use a different construction than @edc65 solution to solve for the (A, B, C, D, E, F) coefficients.
If we use homogeneous coordinates, we can represent the 5 points equation as a 5x6 matrix (rectangular matrix):

M = [x1**2, x1*y1, y1**2, x1, y1, 1]
    [x2**2, x2*y2, y2**2, x2, y2, 1]
    [x3**2, x3*y3, y3**2, x3, y3, 1]
    [x4**2, x4*y4, y4**2, x4, y4, 1]
    [x5**2, x5*y5, y5**2, x5, y5, 1]

If we solve the equation:
Mx = 0 (null space of the matrix M)

We can recover the coefficients (A, B, C, D, E, F) to determine the shape.

With M being a rectangular matrix, we also need to check if the rank of the matrix M is 5.
This constraint forces the solution to be a unique conic.

"""

def identify(p1, p2, p3, p4, p5):
    eps = 1e-14

    x1, y1 = p1[0], p1[1]
    x2, y2 = p2[0], p2[1]
    x3, y3 = p3[0], p3[1]
    x4, y4 = p4[0], p4[1]
    x5, y5 = p5[0], p5[1]

    M = np.array([
        [x1**2, x1*y1, y1**2, x1, y1, 1],
        [x2**2, x2*y2, y2**2, x2, y2, 1],
        [x3**2, x3*y3, y3**2, x3, y3, 1],
        [x4**2, x4*y4, y4**2, x4, y4, 1],
        [x5**2, x5*y5, y5**2, x5, y5, 1],
    ])
    if np.linalg.matrix_rank(M) != 5:
        return "unknown"

    K = null_space(M)
    
    A, B, C, D, E, F = K.flatten()
    
    det = B**2 - 4*A*C
    if np.allclose(det, 0, atol=eps):
        return "parabola"
    if det > 0:
        return "hyperbola"
    if np.allclose(A, C, atol=eps) and np.allclose(B, 0, atol=eps):
        return "circle"
    return "ellipse"

def main():
    assert(identify((0, 0), (1, 5), (2, 3), (4, 8), (9, 2)) == "hyperbola")
    assert(identify((1.2, 5.3), (4.1, 5.6), (9.1, 2.5), (0, 1), (4.2, 0)) == "ellipse")
    assert(identify((5, 0), (4, 3), (3, 4), (0, 5), (0, -5)) == "circle")
    assert(identify((1, 0), (0, 1), (2, 1), (3, 4), (4, 9)) == "parabola")

main()
