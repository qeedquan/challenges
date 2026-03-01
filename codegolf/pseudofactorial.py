#!/usr/bin/env python3

"""

There is a rather curious number which shows up sometimes in math problems or riddles. The pseudofactorial(N) is the least (i.e. lowest) common multiple of the numbers 1 through N; in other words, it's the lowest number which has all numbers from 1 through N as factors.

For instance pseudofactorial(7) = 3 * 4 * 5 * 7, which is the same as 7! except that 2 and 6 have been removed because they are contained in other terms.

Write a program to calculate pseudofactorial(N) and as always, shortest code wins.

Here is a short list for your use. More test cases can be found in the OEIS under A003418.

Factorial:

1
2
6
24
120
720
5040

Pseudofactorial:

1
2
6
12
60
60
420

"""

from math import *

# https://oeis.org/A003418
def pseudofactorial(n):
    if n < 0:
        return 0
    
    v = 1
    for i in range(1, n+1):
        v = lcm(i, v)
    return v

def main():
    tab = [1, 1, 2, 6, 12, 60, 60, 420, 840, 2520, 2520, 27720, 27720, 360360, 360360, 360360, 720720, 12252240, 12252240, 232792560, 232792560, 232792560, 232792560, 5354228880, 5354228880, 26771144400, 26771144400, 80313433200, 80313433200, 2329089562800, 2329089562800]

    for i in range(len(tab)):
        assert(pseudofactorial(i) == tab[i])

main()
