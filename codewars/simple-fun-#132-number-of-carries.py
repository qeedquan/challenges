#!/usr/bin/env python3

"""

Task
Two integer numbers are added using the column addition method. When using this method, some additions of digits produce non-zero carries to the next positions. Your task is to calculate the number of non-zero carries that will occur while adding the given numbers.

The numbers are added in base 10.

Example
For a = 543 and b = 3456, the output should be 0

For a = 1927 and b = 6426, the output should be 2

For a = 9999 and b = 1, the output should be 4

Input/Output
[input] integer a
A positive integer.

Constraints: 1 ≤ a ≤ 10^7

[input] integer b
A positive integer.

Constraints: 1 ≤ b ≤ 10^7

[output] an integer


"""

def carries(a, b):
    r, c = 0, 0
    while a != 0 or b != 0:
        v = (a % 10) + (b % 10) + c
        c = 0
        if v >= 10:
            c = 1
        r += c
        a //= 10
        b //= 10
    return r

def main():
    assert(carries(999, 1) == 3)
    assert(carries(348, 91) == 1)
    assert(carries(398, 91) == 1)
    assert(carries(348, 51) == 0)
    assert(carries(348, 52) == 2)
    assert(carries(5, 15) == 1)
    assert(carries(999, 999) == 3)
    assert(carries(505, 505) == 2)
    assert(carries(123, 456) == 0)
    assert(carries(555, 555) == 3)
    assert(carries(123, 594) == 1)
    assert(carries(543, 3456) == 0)
    assert(carries(1927, 6426) == 2)
    assert(carries(9999, 1) == 4)

main()
