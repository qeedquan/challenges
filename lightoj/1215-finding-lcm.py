#!/usr/bin/env python3

"""

LCM is an abbreviation used for Least Common Multiple in Mathematics. We say LCM (a, b, c) = L if and only if L is the least integer which is divisible by a, b and c.

You will be given a, b and L. You have to find c such that LCM (a, b, c) = L. If there are several solutions, print the one where c is as small as possible. If there is no solution, report so.

Input
Input starts with an integer T (≤ 325), denoting the number of test cases.

Each case starts with a line containing three integers a b L (1 ≤ a, b ≤ 10^6, 1 ≤ L ≤ 10^12).

Output
For each case, print the case number and the minimum possible value of c. If no solution is found, print impossible.

Sample
Input	Output
3
3 5 30
209475 6992 77086800
2 6 10

Case 1: 2
Case 2: 1
Case 3: impossible

"""

from math import gcd, lcm

def solve(A, B, L):
    M = lcm(A, B)
    if M == 0 or L%M != 0:
        return "impossible"
    
    C = L // M
    G = gcd(C, M)
    while G != 1:
        C *= G
        M //= G
        G = gcd(C, M)
    return C

def main():
    assert(solve(3, 5, 30) == 2)
    assert(solve(209475, 6992, 77086800) == 1)
    assert(solve(2, 6, 10) == "impossible")

main()
