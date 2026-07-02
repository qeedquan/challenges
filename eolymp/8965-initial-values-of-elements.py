#!/usr/bin/env python3

"""

Each element of an array of n integers is increased by the smallest element of the array.
The resulting values are provided as input to the program in the same order.
Restore the original values of the array elements.

Input
The first line contains one positive integer n (n≤100). The second line contains n integers, each with an absolute value not exceeding 100.

Output
Print the original values of the array elements in a single line.

Examples
Input #1
7
1 7 -1 -4 2 1 2

Answer #1
3 9 1 -2 4 3 4

"""

def solve(a):
    m = min(a) // 2
    for i in range(len(a)):
        a[i] -= m
    return a

def main():
    assert(solve([1, 7, -1, -4, 2, 1, 2]) == [3, 9, 1, -2, 4, 3, 4])

main()
