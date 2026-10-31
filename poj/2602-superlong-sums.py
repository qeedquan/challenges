#!/usr/bin/env python3

"""

Description

The creators of a new programming language D++ have found out that whatever limit for SuperLongInt type they make, sometimes programmers need to operate even larger numbers. A limit of 1000 digits is so small... You have to find the sum of two numbers with maximal size of 1.000.000 digits.
Input

The first line of an input file contains a single number N (1<=N<=1000000) - the length of the integers (in order to make their lengths equal, some leading zeroes can be added). It is followed by these integers written in columns. That is, the next N lines contain two digits each, divided by a space. Each of the two given integers is not less than 1, and the length of their sum does not exceed N.

Output

Output file should contain exactly N digits in a single line representing the sum of these two integers.

Sample Input

4
0 4
4 2
6 8
3 7

Sample Output

4750
Hint

Huge input,scanf is recommended.

Source

Ural State University collegiate programming contest 2000

"""

def supersum(a):
    r = []
    c = 0
    for i in range(len(a) - 1, -1, -1):
        v = a[i][0] + a[i][1] + c
        c = v // 10
        r.append(v % 10)
    
    if c > 0:
        r.append(c)

    return r[::-1]

def main():
    assert(supersum([[0, 4], [4, 2], [6, 8], [3, 7]]) == [4, 7, 5, 0])
    assert(supersum([[9, 9], [9, 9]]) == [1, 9, 8])

main()
