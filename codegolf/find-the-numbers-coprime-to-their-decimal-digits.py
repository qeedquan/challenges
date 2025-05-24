#!/usr/bin/env python3

"""

Two numbers are coprime if their greatest common divisor is 1.

Given a positive integer N, your task is to compute the first N terms of OEIS A061116, which is the sequence of positive integers higher than 1 that are coprime to all their decimal digits.

Here are the first few terms of the sequence:

11, 13, 17, 19, 21, 23, 27, 29, 31, 37, 41, 43, 47, 49, 51, 53, 57, 59, 61, 67, 71
You can assume that N < 200.

Test Cases
Input -> Output

1 -> 11
3 -> 11, 13, 17
6 -> 11, 13, 17, 19, 21, 23
25 -> 11, 13, 17, 19, 21, 23, 27, 29, 31, 37, 41, 43, 47, 49, 51, 53, 57, 59, 61, 67, 71, 73, 79, 81, 83
You may output in any decent form (as a list, with a separator or whatever else). You can take input as the String representation of N or as an integer. Standard I/O rules apply.

Default Loopholes apply. This is code-golf, so the shortest code in bytes wins!

"""

from math import gcd

# https://oeis.org/A061116
def digcop(n):
    if n <= 1:
        return False
    return all(gcd(n, int(d)) == 1 for d in str(n))

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if digcop(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [11, 13, 17, 19, 21, 23, 27, 29, 31, 37, 41, 43, 47, 49, 51, 53, 57, 59, 61, 67, 71, 73, 79, 81, 83, 87, 89, 91, 97, 111, 113, 117, 119, 121, 127, 131, 133, 137, 139, 141, 143, 149, 151, 157, 161, 163, 167, 169, 171, 173, 177, 179, 181, 187, 191, 193, 197, 199, 211]

    assert(gen(len(tab)) == tab)

main()
