#!/usr/bin/env python3

"""

Given 2 sets of integers, M and N, print their symmetric difference in ascending order.
The term symmetric difference indicates those values that exist in either M or N but do not exist in both.

Sample Input

STDIN       Function
-----       --------
4           set a size M = 4
2 4 5 9     a = {2, 4, 5, 9}
4           set b size N = 4
2 4 11 12   b = {2, 4, 11, 12}
Sample Output

5
9
11
12

"""

def symmetric_difference(a, b):
    x = a.union(b)
    y = a.intersection(b)
    return x.difference(y)

def do(a, b):
    l = sorted(list(symmetric_difference(a, b)))
    for v in l:
        print(v)

def main():
    a = set([2, 4, 5, 9])
    b = set([2, 4, 11, 12])
    do(a, b)

main()
