#!/usr/bin/env julia

#=

Given the matrix  =

[0   1]
[-2 -3]

The two Eigenvectors of this matrix are computed as:

v1 = k1 [+1 A]^T and 
v2 = k2 [+1 B]^T

Also, A < B
In the text box, enter the two integers A and B, each on a new line.

=#

using LinearAlgebra;

A = [0 1; -2 -3]
V = eigvecs(A)
v1 = V[:, 1] / V[1, 1]
v2 = V[:, 2] / V[1, 2]
println(v1[2])
println(v2[2])

