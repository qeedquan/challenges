#!/usr/bin/env python3

"""

The formula to compute the area of regular polygon with n sides and side-length of s is:

A(n, s) = n*s^2 / (4*tan(pi/n))

Your task is to use this formula to calculate the areas of regular polygons. You are also asked to print appropriate error messages for problematic input cases.

Input
The first input line contains the number of test cases N, 1≤N≤50.

Each test case begins with a line containing two integers n and s, separated by space.

n is the user input for the number of sides, and satisfies −100≤n≤100.

s is the user input for the length of each side, and satisfies −100≤s≤100.

Output
For each test case, print an error message or the area (if no errors are found) on a single line.
If n is zero or negative then print the message "Number of sides must be positive".
Otherwise, if n is strictly less than 3, then print "Need more sides".
Otherwise, if s is zero or negative then print "Side length must be positive".
Otherwise the input is valid, and you are asked to print the area of the regular polygon described by the input, to 4 decimal places.

Examples
Input #1
4
4 1
3 10
-10 10
10 -10

Answer #1
1.0000
43.3013
Number of sides must be positive
Side length must be positive

"""

from math import tan, pi

def solve(n, s):
    if n < 0:
        return "Number of sides must be positive"
    if s < 0:
        return "Side length must be positive"
    return n*s*s / (4*tan(pi/n))

def main():
    print(solve(4, 1))
    print(solve(3, 10))
    print(solve(-10, 10))
    print(solve(10, -10))

main()
