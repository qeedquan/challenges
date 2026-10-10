#!/usr/bin/env python3

"""

Your task
Take a list of strings as the input, and output the maximum average ord.

Example
Given the list ['hello', 'world', 'bye']:

The average ord of 'hello' is:
(ord(h) + ord(e) + ord(l) + ord(l) + ord(o)) / len('hello')
= 106.4
The average ord of 'world' = 110.4
The average ord of 'bye' = 106.7
The maximum average ord is 110.4. This is your output.

Test cases
Note: For the last two test cases, I have given the roundings for 1, 2, and 3 decimal places. As mentioned in the rules below, you can round to any number of decimal places.

Input                                        Output
['hello', 'world', 'bye']                    110.4
['code', 'golf', 'stack', 'exchange']        106.8
['!@#', '$%^', '&*(']                        55.7 / 55.67 / 55.667 / etc.
['qwertyuiop[', 'asdfghjkl;', 'zxcvbnm,']    110.9 / 110.91 / 110.909 / etc.
Rules/clarifications
The output must be only the average ord. You may not output anything else.
It may be rounded (up or down) to any number (≥ 1) of decimal places. If your language does not support floating points, you may output the average multiplied by 10.
Floating point innacuracies are ok.
You may assume that the input list will always have a length of 2 or more
You may assume that the strings will never be empty
You may assume that the strings will not contain whitespace or non-ASCII characters
This is code-golf, so shortest code in bytes wins!

"""

def ao(s):
    r = 0
    for c in s:
        r += ord(c)
    return r/len(s)

def maxao(l):
    r = 0
    for s in l:
        r = max(r, ao(s))
    return r

def test(l, r):
    v = maxao(l)
    print(v, r)
    assert(abs(v-r) < 1e-3)

def main():
    test(['hello', 'world', 'bye'], 110.4)
    test(['code', 'golf', 'stack', 'exchange'], 106.8)
    test(['!@#', '$%^', '&*('], 55.667)
    test(['qwertyuiop[', 'asdfghjkl;', 'zxcvbnm,'], 110.909)

main()
