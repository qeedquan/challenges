#!/usr/bin/env Rscript

comments <- "

The square matrix is given. Find the inverse matrix.

Input
The first line contains the size of the matrix n (1≤n≤100). Each of the next n lines contains n real numbers — the data of the matrix.

Output
If the inverse matrix does not exist, print NO. Otherwise, print YES in the first line, and then print n lines with n real numbers in each — the inverse matrix. The answer is considered correct if the absolute or relative error of the elements of the inverse matrix is no more than 10^-6.

Examples
Input #1
2
0 1.0
1 0

Answer #1
YES
0.00000000000000000000 1.00000000000000000000
1.00000000000000000000 0.00000000000000000000

"

A <- matrix(c(0, 1, 1, 0), nrow = 2, ncol = 2)
A_inv <- solve(A)
print(A_inv)
