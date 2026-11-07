#!/usr/bin/env python3

"""

Given a positive integer n. Is it divisible simultaneously by a and by b?

Input
Three positive integers n, a, and b, not greater than 10^9.

Output
Print YES if n is divisible simultaneously by a and by b. Print NO otherwise.

Examples

Input #1
12 4 6

Answer #1
YES

Input #2
10 5 6

Answer #2
NO

"""

def solve(n, a, b):
    if a != 0 and b != 0 and n%a == 0 and n%b == 0:
        return "YES"
    return "NO"

def main():
    assert(solve(12, 4, 6) == "YES")
    assert(solve(10, 5, 6) == "NO")

main()
