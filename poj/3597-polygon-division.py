#!/usr/bin/env python3

"""

Description

Given a regular polygon, there are numerous ways to divide it into several triangles and/or quadrangles by adding some diagonals that do not properly intersect each other. For example, Figure 4 shows all ten different divisions of a regular pentagon into triangles and quadrangles.

http://poj.org/images/3597_1.png

Figure 4: Divisions of a regular pentagon into triangles and quadrangles

Given n, the number of sides of the polygon, compute the number of such divisions.

Input

The input contains multiple test cases. Each test case consists of a single integer n (3 ≤ n ≤ 5000) on a separate line. The input ends where EOF is met.

Output

For each test case, print the answer modulo 264 on a separate line.

Sample Input

3
4
5
6
7
8
9
10

Sample Output

1
3
10
38
154
654
2871
12925

Source

PKU Campus 2008 (POJ Founder Monthly Contest – 2008.05.10), frkstyc

"""

from math import *

# https://oeis.org/A001002
def divisions(n):
    r = 0
    m = (n // 2) + (n & 1)
    for i in range(m, n + 1):
        r += comb(n + i, i) * comb(i, n - i)
    return r // (n + 1)

def main():
    tab = [1, 1, 3, 10, 38, 154, 654, 2871, 12925, 59345, 276835, 1308320, 6250832, 30142360, 146510216, 717061938, 3530808798, 17478955570, 86941210950, 434299921440, 2177832612120, 10959042823020, 55322023332420, 280080119609550, 1421744205767418, 7234759677699954]

    for i in range(len(tab)):
        assert(divisions(i) == tab[i])

main()
