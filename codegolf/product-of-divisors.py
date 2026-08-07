#!/usr/bin/env python3

"""

Challenge
Given a positive integer, return the product of its divisors, including itself.

This is sequence A007955 in the OEIS.

Test Cases
1: 1
2: 2
3: 3
4: 8
5: 5
6: 36
7: 7
8: 64
9: 27
10: 100
12: 1728
14: 196
24: 331776
25: 125
28: 21952
30: 810000

Scoring
This is code-golf, so the shortest answer in each language wins!

"""

from sympy import *

# https://oeis.org/A007955
def divprod(n):
    return prod(divisors(n))

def main():
    tab = [1, 2, 3, 8, 5, 36, 7, 64, 27, 100, 11, 1728, 13, 196, 225, 1024, 17, 5832, 19, 8000, 441, 484, 23, 331776, 125, 676, 729, 21952, 29, 810000, 31, 32768, 1089, 1156, 1225, 10077696, 37, 1444, 1521, 2560000, 41, 3111696, 43, 85184, 91125, 2116, 47, 254803968, 343]
    
    for i in range(len(tab)):
        assert(divprod(i+1) == tab[i])

main()
