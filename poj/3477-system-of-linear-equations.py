#!/usr/bin/env python3

"""

Description

Solve the system of linear equations

http://poj.org/formula?tex=%5Cbegin%7Bpmatrix%7Da_%7B11%7D%26a_%7B12%7D%26%5Ccdots%26a_%7B1n%7D%5C%5Ca_%7B21%7D%26a_%7B22%7D%26%5Ccdots%26a_%7B2n%7D%5C%5C%5Cvdots%26%5Cvdots%26%5Cddots%26%5Cvdots%5C%5Ca_%7Bm1%7D%26a_%7Bm2%7D%26%5Ccdots%26a_%7Bmn%7D%5Cend%7Bpmatrix%7D%5Cbegin%7Bpmatrix%7Dx_1%5C%5Cx_2%5C%5C%5Cvdots%5C%5Cx_n%5Cend%7Bpmatrix%7D%3D%5Cbegin%7Bpmatrix%7Db_1%5C%5Cb_2%5C%5C%5Cvdots%5C%5Cb_m%5Cend%7Bpmatrix%7D&driver=1

subject to

xi ≥ 0, ∀i = 1, 2, …, n.

Input

The input in is the following format with 1 ≤ m, n ≤ 100.

m	n
a11	a12	…	a1n	b1
a21	a22	…	a2n	b2
…	…	…	…	…
am1	am2	…	amn	bm
All numbers except m and n are real numbers.

Output

If any solutions exist, output one of them in the following format.

x1
x2
…
xn
Otherwise declare that the system is inconsistent by printing “impossible”. An special checker program that admits an absolute error of 10−10 is used to verify your results.

Sample Input

2 3
1 1 0 36
-1 1 -1 4
Sample Output

16
20
0
Source

POJ Founder Monthly Contest – 2007.12.30, frkstyc

"""

import numpy as np

def solve(A, b):
    if len(A) == 0 or len(A[0]) == 0:
        return "impossible"
    
    r, c = len(A), len(A[0])
    x, y = min(r, c), max(r, c)
    
    A = np.pad(A, ((0, y-r), (0, y-c)))
    for i in range(x, y):
        A[i][i] = 1
    b = np.pad(b, (0, y-len(b)))
    
    try:
        return np.dot(np.linalg.inv(A), b)
    except:
        pass
    
    return "impossible"

def main():
    assert(np.allclose(solve(np.array([[1, 1, 0], [-1, 1, -1]]), np.array([36, 4])), np.array([16, 20, 0])))

main()
