#!/usr/bin/env julia

#=

Given matrix A. Transpose it.

Let B be the transposed matrix A. Then B[i, j] = A[j, i].

1 2   1 3 5
3 4 = 2 4 6
5 6

Input
The first line contains the size of the matrix n and m (1≤n,m≤100). Each of the next n lines contains m integers and describe the matrix A.

Output
Print the transposed matrix A: m lines, each with n integers.

Examples

Input #1
3 2
1 2
3 4
5 6

Answer #1
1 3 5
2 4 6

=#

M = [[1 2]; [3 4]; [5 6]]
println(M')
