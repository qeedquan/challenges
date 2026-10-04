#!/usr/bin/env python3

"""

Given a state-space matrix, we can convert to a transfer function representation using this formula:

H(s) = C*(s*I - A)^-1*B' + D

B' is a column vector (transpose of a row vector)

In sympy we transpose C because the matrix construction makes a column vector by default

"""

from sympy import *
import numpy as np

def ss2tf(A, B, C, D):
    n = A.shape[0]
    s = Symbol('s')
    I = eye(n)
    E = (s*I - A).inv()
    return simplify(C*E*B + D)

"""

Mass-Spring-Damper system

If these values are constants, it leads to the transfer function of the form:

1/(m*s^2 + b*s + k)

"""
m = 1
k = 1
b = 0.2
F = 1

A = Matrix([[0, 1], [-k/m, -b/m]])
B = Matrix([0, 1/m])
C = Transpose(Matrix([1, 0]))
D = Matrix([0])
print(ss2tf(A, B, C, D))

"""

RLC circuit

I(s)/V(s) = H(s)

Transfer function:
s / (L*s^2 + R*s + 1/C)

"""
xR = Symbol('R')
xL = Symbol('L')
xC = Symbol('C')

A = Matrix([[0, 1], [-1/(xL*xC), -xR/xL]])
B = Matrix([0, 1/xL])
C = Transpose(Matrix([0, 1]))
D = Matrix([0])
print(ss2tf(A, B, C, D))
