#!/usr/bin/env python3

"""

Write the shortest function that takes one string, and returns a regular expression that matches anything EXCEPT the input string, in parenthesis. Escape necessary characters like Perl quotemeta.

Input:
  helloworld
Output:
  ([^h]|h[^e]|he[^l]|hel[^l]|hell[^o]|hello[^w]|hellow[^o]|hellowo[^r]|hellowor[^l]|helloworl[^d])
Input:
  */
Output:
  ([^\*]|\*[^\/])
See also:

http://yannesposito.com/Scratch/en/blog/2010-02-15-All-but-something-regexp/
http://shinkirou.org/blog/2010/12/tricky-regular-expression-problems/

"""

import re

"""

@JBernardo

The answer matches anything but the input. It gives an output using conditional groups so is suited for the problem:
regular expression that matches anything EXCEPT the input string

"""

def negative(s):
    return '(^(?!%s$).*$)' % re.escape(s)

def main():
    print(negative("helloworld"))
    print(negative("*/"))

main()
