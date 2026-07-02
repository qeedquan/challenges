#!/usr/bin/env python3

"""

Description

Beads of N colors are connected together into a circular necklace of N beads (N<=1000000000). Your job is to calculate how many different kinds of the necklace can be produced. You should know that the necklace might not use up all the N colors, and the repetitions that are produced by rotation around the center of the circular necklace are all neglected.

You only need to output the answer module a given number P.
Input

The first line of the input is an integer X (X <= 3500) representing the number of test cases. The following X lines each contains two numbers N and P (1 <= N <= 1000000000, 1 <= P <= 30000), representing a test case.
Output

For each test case, output one line containing the answer.
Sample Input

5
1 30000
2 30000
3 30000
4 30000
5 30000
Sample Output

1
3
11
70
629
Source

POJ Monthly,Lou Tiancheng

"""

from math import *
from sympy import *

# https://oeis.org/A056665
def necklaces(n, p):
    if n < 1:
        return 0

    r = 0
    for k in range(1, n + 1):
        g = gcd(n, k)
        r += (n**(n//g) * totient(g)) / totient(n//g)
    
    x = 0
    if r%n != 0:
        x = 1
    
    return (r//n + x) % p

def main():
    assert(necklaces(1, 30000) == 1)
    assert(necklaces(2, 30000) == 3)
    assert(necklaces(3, 30000) == 11)
    assert(necklaces(4, 30000) == 70)
    assert(necklaces(5, 30000) == 629)
    assert(necklaces(6, 30000) == 7826)
    assert(necklaces(7, 300000) == 117655)

main()
