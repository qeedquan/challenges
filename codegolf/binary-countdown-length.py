#!/usr/bin/env python3

"""

inspired by Count down from infinity

Given a non-negative integer N, output the number of repetitions of the following steps it takes to reach 0:

Convert N to binary (4812390 -> 10010010110111001100110)
Flip each bit (10010010110111001100110 -> 01101101001000110011001)
Trim leading zeroes (01101101001000110011001 -> 1101101001000110011001)
Convert back to decimal (1101101001000110011001 -> 3576217)
Rules
Input and output may be in any unambiguous, consistent format
The input will be within the native representable integer range for your language (if your language supports arbitrarily-large integers, there is no bound)
Test Cases
0 -> 0
1 -> 1
42 -> 6
97 -> 3
170 -> 8
255 -> 1
682 -> 10
8675309 -> 11
4812390 -> 14
178956970 -> 28
2863311530 -> 32

This sequence is A005811 in the OEIS.

"""

def dec2gray(n):
    return n ^ (n >> 1)

# https://oeis.org/A005811
def gray1s(n):
    s = bin(dec2gray(n))[2:]
    return s.count("1")

def main():
    tab = [0, 1, 2, 1, 2, 3, 2, 1, 2, 3, 4, 3, 2, 3, 2, 1, 2, 3, 4, 3, 4, 5, 4, 3, 2, 3, 4, 3, 2, 3, 2, 1, 2, 3, 4, 3, 4, 5, 4, 3, 4, 5, 6, 5, 4, 5, 4, 3, 2, 3, 4, 3, 4, 5, 4, 3, 2, 3, 4, 3, 2, 3, 2, 1, 2, 3, 4, 3, 4, 5, 4, 3, 4, 5, 6, 5, 4, 5, 4, 3, 4, 5, 6, 5, 6, 7, 6, 5, 4, 5, 6, 5, 4, 5]

    for i in range(len(tab)):
        assert(gray1s(i) == tab[i])

    assert(gray1s(0) == 0)
    assert(gray1s(1) == 1)
    assert(gray1s(42) == 6)
    assert(gray1s(97) == 3)
    assert(gray1s(170) == 8)
    assert(gray1s(255) == 1)
    assert(gray1s(682) == 10)
    assert(gray1s(8675309) == 11)
    assert(gray1s(4812390) == 14)
    assert(gray1s(178956970) == 28)
    assert(gray1s(2863311530) == 32)

main()
