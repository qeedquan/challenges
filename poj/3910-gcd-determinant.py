#!/usr/bin/env python3

"""

Description

We say that a set S = {x1, x2, ..., xn} is factor closed if for any xi ∈ S and any divisor d of xi we have d ∈ S. Let’s build a GCD matrix (S) = (sij), where sij = GCD(xi, xj) – the greatest common divisor of xi and xj. Given the factor closed set S, find the value of the determinant:

Dn =   |  gcd(x1, x1) gcd(x1, x2) ... |
       |  gcd(x2, x1) gcd(x2, x2) ... |
       |  ........................... |
       |  gcd(xn, x1) gcd(xn, x2) ... |

Input

The input file contains several test cases. Each test case starts with an integer n (0 < n < 1000), that stands for the cardinality of S. The next line contains the numbers of S: x1, x2, ..., xn. It is known that each xi is an integer, 0 < xi < 2*109. The input data set is correct and ends with an end of file.

Output

For each test case find and print the value Dn mod 1000000007.

Sample Input

2
1 2
3
1 3 9
4
1 2 3 6

Sample Output

1
12
4

Source

Southeastern European Regional Programming Contest 2008

"""

import numpy as np
from math import *

def gcddet(a):
    n = len(a)
    m = []
    for i in range(n):
        r = []
        for j in range(n):
            r.append(gcd(a[i], a[j]))
        m.append(r)
    return np.linalg.det(m) % 1000000007

def main():
    assert(gcddet([1, 2]) == 1)
    assert(gcddet([1, 3, 9]) == 12)
    assert(gcddet([1, 2, 3, 6]) == 4)

main()
