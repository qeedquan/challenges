#!/usr/bin/env python3

"""

Description

Given a base b and two non-negative base b integers p and m, compute p mod m and print the result as a base b integer. p mod m is defined as the smallest non-negative integer k such that p = a*m + k for some integer a.

Input

Input consists of a number of cases. Each case is represented by a line containing three unsigned integers. The first, b, is a decimal number between 2 and 10. The second, p, contains up to 1000 digits between 0 and b-1. The third, m, contains up to 9 digits between 0 and b-1. The last case is followed by a line containing 0.

Output

For each test case, print a line giving p mod m as a base-b integer.

Sample Input

2 1100 101
10 123456789123456789123456789 1000
0

Sample Output

10
789

Source

Waterloo local 2003.09.20

"""

import numpy as np

def remb(b, p, m):
    x = int(str(p), b)
    y = int(str(m), b)
    return int(np.base_repr(x%y, b))

def main():
    assert(remb(2, 1100, 101) == 10)
    assert(remb(10, 123456789123456789123456789, 1000) == 789)

main()
