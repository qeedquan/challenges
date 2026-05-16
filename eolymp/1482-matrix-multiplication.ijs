NB. Let two rectangular matrices A and B with dimensions m × n and n × q respectively be given:
NB.
NB. https://static.e-olymp.com/content/46/46dcacccf2e14306f62c1fd6da576a3c46a9de96.jpg
NB.
NB. Then the matrix C of dimensions m × q is called their product:
NB.
NB. https://static.e-olymp.com/content/da/da99eabd3e6f853ae277048750d0bc336087756f.jpg
NB.
NB. where:
NB.
NB. https://static.e-olymp.com/content/28/284b55eccc48f0b6cbb7edfa694d35b5bddca20a.jpg
NB.
NB. Multiplication of two matrices is possible only if the number of columns in the first matrix equals the number of rows in the second; in this case, the matrices are said to be conformable.
NB.
NB. Two matrices A and B are given. Find their product.
NB.
NB. Input
NB. The first line contains two positive integers n_a and m_a — the dimensions of matrix A.
NB. Each of the next n_a rows contains m_a integers — the elements a_ij of matrix A.
NB. The (n_a+2)-n_d line contains two positive integers n_b and m_b — the dimensions of matrix B.
NB. The next n_b lines each contain m_b integers — the elements bij of matrix B.
NB. Matrix dimensions do not exceed 100×100, and all matrix elements are integers with absolute value at most 100.
NB.
NB. Output
NB. Print the dimensions of the resulting matrix C: n_c and m_c in the first line. In each of the next n_c lines, print m_c
NB. integers separated by spaces — the corresponding elements cij of matrix C.
NB. If matrix multiplication is not possible, print -1 in the first and only line.
NB.
NB. Examples
NB. Input #1
NB. 2 3
NB. 1 3 4
NB. 5 -2 3
NB. 3 3
NB. 1 3 2
NB. 2 1 3
NB. 0 -1 1
NB. Answer #1
NB. 2 3
NB. 7 2 15
NB. 1 10 7
NB. Input #2
NB. 2 3
NB. 10 12 31
NB. 23 11 17
NB. 3 4
NB. 0 2 1 4
NB. 3 9 2 4
NB. -5 4 2 5
NB. Answer #2
NB. 2 4
NB. -119 252 96 243
NB. -52 213 79 221

mul =: +/ . *

A1 =: 2 3 $ 1 3 4 5 _2 3
B1 =: 3 3 $ 1 3 2 2 1 3 0 _1 1

A2 =: 2 3 $ 10 12 31 23 11 17
B2 =: 3 4 $ 0 2 1 4 3 9 2 4 _5 4 2 5

1!:2&2 A1 mul B1
1!:2&2 A2 mul B2

