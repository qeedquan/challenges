#!/usr/bin/env python3

"""

Introduction
A xenodrome in base n is an integer where all of its digits in base n are different. Here are some OEIS sequences of xenodromes.

For example, in base 16, FACE, 42 and FEDCBA9876543210 are some xenodromes (Which are 64206, 66 and 18364758544493064720 in base 10), but 11 and DEFACED are not.

Challenge
Given an input base, n, output out all xenodromes for that base in base 10.

The output should be in order of least to greatest. It should be clear where a term in the sequence ends and a new one begins (e.g. [0, 1, 2] is clear where 012 is not.)

n will be an integer greater than 0.

Clarifications
This challenge does IO specifically in base 10 to avoid handling integers and their base as strings. The challenge is in abstractly handling any base. As such, I am adding this additional rule:

Integers cannot be stored as strings in a base other than base 10.

Your program should be able to theoretically handle reasonably high n if there were no time, memory, precision or other technical restrictions in the implementation of a language.

This is code-golf, so the shortest program, in bytes, wins.

Example Input and Output
1  # Input
0  # Output
2
0, 1, 2
3
0, 1, 2, 3, 5, 6, 7, 11, 15, 19, 21
4
0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14, 18, 19, 24, 27, 28, 30, 33, 35, 36, 39, 44, 45, 49, 50, 52, 54, 56, 57, 75, 78, 99, 108, 114, 120, 135, 141, 147, 156, 177, 180, 198, 201, 210, 216, 225, 228

"""

def xenodrome(n):
    r = []
    for x in range(n**n):
        m = {n}
        a = x
        while ({a % n} | m) > m:
            m.add(a % n)
            a //= n
        s = (1 - a) * repr(x)
        if s != "":
            r.append(int(s))
    return r

def main():
    assert(xenodrome(1) == [0])
    assert(xenodrome(2) == [0, 1, 2])
    assert(xenodrome(3) == [0, 1, 2, 3, 5, 6, 7, 11, 15, 19, 21])
    assert(xenodrome(4) == [0, 1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14, 18, 19, 24, 27, 28, 30, 33, 35, 36, 39, 44, 45, 49, 50, 52, 54, 56, 57, 75, 78, 99, 108, 114, 120, 135, 141, 147, 156, 177, 180, 198, 201, 210, 216, 225, 228])

main()
