#!/usr/bin/env python3

"""

Description

A single positive integer i is given. Write a program to find the digit located in the position i in the sequence of number groups S1S2...Sk. Each group Sk consists of a sequence of positive integer numbers ranging from 1 to k, written one after another.
For example, the first 80 digits of the sequence are as follows:
11212312341234512345612345671234567812345678912345678910123456789101112345678910

Input

The first line of the input file contains a single integer t (1 ≤ t ≤ 10), the number of test cases, followed by one line for each test case. The line for a test case contains the single integer i (1 ≤ i ≤ 2147483647)
Output

There should be one output line per test case containing the digit located in the position i.

Sample Input

2
8
3

Sample Output

2
2
Source

Tehran 2002, First Iran Nationwide Internet Programming Contest

"""

from math import *

# https://oeis.org/A002260
def risereset(n):
    return n - comb(floor((1 + sqrt(8*n)) / 2), 2)

def main():
    assert(risereset(8) == 2)
    assert(risereset(3) == 2)

main()
