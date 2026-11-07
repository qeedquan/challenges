#!/usr/bin/env python3

"""

Given three integers a, b, and c, determine if there is at least one positive number and at least one negative number among them.
If so, print YES; otherwise, print NO.

Input
Three integers a, b, and c provided on a single line, separated by spaces.

Output
Print YES if the condition is met, otherwise print NO.

Examples
Input #1
1 -2 3

Answer #1
YES

"""

def solve(a, b, c):
    if min(a, b, c) < 0 and max(a, b, c) > 0:
        return "YES"
    return "NO"

def main():
    assert(solve(1, -2, 3) == "YES")

main()
