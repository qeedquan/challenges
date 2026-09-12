#!/usr/bin/env python3

"""

Task

Given two positive integers (dividend and divisor), calculate the quotient and the remainder.
Normally it would be calculated as e = o*q+r where q*o<=e and 0<=r<o.
For this challenge it still e = o*q+r but q*o>=e and -o<r<=0.
For example e=20 and o=3, normally it would be 20/3 -> 20=3*6+2, since 18<=20 and 0<=2<3. Here it will be 20/3 -> 20=3*7-1 where 21>=20 and -3<-1<=0

Test Cases
Input -> Output
20, 3 -> 7, -1
10, 5 -> 2, 0
7, 20 -> 1, -13
100, 13 -> 8, -4
You don't need to handle o=0.

"""

def upper_divmod(a, b):
    if b == 0:
        return (0, 0)
    return (-(a//-b), a%-b)

def main():
    assert(upper_divmod(20, 3) == (7, -1))
    assert(upper_divmod(10, 5) == (2, 0))
    assert(upper_divmod(7, 20) == (1, -13))
    assert(upper_divmod(100, 13) == (8, -4))

main()
