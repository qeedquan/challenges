#!/usr/bin/env python3

"""

The quantum fourier transform matrix is a NxN square matrix that is unitary.
It is defined for all positive integer N.
For phase estimation, only matrices of the order 2^N are considered, but we can calculate it for any positive integer.

QFT[N] = 1/sqrt(N) * MATRIX
MATRIX = NxN matrix where the entries are: M[y][x] = exp(2*pi*i/N)**(x*y)

Since it is a unitary matrix:
QFT^-1 = QFT* (complex conjugate transpose)

"""

from sympy import Matrix, I, zeros, eye, exp, cos, sqrt, pi, init_printing, pprint, simplify, factor, MatMul, lambdify
import numpy as np

def qft(N):
    M = eye(N)
    for y in range(N):
        for x in range(N):
            w = exp(2*pi*I/N)**(x*y)
            w = w.rewrite(cos)
            M[y, x] = w
    return MatMul(1/sqrt(N), M, evaluate=False)

def main():
    init_printing()
    for i in range(1, 11):
        Q = qft(i)
        
        # To get the complex conjugate, use M.H 
        # Should give identity matrix
        M = Matrix(Q)
        X = lambdify([], M, modules='numpy')()
        Y = lambdify([], M.H, modules='numpy')()
        assert(np.allclose(np.dot(X, Y), np.eye(i)))

        print(i)
        pprint(Q)
        print()

main()
