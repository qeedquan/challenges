#!/usr/bin/env python3

"""

A Hankel matrix is a square matrix in which each ascending skew-diagonal from left to right is constant, e.g.:

a b c d
b c d e
c d e f
d e f g

Given a sequence of integers {an}, we can construct a sequence of Hankel matrices {Hn}, where Hn is the n×n Hankel matrix whose (i,j) entry is a[i+j-1] (1-indexed).
The Hankel transform of {an} is defined as the sequence of determinants of the matrices {Hn}, i.e. {det(Hn)}.

For example, the fourth Hankel matrix of the Catalan numbers {1,1,2,5,14,42,132,…} is

H4

1 1 2 5
1 2 5 14
2 5 14 42
5 14 42 132

and the determinant of H1, H2, H3, and H4 are all 1. The Hankel transform of the Catalan numbers is therefore {1,1,1,1,…}.

Task
Given a finite sequence of integers {an}, output its Hankel transform {det(Hn)}.

The length of the input sequence is always an odd number. If the length of the input sequence is 2n−1, then the length of the output sequence should be n.

Input and output can be in any reasonable format, e.g., a list, an array, a polynomial, a function that takes i and returns the ith term (0-indexed or 1-indexed), etc.

You may also take the input sequence and an integer i, and output the ith term (0-indexed or 1-indexed) of the output sequence.

This is code-golf, so the shortest code in bytes wins.

Testcases
[1,1,2,3,5,8,13] -> [1,1,0,0]
[0,1,2,3,4,5,6,7,8] -> [0,-1,0,0,0]
[1,0,-1,0,1,0,-1,0,1] -> [1,-1,0,0,0]
[1,2,5,14,42,132,429,1430,4862] -> [1,1,1,1,1]
[1,2,5,15,51,188,731,2950,12235] -> [1,1,1,1,1]
[1,2,6,20,70,252,924,3432,12870] -> [1,2,4,8,16]
[1,1,2,4,10,26,76,232,764,2620,9496] -> [1,1,2,12,288,34560]

"""

import numpy as np

def hankel(a):
    r = []
    n = len(a)//2 + 1
    for s in range(1, n+1):
        m = np.eye(s)
        for i in range(s):
            for j in range(s):
                m[i][j] = a[i+j]
        r.append(round(np.linalg.det(m)))
    return r

def main():
    assert(hankel([1, 1, 2, 3, 5, 8, 13]) == [1, 1, 0, 0])
    assert(hankel([0, 1, 2, 3, 4, 5, 6, 7, 8]) == [0, -1, 0, 0, 0])
    assert(hankel([1, 0, -1, 0, 1, 0, -1, 0, 1]) == [1, -1, 0, 0, 0])
    assert(hankel([1, 2, 5, 14, 42, 132, 429, 1430, 4862]) == [1, 1, 1, 1, 1])
    assert(hankel([1, 2, 5, 15, 51, 188, 731, 2950, 12235]) == [1, 1, 1, 1, 1])
    assert(hankel([1, 2, 6, 20, 70, 252, 924, 3432, 12870]) == [1, 2, 4, 8, 16])
    assert(hankel([1, 1, 2, 4, 10, 26, 76, 232, 764, 2620, 9496]) == [1, 1, 2, 12, 288, 34560])

main()
