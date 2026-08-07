#!/usr/bin/env python3

"""

Given a sequence of real numbers, find the arithmetic mean of the positive numbers.

Input
The first line contains the number of numbers n (0<n≤100). The next line contains n real numbers, each with an absolute value not exceeding 100.

Output
Output the arithmetic mean of the positive numbers with 2 digits after the decimal point. If there are no positive numbers, output Not Found (without quotes).

Examples

Input #1
3
5.2 -2 4

Answer #1
4.60

Input #2
3
-5.2 -2 -4

Answer #2
Not Found

"""

def solve(a):
    s = 0
    c = 0
    for x in a:
        if x > 0:
            s += x
            c += 1
    if c == 0:
        return "Not Found"
    return s / c

def main():
    print(solve([5.2, -2, 4]))
    print(solve([-5.2, -2, -4]))

main()
