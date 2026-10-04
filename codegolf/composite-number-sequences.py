#!/usr/bin/env python3

"""

Inspired by this question
https://codegolf.stackexchange.com/questions/56006/calculate-an-bn-with-cn-digits

Given a positive integer n, your code must output the first n composite numbers.

Input / Output

You may write a program or a function. Input is through STDIN or function argument and output is to STDOUT, or function return value.

Output can be a List, Array, or String.

Examples

 0 ->
 1 -> 4
 2 -> 4, 6
 3 -> 4, 6, 8
13 -> 4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22
Rules
As always standard loopholes are disallowed.

Built-ins that generate prime or composite numbers are not allowed.

Built-ins relating to prime or composite numbers are not allowed.

"""

from sympy import isprime

# https://oeis.org/A002808
def gen(n):
    r = []
    i = 2
    while len(r) < n:
        if not isprime(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [
        4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 26, 27, 28, 30,
        32, 33, 34, 35, 36, 38, 39, 40, 42, 44, 45, 46, 48, 49, 50, 51, 52, 54,
        55, 56, 57, 58, 60, 62, 63, 64, 65, 66, 68, 69, 70, 72, 74, 75, 76, 77,
        78, 80, 81, 82, 84, 85, 86, 87, 88
    ]

    assert(gen(len(tab)) == tab)

main()
