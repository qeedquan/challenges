#!/usr/bin/env python3

"""

How to spot them
Take a positive integer k. Find its divisors. Find the distinct prime factors of each divisor. Sum all these factors together. If this number (sum) is a divisor of k (if the sum divides k) then, this number k, is a BIU number

Examples
Let's take the number 54
Find all the divisors: [1, 2, 3, 6, 9, 18, 27, 54]
Find the distinct prime factors of each divisor
NOTE: For the case of 1 we take as distinct prime factor 1

1  -> 1
2  -> 2
3  -> 3
6  -> 2,3
9  -> 3
18 -> 2,3
27 -> 3
54 -> 2,3
Now we take the sum of all these prime factors
1+2+3+2+3+3+2+3+3+2+3=27
27 divides 54 (leaves no remainder)
So, 54 is a BIU number.

Another (quick) example for k=55
Divisors: [1,5,11,55]
Sum of distinct prime factors: 1+5+11+5+11=33
33 is NOT a divisor of 55, that's why 55 is NOT a BIU number.

BIU numbers
Here are the first 20 of them:

1,21,54,290,735,1428,1485,1652,2262,2376,2580,2838,2862,3003,3875,4221,4745, 5525,6750,7050...

but this list goes on and there are many BIU numbers that are waiting to be descovered by you!

The Challenge
Given an integer n>0 as input, output the nth BIU number

Test Cases
Input->Output

1->1
2->21
42->23595
100->118300
200->415777
300->800175

This is codegolf.Shortest answer in bytes wins!

"""

from sympy import *

def biu(n):
    if n < 1:
        return False

    r = 0
    d = divisors(n)
    for x in d:
        f = factorint(x)
        if x == 1:
            f = {1: 1}
        for y in f:
            r += y
    return n%r == 0

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if biu(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [1, 21, 54, 290, 735, 1428, 1485, 1652, 2262, 2376, 2580, 2838, 2862, 3003, 3875, 4221, 4745, 5525, 6750, 7050]
    assert(gen(len(tab)) == tab)

main()
