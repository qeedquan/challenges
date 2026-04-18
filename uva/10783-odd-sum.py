#!/usr/bin/env python3

"""

Given a range [a, b], you are to find the summation of all the odd integers in this range. For example,
the summation of all the odd integers in the range [3, 9] is 3 + 5 + 7 + 9 = 24.

Input
There can be at multiple test cases. The first line of input gives you the number of test cases, T
(1 ≤ T ≤ 100). Then T test cases follow. Each test case consists of 2 integers a and b (0 ≤ a ≤ b ≤ 100)
in two separate lines.

Output
For each test case you are to print one line of output – the serial number of the test case followed by
the summation of the odd integers in the range [a, b].

Sample Input
2
1
5
3
5

Sample Output
Case 1: 9
Case 2: 8

"""

def oddsum(a, b):
    if b < a:
        a, b = b, a

    x = a // 2
    y = (b + 1) // 2
    return y**2 - x**2

def oddsumbf(a, b):
    if b < a:
        a, b = b, a

    if a%2 == 0 and a == b:
        return 0

    r = 0
    i = a
    while i <= b:
        if i%2 == 0:
            i += 1
        r += i
        i += 2
    return r

def main():
    assert(oddsum(0, 9) == 25)
    assert(oddsum(3, 9) == 24)
    assert(oddsum(1, 5) == 9)
    assert(oddsum(3, 5) == 8)

    n = 100
    for a in range(-n, n + 1):
        for b in range(-n, n + 1):
            assert(oddsum(a, b) == oddsumbf(a, b))

main()

