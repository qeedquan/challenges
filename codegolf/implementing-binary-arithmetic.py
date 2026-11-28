#!/usr/bin/env python3

"""

Given two binary numbers (strings containing 0s and 1s), perform operations on them, with one problem: You must keep them in binary. That means no going binary(integer(n1)+integer(n2)) or anything like that.

Input: Two binary numbers, n1 and n2, and a number between 0 and 3, o, defining the operator. The two binary numbers will be the same length.

Output: If o is 0, return n1+n2 as a binary number.
If o is 1, return n1-n2 as a binary number.
If o is 2, return n1*n2 as a binary number.
If o is 3, return n1/n2 as a binary number, using floor division.
The output will not be the same length as the input. Please truncate all leading zeros.

If you implement Two's Complement, subtract 10% off your character count, up to a limit of 50. Truncate to length(n1)+length(n2) digits.

Test Cases:
n1=01010, n2=10101, o=0: 11111
n1=11110, n2=01010, o=1: 10100
n1=0010, n2=1000, o=2: 10000
n1=1011010, n2=0010001, o=3: 101

Shortest code wins. Good luck!

"""

# Ported from @Keith Randall solution

PAD = '0' * 32

def add(x, y):
    r = ""
    carry = '0'
    for left, right in zip(x + PAD, y + PAD):
        index = (left + right + carry).count('1')
        r += "0101"[index]
        carry = "0011"[index]
    return r[:32]

def sub(x, y):
    yinv = "".join(chr(ord(bit) ^ 1) for bit in y + PAD)
    return add(add(x, yinv), '1')

def mul(x, y):
    r = ""
    while y:
        if y[0] == '1':
            r = add(r, x)
        x = '0' + x
        y = y[1:]
    return r

def div(x, y):
    x = (x + PAD)[:32]
    y = (y + PAD)[:32]
    r = ""
    while x[::-1] >= y[::-1]:
        r = add(r, '1')
        x = sub(x, y)
    return r


def apply(x, y, operation):
    functions = [add, sub, mul, div]
    r = functions[operation](x, y).rstrip('0')
    r = r[: len(x) + len(y)]
    return r or '0'

assert(apply('01010', '10101', 0) == '11111')
assert(apply('01111', '01010', 1) == '00101')
assert(apply('0100', '0001', 2) == '00001')
assert(apply('0101101', '1000100', 3) == '101')

