#!/usr/bin/env julia

#=

Diagonalize a vector into a matrix.

Input
A vector, list, array, etc. of integers v of length n.

Output
A n×n matrix, 2D array, etc. A such that for each element ai∈v,

A = [a1 0 ... 0]
    [0 a2 ... 0]
    [0 0  ... an]

where the diagonal of A is each element in v.

Notes
This is code-golf, so shortest program or function in bytes wins!
Construct the Identity Matrix may be of use to you.
If the length of v is 0, you may return an empty vector, or an empty matrix.
If the length of v is 1, you must return a 1×1 matrix.
Not Bonus
You can receive this Not Bonus if your program is generic across any type, using the type's zero-value (if it exists) in place of 0.

Test Cases
[] -> []
[0] -> [[0]]
[1] -> [[1]]
[1, 2, 3] -> [[1, 0, 0], [0, 2, 0], [0, 0, 3]]
[1, 0, 2, 3] -> [[1, 0, 0, 0], [0, 0, 0, 0], [0, 0, 2, 0], [0, 0, 0, 3]]
[1, -9, 1, 3, 4, -4, -5, 6, 9, -10] -> [[1, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, -9, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 3, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 4, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, -4, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, -5, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 6, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 9, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, -10]]

=#

using LinearAlgebra

@assert(Diagonal([]) == Array{Float64}(undef, 0, 0))
@assert(Diagonal([0]) == [0;;])
@assert(Diagonal([1]) == [1;;])
@assert(Diagonal([1, 2, 3]) == [[1 0 0]; [0 2 0]; [0 0 3]])
@assert(Diagonal([1, 0, 2, 3]) == [[1 0 0 0]; [0 0 0 0]; [0 0 2 0]; [0 0 0 3]])
@assert(Diagonal([1, -9, 1, 3, 4, -4, -5, 6, 9, -10]) == [[1 0 0 0 0 0 0 0 0 0]; [0 -9 0 0 0 0 0 0 0 0]; [0 0 1 0 0 0 0 0 0 0]; [0 0 0 3 0 0 0 0 0 0]; [0 0 0 0 4 0 0 0 0 0]; [0 0 0 0 0 -4 0 0 0 0]; [0 0 0 0 0 0 -5 0 0 0]; [0 0 0 0 0 0 0 6 0 0]; [0 0 0 0 0 0 0 0 9 0]; [0 0 0 0 0 0 0 0 0 -10]])
