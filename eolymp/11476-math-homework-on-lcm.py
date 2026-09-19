#!/usr/bin/env python3

"""

VanDiana received a math homework in which she has to solve T problems on finding the least common multiple (LCM) of two natural numbers a and b.
To check her work, she wrote a program in C++ that performs the verification and asks you to do the same.

Input
The first line contains a natural number T (1≤T≤200) — the number of problems. The next T lines contain the problems themselves.
Each problem consists of three natural numbers a, b, c (1≤a,b,c≤2×10^15),
where a and b are the numbers whose LCM needs to be found, and c is the answer given by VanDiana.

Output
For each problem, print YES in a separate line if VanDiana's answer is correct, otherwise print NO.

Examples

Input #0
2
25 50 50
35 50 35

Answer #0
YES
NO

"""

from math import lcm

def solve(a, b, c):
    if c == lcm(a, b):
        return "YES"
    return "NO"

def main():
    assert(solve(25, 50, 50) == "YES")
    assert(solve(35, 50, 35) == "NO")

main()
