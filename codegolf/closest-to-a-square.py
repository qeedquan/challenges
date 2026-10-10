#!/usr/bin/env python3

"""

The task
Given a positive integer c, output two integers a and b where a * b = c and each a and b is closest to sqrt(c) while still being integers.

Test cases

Input: 136
Output: 17 8

Input: 144
Output: 12 12

Input: 72
Output: 9 8

Input: 41
Output: 41 1

Input: 189
Output: 21 9

Rules
a, b and c are all positive integers
You may give a and b in any order, so for the first case an output of 8 17 is also correct
This is code-golf, so lowest byte count wins!

"""

"""

https://oeis.org/A033676 (lower number)
https://oeis.org/A033677 (higher number)

"""

def solve(n):
    if n < 1:
        return (0, 0)
    i = n
    while i*i > n or n%i != 0:
        i -= 1
    return (n//i, i)

def main():
    A033676 = [
        1, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 3, 1, 2, 3, 4, 1, 3, 1, 4, 3, 2, 1, 4,
        5, 2, 3, 4, 1, 5, 1, 4, 3, 2, 5, 6, 1, 2, 3, 5, 1, 6, 1, 4, 5, 2, 1, 6,
        7, 5, 3, 4, 1, 6, 5, 7, 3, 2, 1, 6, 1, 2, 7, 8, 5, 6, 1, 4, 3, 7, 1, 8,
        1, 2, 5, 4, 7, 6, 1, 8
    ]

    A033677 = [
        1, 2, 3, 2, 5, 3, 7, 4, 3, 5, 11, 4, 13, 7, 5, 4, 17, 6, 19, 5, 7, 11,
        23, 6, 5, 13, 9, 7, 29, 6, 31, 8, 11, 17, 7, 6, 37, 19, 13, 8, 41, 7,
        43, 11, 9, 23, 47, 8, 7, 10, 17, 13, 53, 9, 11, 8, 19, 29, 59, 10, 61,
        31, 9, 8, 13, 11, 67, 17, 23, 10, 71, 9, 73, 37, 15, 19, 11, 13, 79, 10
    ]

    for i in range(len(A033676)):
        assert(solve(i + 1) == (A033677[i], A033676[i]))

    assert(solve(136) == (17, 8))
    assert(solve(144) == (12, 12))
    assert(solve(72) == (9, 8))
    assert(solve(41) == (41, 1))

main()
