#!/usr/bin/env python3

"""

Given an integer n, you have to find whether it can be expressed as summation of factorials such that:

n=x1!+x2! + ... + xk!(xi<xi+1)

Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.

Each case starts with a line containing an integer n (1 ≤ n ≤ 10^18).

Output
For each case, print the case number and the solution in summation of factorial form. If there is no solution, print impossible. There can be multiple solutions, any valid one will do. See the samples for exact formatting.

Sample
Input	Output
4
7
7
9
11

Case 1: 1!+3!
Case 2: 0!+3!
Case 3: 1!+2!+3!
Case 4: impossible

Notes
Be careful about the output format; you may get wrong answer for wrong output format.
In mathematics, the factorial of a positive integer n, denoted by n!, is the product of all positive integers less than or equal to n:
n!=n×(n−1)×(n−2)×(n−3)×⋯×3×2×1

"""

from math import factorial

def maxfact(n):
    for i in range(n):
        if factorial(i) > n:
            return i
    return n

# https://oeis.org/A059589
def solve(n):
    r = []
    i = maxfact(n)
    while i >= 0:
        f = factorial(i)
        if f <= n:
            n -= f
            r.append(i)
        i -= 1

    if n != 0:
        return []
    return r[::-1]

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if len(solve(i)) > 0:
            r.append(i)
        i += 1
    return r

def main():
    tab = [
        1, 2, 3, 4, 6, 7, 8, 9, 10, 24, 25, 26, 27, 28, 30, 31, 32, 33, 34, 120,
        121, 122, 123, 124, 126, 127, 128, 129, 130, 144, 145, 146, 147, 148,
        150, 151, 152, 153, 154, 720, 721, 722, 723, 724, 726, 727, 728, 729,
        730, 744, 745, 746, 747, 748, 750, 751, 752, 753
    ]

    print(solve(7))
    print(solve(9))
    print(solve(11))

    assert(gen(len(tab)) == tab)

main()
