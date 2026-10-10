#!/usr/bin/env python3

"""

Given a positive integer as input, output the smallest positive integer such that appending its digits (in base 10) to the end of the input number will form a prime number.

Examples
1     -->   1
2     -->   3
8     -->   3
9     -->   7
11    -->   3
20    -->  11
43    -->   1
134   -->  11
3492  -->  11
3493  -->   9
65595 -->  19

Rules and Scoring
This is code golf, so shortest code wins
Standard rules and loopholes apply
Use any convenient I/O format
The largest concatenated number (which is larger than both the input and output) your solution supports must be at least 2^53−1. (This is the largest odd integer that can be represented with double precision floats)
Leading zeros should not be added to numbers before appending them to the input number
Primality tests must be exact

"""

from sympy import isprime

"""

https://oeis.org/A068695
https://math.stackexchange.com/questions/60825/proof-that-there-are-infinitely-many-prime-numbers-starting-with-a-given-digit-s

"""

def solve(n):
    i = 1
    while True:
        p = int(str(n) + str(i))
        if isprime(p):
            return i
        i += 1

def main():
    tab = [
        1, 3, 1, 1, 3, 1, 1, 3, 7, 1, 3, 7, 1, 9, 1, 3, 3, 1, 1, 11, 1, 3, 3,
        1, 1, 3, 1, 1, 3, 7, 1, 17, 1, 7, 3, 7, 3, 3, 7, 1, 9, 1, 1, 3, 7, 1,
        9, 7, 1, 3, 13, 1, 23, 1, 7, 3, 1, 7, 3, 1, 3, 11, 1, 1, 3, 1, 3, 3, 1,
        1, 9, 7, 3, 3, 1, 1, 3, 7, 7, 9, 1, 1, 9, 19, 3, 3, 7, 1, 23, 7, 1, 9,
        7, 1, 3, 7, 1, 3, 1, 9, 3, 1
    ]

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

    assert(solve(1) == 1)
    assert(solve(2) == 3)
    assert(solve(8) == 3)
    assert(solve(9) == 7)
    assert(solve(11) == 3)
    assert(solve(20) == 11)
    assert(solve(43) == 1)
    assert(solve(134) == 11)
    assert(solve(3492) == 11)
    assert(solve(3493) == 9)
    assert(solve(65595) == 19)

main()

