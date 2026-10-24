#!/usr/bin/env python3

"""

Given a number N, find the number of sequences composed of zeros and ones, each of length N, where no three consecutive ones appear.

Input
The input consists of a single natural number N, with a maximum value of 35.

Output
Output the total number of such sequences. It is guaranteed that the result will not exceed 2^31 - 1.

Examples
Input #1
4

Answer #1
13

"""

from math import sqrt, cbrt

# https://www.fq.math.ca/Scanned/20-2/spickerman.pdf
# https://oeis.org/A000073
def tribonacci(n):
    k0 = cbrt(19 + 3*sqrt(33))
    k1 = cbrt(19 - 3*sqrt(33))

    p = (k0 + k1 + 1) / 3
    o = (2 - k0 - k1 + sqrt(3)*1j*(k0 - k1)) / 6
    a = abs(p**2 / (p - o)**2)
    return int(a*p**n + 0.5)

def solve(n):
    return tribonacci(n + 1)

def main():
    assert(solve(4) == 13)

main()
