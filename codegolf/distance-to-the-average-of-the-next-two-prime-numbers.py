#!/usr/bin/env python3

"""

Suppose we have a sequence P.
Every element Pn represents the distance between the nth prime number and the average of the next two prime numbers.

For example, P1 would be the distance between the first prime number (2) and the average of the next two prime numbers (3 and 5), so P1=3+52−2=2.
Similarly, P2=5+72−3=3.

Input
Your input is an integer n. You may assume n>0.

Output
Your task is to print out the sequence P up to n, starting from P1.
You can format your output however you like as long as every element is clearly separated.

Rules
This is code-golf, so shortest number of bytes wins.
You can assume that every computed number will be within the limits of the language you choose, so no need to worry about how big n or Pn can get.

Test cases
Input            Output
n = 1            2
n = 2            2, 3
n = 5            2, 3, 4, 5, 4
n = 10           2, 3, 4, 5, 4, 5, 4, 7, 7, 5
(If you're curious, this sequence is A305748!)

"""

from sympy import *

# https://oeis.org/A305748
def seq(n):
    r = []
    i = 1
    while len(r) < n:
        p0 = nextprime(i)
        p1 = nextprime(p0 + 1)
        p2 = nextprime(p1 + 1)
        i = p0
        
        r.append((p1+p2)//2 - p0)

    if len(r) > 0:
        r[0] = 2

    return r

def main():
    tab = [2, 3, 4, 5, 4, 5, 4, 7, 7, 5, 8, 5, 4, 7, 9, 7, 5, 8, 5, 5, 8, 7, 10, 10, 5, 4, 5, 4, 11, 16, 7, 7, 7, 11, 5, 9, 8, 7, 9, 7, 7, 11, 4, 5, 8, 18, 14, 5, 4, 7, 7, 7, 13, 9, 9, 7, 5, 8, 5, 7, 17, 16, 5, 4, 11, 17, 11, 11, 4, 7, 10, 11, 9, 8, 7, 10, 10, 8, 13, 11, 7, 11, 5, 8, 7, 10, 10, 5, 4, 10, 16, 10, 8, 10, 7, 12, 13]

    assert(seq(1) == [2])
    assert(seq(2) == [2, 3])
    assert(seq(5) == [2, 3, 4, 5, 4])
    assert(seq(10) == [2, 3, 4, 5, 4, 5, 4, 7, 7, 5])
    assert(seq(len(tab)) == tab)

main()
