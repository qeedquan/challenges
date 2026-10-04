#!/usr/bin/env python3

"""

Description


A bee larva living in a hexagonal cell of a large honeycomb decides to creep for a walk. In each “step” the larva may move into any of the six adjacent cells and after n steps, it is to end up in its original cell.

Your program has to compute, for a given n, the number of different such larva walks.

Input

The first line contains an integer giving the number of test cases to follow. Each case consists of one line containing an integer n, where 1 ≤ n ≤ 14.

Output

For each test case, output one line containing the number of walks. Under the assumption 1 ≤ n ≤ 14, the answer will be less than 231.

Sample Input

2
2
4

Sample Output

6
90
Source

Nordic 2006

"""

from math import *

# https://oeis.org/A002898
def walks(n):
    r = 0
    for i in range(n + 1):
        u = (-2)**(n-i) * comb(n, i)
        v = 0
        for j in range(i + 1):
            v += comb(i, j)**3
        r += u*v
    return r

def main():
    tab = [1, 0, 6, 12, 90, 360, 2040, 10080, 54810, 290640, 1588356, 8676360, 47977776, 266378112, 1488801600, 8355739392, 47104393050, 266482019232, 1512589408044, 8610448069080, 49144928795820, 281164160225520, 1612061452900080, 9261029179733760, 53299490722049520]

    for i in range(len(tab)):
        assert(walks(i) == tab[i])

main()
