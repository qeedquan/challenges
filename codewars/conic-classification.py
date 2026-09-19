#!/usr/bin/env python3

"""

The conic curves may be obtained doing different sections of a cone and we may obtain the three principal groups: ellipse, hyperbola and parabola.

https://imgur.com/4NdOkgf

The circle is a special case of ellipses.

In mathematics all the conics may be represented by the following equation:

Ax^2 + Bxy + Cy^2 + Dx + Ey + F = 0

A, B, C, D, E and F are coefficients that may have different values in the real numeric field.

Hesse in the nineteenth century, introduced the use of the invariants, useful tool in order to classify the different conic curves.

The invariants M, N, and S are:

M = det([[2*A, B, D], [B, 2*C, E], [D, E, 2*F]])
N = det([[B, 2*A], [2*C, B]])
S = A + C

It may be proved that if the system of coordinates changes, for example moving the center of the system of coordinates or rotating the coordinates axes, or doing both things, the invariants will have the same value, even though the coefficients A, B, C, D, E, and F change.

The following chart shows how the values of M, N and S classify the gender of the conics and the special cases when the conics are degenerated (points or lines) or they are imaginary:

Elliptic:
N < 0
    M != 0
        M*S < 0 (Real Ellipse)
        M*S > 0 (Imaginary Ellipse)
    M = 0 (A pair of imginary lines with a real common point)

Hyperbolic:
N > 0
    M != 0 (Real hyperbola)
    M = 0 (A pair of intersecting lines)

Parabolic:
N = 0
    M != 0 (A real parabola)
    M = 0 (A pair of lines)
        D*2 - 4*A*F > 0 (Parallel lines)
        D*2 - 4*A*F = 0 (Coinciding lines)
        D*2 - 4*A*F < 0 (Imaginary lines)

The function classify_conic() will do this work. This function will receive the different coefficients of the conic equation and will output the result of the classification as a string

classify_conic(A, B, C, D, E, F) == result
Let's see some cases:

Case1
A = 1 , B = 1, C = 1, D = 2, E = 2, F = -4
classify_conic(A, B, C, D, E, F) == "A real ellipse"

Case2
A = 1 , B = 1, C = -1, D = 2, E = 2, F = 4
classify_conic(A, B, C, D, E, F) == "A real hyperbola"

Case3
A =1, B = 0, C = 0, D = 4; E = 4, F = 4
classify_conic(A, B, C, D, E, F) == "A real parabola"
Case1
A = 1 , B = 1, C = 1, D = 2, E = 2, F = -4
classifyConic(A, B, C, D, E, F) == "A real ellipse"

Case2
A = 1 , B = 1, C = -1, D = 2, E = 2, F = 4
classifyConic(A, B, C, D, E, F) == "A real hyperbola"

Case3
A =1, B = 0, C = 0, D = 4; E = 4, F = 4
classifyConic(A, B, C, D, E, F) == "A real parabola"
The graph showing the above three cases is the following:

https://imgur.com/nUE4mcM

The messages for the special cases, having degenerated or imaginary conics will be:

# For elliptic gender:
"An imaginary ellipse"
"A degenerated ellipse: One point"

# For hyperbolic gender:
"A degenerated hyperbola: two intersecting lines"

# For parabolic gender:
"A degenerated parabola: two parallel lines"
"A degenerated parabola: two coinciding lines"
"A degenerated parabola: two imaginary lines"
Enjoy it!! #Note:

The given coefficients A, B, C, D, E and F, (a, b, c, d, eandf` in Ruby) will be always integers.

In order to avoid precision problems, the determinant values of M and N should be obtained by the rule of Sarrus. (See: https://en.wikipedia.org/wiki/Rule_of_Sarrus)

"""

import numpy as np

def classify_conic(A, B, C, D, E, F):
    M = np.linalg.det(np.array([[2*A, B, D], [B, 2*C, E], [D, E, 2*F]]))
    N = np.linalg.det(np.array([[B, 2*A], [2*C, B]]))
    S = A + C
    I = D*D - 4*A*F

    if N < 0:
        if M == 0:
            return "A degenerated ellipse: One point"
        if M*S < 0:
            return "A real ellipse"
        if M*S > 0:
            return "An imaginary ellipse"
    
    if N > 0:
        if M != 0:
            return "A real hyperbola"
        return "A degenerated hyperbola: two intersecting lines"

    if M != 0:
        return "A real parabola"

    if I > 0:
        return "A degenerated parabola: two coinciding lines"
    if I < 0:
        return "A degenerated parabola: two imaginary lines"
    return "A degenerated parabola: two parallel lines"

def main():
    assert(classify_conic(1, 1, 1, 2, 2, -4) == "A real ellipse")
    assert(classify_conic(1, 1, -1, 2, 2, 4) == "A real hyperbola")
    assert(classify_conic(1, 0, 0, 4, 4, 4) == "A real parabola")
    assert(classify_conic(5, 0, 4, 0, 0, 0) == "A degenerated ellipse: One point")
    assert(classify_conic(19, 0, -7, 0, 0, 0) == "A degenerated hyperbola: two intersecting lines")
    assert(classify_conic(40, 0, 0, 0, 0, 50) == "A degenerated parabola: two imaginary lines")
    assert(classify_conic(1, 1, 1, 2, 2, 4) == "An imaginary ellipse")

main()
