#!/usr/bin/env python3

"""

Much cooler than your run-of-the-mill Fibonacci numbers, the Triple Shiftian are so defined: T[n] = 4 * T[n-1] - 5 * T[n-2] + 3 * T[n-3].

You are asked to create a function which accept a base with the first 3 numbers and then returns the nth element.

tripleShiftian([1,1,1],25) == 1219856746
tripleShiftian([1,2,3],25) == 2052198929
tripleShiftian([6,7,2],25) == -2575238999
tripleShiftian([3,2,1],35) == 23471258855679
tripleShiftian([1,9,2],2) ==  2

Note: this is meant to be an interview quiz, so the description is scarce in detail on purpose

Special thanks to the first person I met in person here in London just because of CW ( http://www.codewars.com/users/webtechalex ) and that assisted me during the creation of this kata ;)

"""

def triple_shiftian(x, n):
    if n < 0:
        return 0

    if n < 3:
        return x[n]
    
    a, b, c = x[0], x[1], x[2]
    for i in range(3, n + 1):
        a, b, c = b, c, 4*c - 5*b + 3*a
    return c

def main():
    assert(triple_shiftian([1, 1, 1], 25) == 1219856746)
    assert(triple_shiftian([1, 2, 3], 25) == 2052198929)
    assert(triple_shiftian([6, 7, 2], 25) == -2575238999)
    assert(triple_shiftian([3, 2, 1], 35) == 23471258855679)
    assert(triple_shiftian([1, 9, 2], 2) == 2)

main()
