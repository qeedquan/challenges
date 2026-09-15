#!/usr/bin/env python3

"""

An array of N integers is provided as input. The task is to calculate the sum of the array's elements, excluding all instances of its smallest and largest values.

Input
The first line contains a natural number N. The second line contains N integers. Each integer has an absolute value not exceeding 100.

Output
Output the calculated sum.

Examples

Input #1
7
6 2 7 1 7 1 2

Answer #1
10

"""

def solve(a):
    if len(a) == 0:
        return 0

    x = min(a)
    y = max(a)
    r = 0
    for v in a:
        if v != x and v != y:
            r += v
    return r

def main():
    assert(solve([6, 2, 7, 1, 7, 1, 2]) == 10)

main()
