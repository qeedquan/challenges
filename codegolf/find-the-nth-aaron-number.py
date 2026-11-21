#!/usr/bin/env python3

"""

Background
A Ruth-Aaron pair is a pair of consecutive positive integers n and n+1 such that the sum of the prime factors (counting repeated prime factors) of each integer are equal. For example, (714,715) is a Ruth-Aaron pair, since 714=2*3*7*17, 715=5*11*13, and 2+3+7+17=5+11+13=29. The name Ruth-Aaron pair was chosen by Carl Pomerance in reference to Babe Ruth's career home run total of 714, which stood as the world record from May 25, 1935 until April 8, 1974 when Hank Aaron hit his 715th home run. You can learn more about the fascinating history of these numbers in this Numberphile video.

Goal
Write a complete program or function which, given a positive integer n, outputs the nth Aaron number, where the nth number is defined to be the larger integer of the nth Ruth-Aaron pair. Thus the nth Aaron number is a(n)+1, where a(n) is the nth term in the OEIS sequence A039752.

Test cases
The first few Aaron numbers are

6,9,16,78,126,715,949,1331,1521,1863,2492,3249,4186,4192,5406,5561,5960,6868,8281,8464,10648,12352,14588,16933,17081,18491,20451,24896,26643,26650,28449,28810,33020,37829,37882,41262,42625,43216

Rules
Standard loopholes are forbidden.

Input and output may be in any convenient format.

This is code-golf, the shortest answer (in bytes) wins.

"""

from sympy import factorint

# https://oeis.org/A039752
def aupton(terms):
    alst, k, sopfrk, sopfrkp1 = [], 2, 2, 3
    while len(alst) < terms:
        if sopfrkp1 == sopfrk:
            alst.append(k)
        k += 1
        fkp1 = factorint(k+1)
        sopfrk, sopfrkp1 = sopfrkp1, sum(p*fkp1[p] for p in fkp1)
    return alst

def aarons(terms):
    alst = aupton(terms)
    for i in range(len(alst)):
        alst[i] += 1
    return alst

def main():
    tab = [
        6, 9, 16, 78, 126, 715, 949,
        1331, 1521, 1863, 2492, 3249,
        4186, 4192, 5406, 5561, 5960, 6868,
        8281, 8464, 10648, 12352, 14588,
        16933, 17081, 18491, 20451, 24896,
        26643, 26650, 28449, 28810, 33020,
        37829, 37882, 41262, 42625, 43216
    ]

    assert(aarons(len(tab)) == tab)

main()
