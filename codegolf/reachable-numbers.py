#!/usr/bin/env python3

"""

Definitions
Euler Phi Function (AKA totient function): a function which takes in a positive number and returns the number of positive numbers less than the given number which are co-prime with given number. It is denoted as φ(n).

Reachable number: if there exists a positive integer x such that φ(x) == n, then n is reachable.

Task
Write a function/program to determine if a given positive integer is reachable.

Input
A positive number, in any reasonable format. One can assume that the number is within the capability of the language. Unary input is accepted.

Output
Two consistent values, one for reachable numbers, and the other for unreachable numbers. The two values can be anything, as long as they are consistent.

Testcases
The reachable numbers bellow 100 are:

1, 2, 4, 6, 8, 10, 12, 16, 18, 20, 22, 24, 28, 30, 32, 36, 40, 42, 44, 46, 48, 52, 54, 56, 58, 60, 64, 66, 70, 72, 78, 80, 82, 84, 88, 92, 96

(A002202 on OEIS)

Rules
Standard loopholes apply.

Winning criterion
This is code-golf. Submission with lowest byte-count wins.

References
Euler Phi Function
OEIS A002202

"""

from sympy import totient

# https://oeis.org/A002202
def reachable(n):
    for i in range(1, n*n + 1):
        if totient(i) == n:
            return True
    return False

def gen(n):
    r = []
    i = 1
    while len(r) < n:
        if reachable(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [1, 2, 4, 6, 8, 10, 12, 16, 18, 20, 22, 24, 28, 30, 32, 36, 40, 42, 44, 46, 48, 52]

    assert(gen(len(tab)) == tab)

main()
