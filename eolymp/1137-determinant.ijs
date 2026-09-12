NB. Given an integer n×n matrix, compute its determinant.
NB.
NB. Input
NB. The first line contains a natural number n (n≤100).
NB. Each of the next n lines contains n integers, each with absolute value at most 1000000.
NB. The j-th number in the (i+1)-th line gives the j-th element of the i-th row of the matrix.
NB.
NB. Output
NB. Print the value of the determinant.
NB.
NB. Examples
NB. Input #1
NB. 2
NB. 2 1
NB. 3 2
NB. Answer #1
NB. 1

det =: - / . *

M1 =: 2 2 $ 2 1 3 2
M2 =: 3 3 $ 3 0 0 0 4 0 0 0 5

1!:2&2 det M1
1!:2&2 det M2

