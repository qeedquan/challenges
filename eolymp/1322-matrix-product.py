#!/usr/bin/env python3

"""

Given three square matrices A, B, C, each of size n×n. Check whether A × B = C.

Input
Each test case starts with an integer n (n≤500).
Then three matrices A, B, C are given, each described by n lines containing exactly n integers.
Elements of matrices A and B do not exceed 1000 in absolute value.
The last test case contains n=0 and should not be processed.
For example, in the first test case you should check the equality

Output
For each test case, output "YES" or "NO" on a separate line, depending on whether A × B = C holds or not.

Examples
Input #1
2
1 2
3 4
1 3
2 3
5 9
11 21
2
1 2
3 4
1 3
2 3
5 9
10 21
0

Answer #1
YES
NO

"""

import numpy as np

def verify(A, B, C):
    if np.allclose(np.dot(A, B), C):
        return "YES"
    return "NO"

def main():
    A1 = np.array([[1, 2], [3, 4]], dtype=int)
    B1 = np.array([[1, 3], [2, 3]], dtype=int)
    C1 = np.array([[5, 9], [11, 21]], dtype=int)
    C2 = np.array([[5, 9], [10, 21]], dtype=int)
    
    assert(verify(A1, B1, C1) == "YES")
    assert(verify(A1, B1, C2) == "NO")

main()
