#!/usr/bin/env python3

"""

Given the value of a+b and ab you will have to find the value of a^n+b^n. a and b not necessarily have to be real numbers.

Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.

Each case contains three non-negative integers, p, q and n. Here p denotes the value of a+b and q denotes the value of ab. Each number in the input file fits in a signed 32-bit integer. There will be no such input so that you have to find the value of 00.

Output
For each test case, print the case number and (a^n + b^n) modulo 26^4.

Sample
Input	Output
2
10 16 2
7 12 3

Case 1: 68
Case 2: 91

"""

import numpy as np

def solve(p, q, n):
    mod = 2**64
    if n < 0:
        return 0
    if n == 0:
        return 2
    A = np.array([[p, -q], [1, 0]], dtype=object)
    A = np.linalg.matrix_power(A, n - 1)
    return (A[0][0]*p + A[0][1]*2) % mod

def main():
    assert(solve(10, 16, 2) == 68)
    assert(solve(7, 12, 3) == 91)

main()
