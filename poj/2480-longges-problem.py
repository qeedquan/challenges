#!/usr/bin/env python3

"""

Description

Longge is good at mathematics and he likes to think about hard mathematical problems which will be solved by some graceful algorithms. Now a problem comes: Given an integer N(1 < N < 2^31),you are to calculate ∑gcd(i, N) 1<=i <=N.

"Oh, I know, I know!" Longge shouts! But do you know? Please solve it.
Input

Input contain several test case.
A number N per line.
Output

For each N, output, ∑gcd(i, N) 1<=i <=N, a line

Sample Input

2
6

Sample Output

3
15
Source

POJ Contest,Author:Mathematica@ZSU

"""

from sympy.ntheory import *

# https://oeis.org/A018804
def gcdsum(n):
    r = 0
    for d in divisors(n):
        r += n*totient(d)//d
    return r

def main():
    tab = [1, 3, 5, 8, 9, 15, 13, 20, 21, 27, 21, 40, 25, 39, 45, 48, 33, 63, 37, 72, 65, 63, 45, 100, 65, 75, 81, 104, 57, 135, 61, 112, 105, 99, 117, 168, 73, 111, 125, 180, 81, 195, 85, 168, 189, 135, 93, 240, 133, 195, 165, 200, 105, 243, 189, 260, 185, 171, 117, 360]

    for i in range(len(tab)):
        assert(gcdsum(i + 1) == tab[i])

main()
