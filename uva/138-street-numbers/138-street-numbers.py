#!/usr/bin/env python3

"""

A computer programmer lives in a street with houses numbered consecutively (from 1) down one side
of the street. Every evening she walks her dog by leaving her house and randomly turning left or right
and walking to the end of the street and back. One night she adds up the street numbers of the houses
she passes (excluding her own). The next time she walks the other way she repeats this and finds, to
her astonishment, that the two sums are the same. Although this is determined in part by her house
number and in part by the number of houses in the street, she nevertheless feels that this is a desirable
property for her house to have and decides that all her subsequent houses should exhibit it.

Write a program to find pairs of numbers that satisfy this condition. To start your list the first two
pairs are: (house number, last number):
6 8
35 49

Input
There is no input for this program.

Output
Output will consist of 10 lines each containing a pair of numbers, each printed right justified in a field
of width 10 (as shown above).

"""

from math import comb

# https://oeis.org/A001109
def T1(n):
    r = 0
    for k in range(n):
        r += (-1)**(n+k+1) * comb(n+k, 2*k + 1) * 8**k
    return r

# https://oeis.org/A001108
def T2(n):
    r = 0
    for i in range(1, n+1):
        r += 2**(i-1) * comb(2*n, 2*i)
    return r

def main():
    for i in range(10):
        print(T1(i + 2), T2(i + 2))

main()

