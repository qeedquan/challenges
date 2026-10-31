#!/usr/bin/env python3

"""

Description

Given a polynomial Sum[k=0, n] a[k]*x^k and a number t, please convert it into an equivalent polynomial in the form of Sum[k=0, n] b[k]*(x-t)^k.

Input

The input contains several test cases.
The first line of each test case gives two integer n (1 < n ≤ 200) and t (-10 ≤ t ≤ 10). The following line is a sequence of n integer a0,a1, ... ,an (-1000 ≤ ai ≤ 1000), which is separated by exactly one space.

Output

For each test case, output the equivalent polynomial's coefficient b0,b1, ... ,bn. One line for each test case and each number is separated by exactly one space, no extra space at the end of each line.
Sample Input

2 1
1 0 2
Sample Output

3 4 2
Source

POJ Monthly Contest - 2009.08.23, wjn

"""

from math import *

def equivpoly(a, t):
    n = len(a)
    b = [0] * n
    for i in range(n):
        for j in range(i+1):
            b[j] += a[i] * t**(i-j) * comb(i, j)
    return b

def main():
    assert(equivpoly([1, 0, 2], 1) == [3, 4, 2])
    assert(equivpoly([31, 532, 34, 562, 14], 31) == [29721033, 3291182, 133024, 2298, 14])

main()
