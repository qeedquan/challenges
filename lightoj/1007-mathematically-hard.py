#!/usr/bin/env python3

"""

Mathematically some problems look hard. But with the help of the computer, some problems can be easily solvable.

In this problem, you will be given two integers a and b.
You have to find the summation of the scores of the numbers from a to b (inclusive).
The score of a number is defined as the following function:

score(x) = n^2, n<x and gcd(n,x)=1

To illustrate, n is the number of relatively prime numbers with x, which are smaller than x.

For example, For 6, the relatively prime numbers with 6 are {1, 5}.
So, score (6) = 22 = 4.
For 16, the relatively prime numbers with 16 are {1, 3, 5, 7, 9, 11, 13, 15}. So, score (16) = 82 = 64.

Now, you have to solve this task.

Input
Input starts with an integer T (≤ 105), denoting the number of test cases.

Each case will contain two integers a and b (2 ≤ a ≤ b ≤ 5 * 10^6).

Output
For each case, print the case number and the summation of all the scores from a to b.

Sample
Input	Output
3
6 6
8 8
2 20

Case 1: 4
Case 2: 16
Case 3: 1237

Notes
Two integers are said to be relatively prime, if the greatest common divisor for them is 1.

Euler's totient function ϕ(n) applied to a positive integer n is defined to be the number of positive
integers less than or equal to n that are relatively prime to n. ϕ(n) is read "phi of n."

Given the general prime factorization of n=p[1]^e1 p[2]^e2 … p[m]^em, one can compute ϕ(n) using the formula:

ϕ(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pm)

"""

from sympy import totient

def build(n):
    p = [0] * (n + 1)
    for i in range(2, n + 1):
        p[i] = totient(i)**2 + p[i - 1]
    return p

def solve(p, a, b):
    return p[b] - p[a - 1]

def main():
    p = build(1000)
    assert(solve(p, 6, 6) == 4)
    assert(solve(p, 8, 8) == 16)
    assert(solve(p, 2, 20) == 1237)

main()
