#!/usr/bin/env python3

r"""

Define the (unnormalised) Willmore energy of a surface as the integral of squared mean curvature over it:

W = Integrate[Surface S] (H^2) dA

For surfaces topologically equivalent to a sphere W≥4π, and W=4π iff it is actually a sphere.
Thus the energy quantifies how spherical a surface is.

In September 2020 I asked on MathsSE how to simplify the Willmore energy of an ellipsoid with semi-major axes a≥b≥c≥0.
Two days later I had done it myself:

Define
A = a^2
B = b^2
C = c^2
phi = acos(c/a)
g = sqrt((A - C)*B)

m = ((B-C)*A) / ((A-B)*B) (WRONG)
// correction by @Rosario, should be
m = sqrt[ ((B-C)*A) / ((A-B)*B) ]

Then
W = pi/(3ABC) * [ C(5AB + 2AC + 2BC) + 
                  2(AB + AC + BC) * E(phi, m)*g + 
                  BC*(AB + AC + 2BC - A^2) * F(phi, m)/g

Here F and E are the elliptic integrals of the first and second kinds respectively.
(Note that as with all my elliptic integral/function answers on MathsSE the argument convention is as in Mathematica and mpmath, where m is the parameter.)
Later on I derived a much cleaner and order-agnostic formula in terms of Carlson's symmetric integrals – A,B,C keep their meanings

W = pi/3 * (3 + 4*(1/A + 1/B + 1/C)*Rg(AB, CA, BC) - (A + B + C)*Rf(AB, CA, BC))
I was inspired to write this question after writing answers to the ellipse perimeter and ellipsoid surface area questions that use the symmetric integrals.
In the former case it actually saves one byte over an answer using the classic formula.

Task
Given an ellipsoid's semi-axes a,b,c, which you may assume are sorted and positive, output the ellipsoid's Willmore energy with a relative error of at most 10−3.
You may use either formula above or something else entirely like explicitly integrating the squared mean curvature.

This is code-golf; fewest bytes wins.

Test cases
(1, 1, 1) 12.5663706143592
(2, 1, 1) 15.4516066443266
(2, 2, 1) 16.9023119660317
(3, 2, 1) 21.2244261324396
(2, 2, 2) 12.5663706143592
(6, 1, 1) 34.2162831541838
(6, 5, 1) 70.4793621781325
(13, 9, 6) 15.9643343585267

"""

from math import sin, cos, sqrt, pi
from scipy.integrate import dblquad
import numpy as np

def Rf(x, y, z):
    def f(phi, theta):
        st = sin(theta)
        sp = sin(phi)
        ct = cos(theta)
        cp = cos(phi)
        st2 = st * st
        sp2 = sp * sp
        ct2 = ct * ct
        cp2 = cp * cp
        return st / sqrt(x*st2*cp2 + y*st2*sp2 + z*ct2)
    r, _ = dblquad(f, 0, pi, 0, 2*pi)
    return r/(4*pi)

def Rg(x, y, z):
    def g(phi, theta):
        st = sin(theta)
        sp = sin(phi)
        cp = cos(phi)
        ct = cos(theta)
        st2 = st * st
        sp2 = sp * sp
        ct2 = ct * ct
        cp2 = cp * cp
        return sqrt(x*st2*cp2 + y*st2*sp2 + z*ct2) * st
    r, _ = dblquad(g, 0, pi, 0, 2*pi)
    return r/(4*pi)

"""

Use Carlson symmetric integral formulation
The Rg() and Rf() functions are defined at:
https://dlmf.nist.gov/19.23#E6_5

"""

def W(a, b, c):
    A = a**2
    B = b**2
    C = c**2
    X = 3 + 4*(1/A + 1/B + 1/C)*Rg(A*B, C*A, B*C)
    Y = (A + B + C) * Rf(A*B, C*A, B*C)
    return pi/3 * (X - Y)

def main():
    assert(np.allclose(W(1, 1, 1), 12.5663706143592))
    assert(np.allclose(W(2, 1, 1), 15.4516066443266))
    assert(np.allclose(W(2, 2, 1), 16.9023119660317))
    assert(np.allclose(W(3, 2, 1), 21.2244261324396))
    assert(np.allclose(W(2, 2, 2), 12.5663706143592))
    assert(np.allclose(W(6, 1, 1), 34.2162831541838))
    assert(np.allclose(W(6, 5, 1), 70.4793621781325))
    assert(np.allclose(W(13, 9, 6), 15.9643343585267))

main()
