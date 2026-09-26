#!/usr/bin/env python3

"""

We are given a list of integers p1, ..., pk (not necessarily distinct) where each has a value between 1 and 9, inclusive. Using each of the p1, ..., pk exactly once, we can form concatenations of digits, to achieve a new list of numbers; we then output the product of this new list. The goal is to maximize this product by choosing the best concatenations of digits.

For example, we are given the list: 2 3 2 (separated by spaces). We can form the following concatenations:

2 3 2 (product of these concatenations is 12)
23 2 (product is 46)
32 2 (product is 64)
22 3 (product is 66)
Since the largest product that we can form of concatenations is 66, we output that.

Rules:

There must be at least one multiplication (i.e., you cannot just concatenate all of the digits and output that).
You cannot use any other operators other than multiplication, or insert parentheses, etc.
Assume that the list of integers given is separated by spaces, and all integers have values between 1 and 9.
Shortest code (in bytes) wins!

Test cases:

Input: 1 2 3; Output: 63 (i.e., 21*3)

Input: 2 5 9; Output: 468 (52*9)

Input: 1 2 3 4; Output: 1312 (41*32)

"""

"""

@Oberon

edc65 has already explained that the optimal solution can be found applying a single multiplication.
thus, given that
(10x + d)y > (10y + d)x
where x, y are the two numbers and d is the next digit to insert, it follows that y > x
and thus each new digit must be concatenated to the smallest number. obviously, digits
should be added in descending order.

"""

def mcp(a):
    a = sorted(a, reverse=True)
    m = [0, 0]
    for x in a:
        i = m[0] > m[1]
        m[i] = m[i]*10 + x
    return m[0] * m[1]

def main():
    assert(mcp([2, 3, 2]) == 66)
    assert(mcp([1, 2, 3]) == 63)
    assert(mcp([2, 5, 9]) == 468)
    assert(mcp([1, 2, 3, 4]) == 1312)

main()
