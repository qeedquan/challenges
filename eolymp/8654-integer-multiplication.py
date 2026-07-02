#!/usr/bin/env python3

"""

Three integers a,b,c are given. Find the value of expression a∗b mod c.

Input
Three positive integers a,b,c (a,b,c<2^63).

Output
Print the value of expression a∗b mod c.

Examples
Input #1
1000000000007 10000000000005 1000000000000003

Answer #1
74970000000035

"""

def solve(a, b, c):
    return ((a % c) * (b % c)) % c

def main():
    assert(solve(1000000000007, 10000000000005, 1000000000000003) == 74970000000035)

main()

