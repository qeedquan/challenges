#!/usr/bin/env python3

"""

Introduction
This question is inspired by this great question.

Challenge
Given a number N>0, output the largest integer a^b that is smaller or equal to N, and the smallest integer c^d that is greater or equal to N, where b>1 and d>1.

Output should be a list of two integers, the first being smaller or equal to N, the second being greater or equal to N, and both being a perfect power. The two outputs can be in any order.

If N is a perfect power already, the output should be the list [N, N].

This is code-golf, so the shortest code (as measured in bytes) wins.

Example Input and Output

Input:

30

Output:

[27, 32]

Explanation: 27=3^3 is the largest perfect power less than or equal to 30 and 32=2^5 is the smallest perfect power greater or equal to 30. Note that exponents b and d are not the same in this case.

Test cases
2 -> [1, 4]
30 -> [27, 32]
50 -> [49, 64]
100 -> [100, 100]. 100 is already a perfect power.
126 -> [125, 128]
200 -> [196, 216]
500 -> [484, 512]
5000 -> [4913, 5041]
39485 -> [39304, 39601]
823473 -> [822649, 823543]
23890748 -> [23887872, 23892544]

"""

from math import *
import sys

# ported from @bsoelch solution
def powersandwich2(n):
    mi = sys.maxsize
    ma = 0
    for p in range(2, len(bin(n))):
        mi = min(mi, abs(floor(-n**(1/p)))**p)
        ma = max(ma, floor(n**(1/p))**p)
    return (ma, mi)

def main():
    assert(powersandwich2(2) == (1, 4))
    assert(powersandwich2(30) == (27, 32))
    assert(powersandwich2(50) == (49, 64))
    assert(powersandwich2(100) == (100, 100))
    assert(powersandwich2(126) == (125, 128))
    assert(powersandwich2(200) == (196, 216))
    assert(powersandwich2(500) == (484, 512))
    assert(powersandwich2(5000) == (4913, 5041))
    assert(powersandwich2(39485) == (39304, 39601))
    assert(powersandwich2(823473) == (822649, 823543))
    assert(powersandwich2(23890748) == (23887872, 23892544))

main()
