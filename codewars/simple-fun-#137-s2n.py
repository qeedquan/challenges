#!/usr/bin/env python3

"""

Task
Your task is to find the sum for the range 0 ... m for all powers from `0 ... n.

Example
For m = 2, n = 3, the result should be 20

0^0+1^0+2^0 + 0^1+1^1+2^1 + 0^2+1^2+2^2 + 0^3+1^3+2^3 = 20

Note, that no output ever exceeds 2e9.

Input/Output
[input] integer m
0 <= m <= 50000

[input] integer n
0 <= n <= 9

[output] an integer(double in C#)
The sum value.

"""

def s2n(m, n):
    r = 0
    for i in range(n + 1):
        for j in range(m + 1):
            r += j**i
    return r

def main():
    assert(s2n(2, 3) == 20)
    assert(s2n(3, 5) == 434)
    assert(s2n(10, 9) == 1762344782)
    assert(s2n(1, 1) == 3)
    assert(s2n(0, 0) == 1)
    assert(s2n(300, 2) == 9090501)
    assert(s2n(567, 2) == 61083856)
    assert(s2n(37, 4) == 15335280)
    assert(s2n(36, 4) == 13409059)

main()
