#!/usr/bin/env python3

"""

Description

To improve the organization of his farm, Farmer John labels each of his N (1 <= N <= 5,000) cows with a distinct serial number in the range 1..20,000. Unfortunately, he is unaware that the cows interpret some serial numbers as better than others. In particular, a cow whose serial number has the highest prime factor enjoys the highest social standing among all the other cows.

(Recall that a prime number is just a number that has no divisors except for 1 and itself. The number 7 is prime while the number 6, being divisible by 2 and 3, is not).

Given a set of N (1 <= N <= 5,000) serial numbers in the range 1..20,000, determine the one that has the largest prime factor.

Input

* Line 1: A single integer, N

* Lines 2..N+1: The serial numbers to be tested, one per line
Output

* Line 1: The integer with the largest prime factor. If there are more than one, output the one that appears earliest in the input file.

Sample Input

4
36
38
40
42

Sample Output

38
Hint

OUTPUT DETAILS:
19 is a prime factor of 38. No other input number has a larger prime factor.

Source

USACO 2005 October Bronze

"""

from sympy import *

def prestige(a):
    r, m = 0, 0
    for v in a:
        p = max(primefactors(v))
        if m < p:
            r, m = v, p
    return r

def main():
    assert(prestige([36, 38, 40, 42]) == 38)

main()
