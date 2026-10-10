#!/usr/bin/env python3

"""

As is known, the Ackermann function plays an important role in theoretical computer science.
However, due to its rapid growth, the function can be difficult to compute.

The Ackermann function is defined recursively for non-negative integers m and n as follows:

A(m, n) = n + 1              if m = 0
          A(m-1, 1)          if m > 0, n = 0
          A(m-1, A(m, n-1))  if m > 0, n > 0

Given m and n, compute the value of A(m, n)

Input
Each line contains two non-negative integers m and n, where 0≤m≤3. For all m<3, n does not exceed 10^6.
If m=3, then n does not exceed 24.

Output
For each given pair of numbers, print the value of the Ackermann function A(m,n) on a separate line.

Examples

Input #1
1 3
2 4

Answer #1
5
11

"""

def ackermann(m, n):
    if m < 0 or n < 0:
        return 0
    if m == 0:
        return n + 1
    if m > 0 and n == 0:
        return ackermann(m-1, 1)
    return ackermann(m-1, ackermann(m, n-1))

def main():
    assert(ackermann(1, 3) == 5)
    assert(ackermann(2, 4) == 11)

main()
