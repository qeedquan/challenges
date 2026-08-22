#!/usr/bin/env python3

"""

The Challenge
Given an integer, calculate its score as described below.

The score is calculated by raising each digit of the input Integer to the power n, where n denotes the index of the digit in Input (beginning with 1) when counted from left to right (the index of leftmost digit should be 1), and then summing them all together. If the original number happens to be prime, then add the largest digit of the input integer to the score, else subtract the smallest digit of the input integer from it.

Input
Your program should take an integer as input. You can take the input in whatever way you want to.

Output
Output the score of the input integer through whatever medium your programming language supports. Function return is also allowed.

Test Cases
 5328   ->  (5^1)+(3^2)+(2^3)+(8^4)-2 = 4116
 3067   ->  (3^1)+(0^2)+(6^3)+(7^4)+7 = 2627
 7      ->  (7^1)+7                   = 14

Scoring
This is code-golf, so the shortest code in bytes wins!

"""

from sympy import *

def score(n):
    mi = 256
    ma = 0
    s = str(n)
    r = 0
    for i in range(len(s)):
        x = ord(s[i]) - ord('0')
        mi = min(mi, x)
        ma = max(ma, x)
        r += x**(i + 1)
    
    if isprime(n):
        r += ma
    else:
        r -= mi

    return r

def main():
    assert(score(5328) == 4116)
    assert(score(3067) == 2627)
    assert(score(7) == 14)

main()
