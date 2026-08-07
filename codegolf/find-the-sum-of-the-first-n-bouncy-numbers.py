#!/usr/bin/env python3

"""

Terminology

An increasing number is one where each digit is greater than or equal to all the digits to the left of it (ex. 12239)

A decreasing number is one where each digit is less than or equal to all the digits to the left of it (ex. 95531)

A bouncy number is any number that is not increasing or decreasing. Since this requires at least 3 digits, the first bouncy number is 101

The task

Given an integer n greater than or equal to 1, find the sum of the first n bouncy numbers

Rules

This is code golf, so the answer with the shortest amount of bytes wins
If your language has limits on integer size (ex. 2^32-1) n will be small enough that the sum will fit in the integer
Input can be any reasonable form (stdin, file, command line parameter, integer, string, etc)
Output can be any reasonable form (stdout, file, graphical user element that displays the number, etc)
Test cases

1 > 101
10 > 1065
44701 > 1096472981

"""

# https://oeis.org/A319744
def gen(n):
    r = []
    for i in range(1, n + 1):
        a = i
        b = 0
        c = 0
        while a != 0:
            s = ''.join(sorted(str(b)))
            if s != str(b) and s[::-1] != str(b):
                c += b
                a -= 1
            b += 1
        r.append(c)
    return r

def main():
    tab = [101, 203, 306, 410, 515, 621, 728, 836, 945, 1065, 1186, 1316, 1447, 1579, 1719, 1860, 2002, 2145, 2295, 2446, 2598, 2751, 2905, 3065, 3226, 3388, 3551, 3715, 3880, 4050, 4221, 4393, 4566, 4740, 4915, 5091, 5271, 5452, 5634, 5817, 6001, 6186, 6372, 6559, 6749, 6940, 7132, 7325, 7519]

    assert(gen(len(tab)) == tab)

main()
