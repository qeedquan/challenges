#!/usr/bin/env python3

"""

Your program must find the longest sequence of consecutive zeroes in an integer number.

For example, the number 10002030000 has three sequences of zeroes with lengths 3, 1 and 4. So the longest sequence is 4.

Input :
A positive integer

Output :
The max number of consecutive zeros in that number

Restrictions :
Do it in less than 60 (59 or less) chars.

Note :
The number will always have 1 or more zeroes

"""

def f(n):
    if n < 0:
        n = abs(n)
    if n == 0:
        return 1

    m = 0
    z = 0
    while n != 0:
        if n%10 == 0:
            z += 1
        else:
            z = 0
        m = max(m, z)
        n //= 10
    return m

def main():
    assert(f(1002000) == 3)
    assert(f(10002030000) == 4)
    assert(f(10) == 1)

main()
