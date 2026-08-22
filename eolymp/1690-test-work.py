#!/usr/bin/env python3

"""

The eighth-grade classes took a test, and the results were as follows:
exactly A% of the students received a grade of 5, exactly B% received a grade of 4, exactly C% received a grade of 3, and the remaining D% received a grade of 2.
Determine the minimum possible number of students in the eighth-grade classes such that these percentages are possible.

Input
You are given four integers ranging from 0 to 100: A, B, C, and D, where A+B+C+D=100.

Output
Output a single positive integer—the minimum possible number of students in the classes.

Examples

Input #1
40 50 5 5

Answer #1
20

"""

from math import gcd

def solve(a, b, c, d):
    k = gcd(gcd(a, b), gcd(c, d))
    return a//k + b//k + c//k + d//k

def main():
    assert(solve(40, 50, 5, 5) == 20)

main()
