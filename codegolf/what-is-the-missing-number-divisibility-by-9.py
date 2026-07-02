#!/usr/bin/env python3

"""

Challenge
Given a whole number divisible by 9 and one missing digit, find the missing digit.

The missing digit may be represented by any character other than the digits 0-9 as long as it is consistent.

If the missing digit could be 0 or 9, output something to signify so.

Assume the user is intelligent enough to put only one missing digit and one number etc.

Test Cases
In the test cases the missing digit is represented by a question mark

123? -> 3
?999 -> 0 or 9
?0023 -> 4
000?1 -> 8

"""

def solve(s):
    s = s.replace('?', 'I')
    x = -int(s, 19)
    return x % 9

def main():
    assert(solve("123?") == 3)
    assert(solve("?999") == 0)
    assert(solve("?0023") == 4)
    assert(solve("000?1") == 8)

main()
