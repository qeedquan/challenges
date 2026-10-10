#!/usr/bin/env python3

"""

An eviternity number is a number which:

contains only digits 8, 5 and 3, and
the count of the digit 8 >= count of digit 5 >= count of digit 3.
The first few eviternity numbers are as follows.

[8, 58, 85, 88, 358, 385, 538, 583, 588, 835, 853, 858, 885, 888]
You will be given two integers, a and b, and your task is to return the number of eviternity numbers in the range >= a and < b.

For example:
a=0, b=1000 => 14, because they are [8, 58, 85, 88, 358, 385, 538, 583, 588, 835, 853, 858, 885, 888]
The upper bound will not exceed 500,000.

More examples in test cases. Good luck!

"""

def eviternity(n):
    if n < 1:
        return False

    c = [0, 0, 0]
    while n > 0:
        d = n % 10
        if d == 8:
            c[2] += 1
        elif d == 5:
            c[1] += 1
        elif d == 3:
            c[0] += 1
        else:
            return False
        n //= 10
    return c[0] <= c[1] and c[1] <= c[2]

def count(a, b):
    c = 0
    for i in range(a, b):
        if eviternity(i):
            c += 1
    return c

def main():
    assert(count(0, 100) == 4)
    assert(count(0, 1000) == 14)
    assert(count(0, 10000) == 37)
    assert(count(0, 100000) == 103)

main()
