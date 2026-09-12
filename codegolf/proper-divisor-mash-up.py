#!/usr/bin/env python3

"""

A proper divisor is a divisor of a number n, which is not n itself. For example, the proper divisors of 12 are 1, 2, 3, 4 and 6.

You will be given an integer x, x ≥ 2, x ≤ 1000. Your task is to sum all the highest proper divisors of the integers from 2 to x (inclusive) (OEIS A280050).

Example (with x = 6):
Find all the integers between 2 and 6 (inclusive): 2,3,4,5,6.

Get the proper divisors of all of them, and pick the highest ones from each number:

2 -> 1
3 -> 1
4 -> 1, 2
5 -> 1
6 -> 1, 2, 3.
Sum the highest proper divisors: 1 + 1 + 2 + 1 + 3 = 8.

The final result is 8.

Test Cases
Input  |  Output
-------+---------
       |
 2     | 1
 4     | 4
 6     | 8
 8     | 13
 15    | 41
 37    | 229
 100   | 1690
 1000  | 165279

Rules
Default Loopholes apply.

You can take input and provide output by any standard method.

This is code-golf, the shortest valid submission in each language wins! Have Fun!

"""

from sympy import factorint

# https://oeis.org/A020639
def lpf(n):
    if n < 1:
        return 0
    if n == 1:
        return 1
    return min(factorint(n))

# https://oeis.org/A280050
def sdlpf(n):
    r = 0
    for i in range(2, n + 1):
        r += i//lpf(i)
    return r

def main():
    lpftab = [1, 2, 3, 2, 5, 2, 7, 2, 3, 2, 11, 2, 13, 2, 3, 2, 17, 2, 19, 2, 3, 2, 23, 2, 5, 2, 3, 2, 29, 2, 31, 2, 3, 2, 5, 2, 37, 2, 3, 2, 41, 2, 43, 2, 3, 2, 47, 2, 7, 2, 3, 2, 53, 2, 5, 2, 3, 2, 59, 2, 61, 2, 3, 2, 5, 2, 67, 2, 3, 2, 71, 2, 73, 2, 3, 2, 7, 2, 79, 2, 3, 2, 83, 2, 5, 2, 3, 2, 89, 2, 7, 2, 3, 2, 5, 2, 97]

    sdlpftab = [0, 1, 2, 4, 5, 8, 9, 13, 16, 21, 22, 28, 29, 36, 41, 49, 50, 59, 60, 70, 77, 88, 89, 101, 106, 119, 128, 142, 143, 158, 159, 175, 186, 203, 210, 228, 229, 248, 261, 281, 282, 303, 304, 326, 341, 364, 365, 389, 396, 421, 438, 464, 465, 492, 503, 531, 550, 579, 580, 610, 611, 642, 663, 695, 708, 741, 742, 776, 799, 834, 835]

    for i in range(len(lpftab)):
        assert(lpf(i + 1) == lpftab[i])

    for i in range(len(sdlpftab)):
        assert(sdlpf(i + 1) == sdlpftab[i])

main()
