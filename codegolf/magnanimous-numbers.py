#!/usr/bin/env python3

"""

Given an positive integer as input determine if it is a magnanimous number.

A magnanimous number is a number such that any insertion of a + sign between any two digits in base 10 results in an expression of a prime integer.

For example 40427 is magnanimous because

4+0427  = 431  is prime
40+427  = 467  is prime
404+27  = 431  is prime
4042+7  = 4049 is prime
Output
You should output two distinct values, one when the input is magnanimous and one when the input is not.

Scoring
The goal of this contest will be to make the size of the source code written to solve this task, given in bytes, as small as possible.

Test Cases
1       -> True
2       -> True
4       -> True
10      -> False
98      -> True
101     -> True
109     -> False
819     -> False
4063    -> True
40427   -> True
2000221 -> True

OEIS 253996

"""

from sympy import isprime

# https://oeis.org/A252996
def magnanimous(n):
    if n < 0:
        return False
    if n < 10:
        return True

    s = str(n)
    for i in range(1, len(s)):
        x = int(s[:i])
        y = int(s[i:])
        if not isprime(x + y):
            return False
    return True

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if magnanimous(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 14, 16, 20, 21, 23, 25, 29, 30, 32, 34, 38, 41, 43, 47, 49, 50, 52, 56, 58, 61, 65, 67, 70, 74, 76, 83, 85, 89, 92, 94, 98, 101, 110, 112, 116, 118, 130, 136, 152, 158, 170, 172, 203, 209, 221, 227, 229, 245, 265, 281, 310, 316, 334, 338, 356]

    assert(gen(len(tab)) == tab)
    assert(magnanimous(819) == False)
    assert(magnanimous(4063) == True)
    assert(magnanimous(40427) == True)
    assert(magnanimous(2000221) == True)

main()
