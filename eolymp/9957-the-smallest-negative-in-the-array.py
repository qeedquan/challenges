#!/usr/bin/env python3

"""

Given an array of n integers, your task is to find the smallest negative number.
If there are no negative numbers in the array, output NO.

Input
The first line contains the integer n (1≤n≤100), representing the number of elements in the array.
The second line contains n integers, each with an absolute value not exceeding 100.

Output
Print the smallest negative number, or NO if there are no negative numbers in the array.

Examples

Input #1
5
-2 3 5 -6 1

Answer #1
-6

Input #2
5
1 3 5 5 1

Answer #2
NO

"""

def solve(a):
    r = min(a)
    if r < 0:
        return r
    return "NO"

def main():
    assert(solve([-2, 3, 5, -6, 1]) == -6)
    assert(solve([1, 3, 5, 5, 1]) == "NO")

main()
