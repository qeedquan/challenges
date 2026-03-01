#!/usr/bin/env python3

"""

Description

Given a big integer number, you are required to find out whether it's a prime number.
Input

The first line contains the number of test cases T (1 <= T <= 20 ), then the following T lines each contains an integer number N (2 <= N < 2^54).

Output

For each test case, if N is a prime number, output a line containing the word "Prime", otherwise, output a line containing the smallest prime factor of N.
Sample Input

2
5
10
Sample Output

Prime
2
Source

POJ Monthly

"""

from sympy import *

def primetest(n):
    p = factorint(n)
    if len(p) == 1:
        v = list(p.values())
        if v[0] == 1:
            return "Prime"
    return min(p)

def main():
   assert(primetest(5) == "Prime")
   assert(primetest(9) == 3)
   assert(primetest(10) == 2)
   assert(primetest(25) == 5)
   assert(primetest(99) == 3)
   assert(primetest(221) == 13)

main()
