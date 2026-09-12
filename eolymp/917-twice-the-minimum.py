#!/usr/bin/env python3

"""

An array of real numbers is given. Compute twice the value of the minimum element in the array.

Input
The first line contains the number of elements in the array n (n≤100). The second line contains n real numbers, each with an absolute value not exceeding 100.

Output
Print twice the value of the minimum element in the array with two decimal places.

Examples

Input #1
6
6 7.5 2.1 2.0 0 -3

Answer #1
-6.00

"""

def solve(a):
    return min(a) * 2

def main():
    assert(solve([6, 7.5, 2.1, 2.0, 0, -3]) == -6)

main()
