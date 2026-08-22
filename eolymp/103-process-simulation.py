#!/usr/bin/env python3

"""

You are given a discrete evolution process. At each moment, the state of the process is described by parameters

x1 ,x2,…,xn.

x1[i+1] = a11*x1[i] + a12*x2[i] + a1n*xn[i]
xn[i+1] = an1*x1[i] + an2*x2[i] + ann*xn[i]

Find the state of the process at moment M. Each parameter should be computed modulo 100007.

Input
The first line contains T (1≤T≤100), the number of test cases.
Each test case begins with a line containing two integers: N (1≤N≤100), the number of parameters, and M (0≤M≤10^9), the moment in time.
Then N lines follow, each containing N integers separated by spaces.
The j-th integer in the i-th line is aij (0 ≤ aij ≤ 10^9). Then, one more line follows, containing N integers: the j-th integer is xj 0(0 ≤ xj[0] ≤ 10^9).

Output
Output T lines, each in the format Case #A: x1[M] x2[M] … xn[M], where A is the test case number (starting from 1), and x1[M],…,xn[M] are the required parameters for that test case.

Examples

Input #1
2
1 5
2
1
2 7
14 26
32 45
534 623

Answer #1
Case #1: 32
Case #2: 62813 87846

"""

import numpy as np

def solve(A, x, n):
    m = 100007
    A = np.linalg.matrix_power(A, n)
    y = np.dot(A, x) % m
    return y

def main():
    print(solve(np.array([[2]], dtype=object), np.array([1], dtype=object), 5))
    print(solve(np.array([[14, 26], [32, 45]], dtype=object), np.array([534, 623], dtype=object), 7))

main()
