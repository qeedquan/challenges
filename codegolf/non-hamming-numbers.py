#!/usr/bin/env python3

"""

Hamming number (also known as regular number) is a number that evenly divides powers of 60. We already have a task to do something with it. This time we are going to do the opposite.

I define non-Hamming number as in: n is non-Hamming number if and only if it satisfies following two conditions:

n is positive integer, and n does not divide powers of 60 evenly; i.e. 60^m mod n ≠ 0 for all positive integer m.
Make a program, a function, or a subroutine that does one of these:

takes no input to print/return/generate a list of non-Hamming numbers infinitely, or
takes a positive integer n as input to print/return/generate nth non-Hamming number (can be either 0-indexed or 1-indexed), or takes a positive integer n as input to print/return/generate a list of first n non-Hamming numbers.
4. takes a positive integer n to print/return/generate non-Hamming number until n (suggested by @Wasif, can be inclusive or not; i.e. non-Hamming numbers that are either <n or ≤n). abolished by @rak1507.

Example
This example shows how program/function/subroutine that does 3rd task should work:

Input: 5
Output: 7, 11, 13, 14, 17

Rules
I/O method is done by your desired format.
If you are answering one of 2nd or 3rd task, you can assume that input is a non-negative integer.
No external resources.
Standard loopholes apply.
If your program/function/subroutine fails to output huge non-Hamming numbers because of overflow (or similar boundary) but is theotically valid, it is acceptable.
Shortest code in bytes wins. However, if someone have won entire of this post, you can still try to win among languages and tasks.

P.S.
It's actually A279622.

"""

from sympy import *

# https://oeis.org/A279622
def nonhamming(n):
    if n < 2:
        return False
    p = list(factorint(n))
    return max(p) > 5

def gen(n):
    r = []
    i = 2
    while len(r) < n:
        if nonhamming(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [7, 11, 13, 14, 17, 19, 21, 22, 23, 26, 28, 29, 31, 33, 34, 35, 37, 38, 39, 41, 42, 43, 44, 46, 47, 49, 51, 52, 53, 55, 56, 57, 58, 59, 61, 62, 63, 65, 66, 67, 68, 69, 70, 71, 73, 74, 76, 77, 78, 79, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94]

    assert(gen(len(tab)) == tab)

main()
