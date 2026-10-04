#!/usr/bin/env python3

"""

A sequence of integers ai is defined as follows:

a[i] = b[i]                                           for 1 <= i <= k
a[i] = c[1]*a[i-1] + c[2]*a[i-2] + ... + c[k]*a[i-k]  for i > k

where the sequences bj and cj (1≤j≤k) consist of given integer numbers.
Your task is to compute an for a given n and output the result modulo 10^9.

Input
The first line contains the integer t (1≤t≤10^4), the number of test cases.

Each test case consists of four lines:

The first line contains a single integer k (1≤k≤10) — the length of the sequences b and c.

The second line contains k integers b1,b2,…,bk(0≤bj≤10^9), the initial values of the sequence.

The third line contains k integers c1, c2, … ,ck (0≤cj≤10^9), the coefficients of the recurrence.

The fourth line contains a single integer n (1≤n≤10^9) — the required position in the sequence.

Output
For each test case, assert a single integer: the value of a n modulo 10^9.

Examples

Input
2
3
1 2 3
2 1 3
4
3
1 2 3
2 1 3
6

Answer
11
45 (wrong answer, should be 82)

Input #1
3
3
5 8 2
32 54 6
2
3
1 2 3
4 5 6
6
3
24 354 6
56 57 465
98765432

Answer #1
8
714
257599514

"""

import numpy as np

def recurrence(c):
    n = len(c)
    A = np.zeros((n, n), dtype=object)
    for i in range(n):
        A[n-1][i] = c[i]
    for i in range(n-1):
        A[i][i+1] = 1
    return A

def mul(X, Y, mod):
    n = len(X)
    R = np.zeros((n, n), dtype=object)
    for i in range(n):
        for j in range(n):
            for k in range(n):
                R[i][j] += X[i][k] * Y[k][j]
                R[i][j] %= mod
    return R

def powm(A, n, mod):
    X = np.eye(len(A), dtype=object)
    Y = A
    while n > 0:
        if n&1 != 0:
            X = mul(X, Y, mod)
        Y = mul(Y, Y, mod)
        n >>= 1
    return X

def solvebf(b, c, n):
    if n < 1:
        return 0
    if n < len(b):
        return b[n - 1]

    mod = 1_000_000_000
    c = c[::-1]
    x = b
    for i in range(n - len(b)):
        v = int(np.dot(x, c)) % mod
        x = x[1:] + [v]
    return x[-1]

"""

https://gciruelos.com/linear-recurrences.html
https://en.wikipedia.org/wiki/Companion_matrix

"""

def solve(b, c, n):
    if n < 1:
        return 0
    if n < len(b):
        return b[n - 1]

    mod = 1_000_000_000
    c = c[::-1]
    A = recurrence(c)
    A = powm(A, n - len(b), mod)
    x = np.dot(A, b)
    return x[-1]

def main():
    assert(solve([1, 2, 3], [2, 1, 3], 4) == 11)
    assert(solve([1, 2, 3], [2, 1, 3], 6) == 82)
    assert(solve([5, 8, 2], [32, 54, 6], 2) == 8)
    assert(solve([1, 2, 3], [4, 5, 6], 6) == 714)
    assert(solve([24, 354, 6], [56, 57, 465], 98765432))

main()

