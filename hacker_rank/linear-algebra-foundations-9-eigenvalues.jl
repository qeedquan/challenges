#!/usr/bin/env julia

#=

Given the matrix  =

[0   1]
[-2 -3]

Compute the two eigenvalues of this matrix, and enter each of the two integers on a new line in the text box below, for submitting your answer.
Enter the smaller eigenvalue in the first line and the larger eigenvalue in the second line.

For example, your answer may look like:

-1
4

=#

using LinearAlgebra

M = [0 1; -2 -3]
println(eigvals(M))

