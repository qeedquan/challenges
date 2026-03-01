#!/usr/bin/env python3

"""

Write a piece of code that is executable in at least three different languages. The code must output the integer 1 in language number one, 2 in language number two, 3 in language number three etc.

Rules:

The output must be only the integer, but trailing newlines are OK.
The code can't take input of any kind
Different major versions of the same language are considered unique. So, your code can be executable in Python 2 and Python 3, however Python 2.5 and Python 2.7 are not considered unique.
You may use a new language if and only if it has an esolang/wiki article, available interpreter and documentation, and has been used by at least two users on PPCG prior to using it in this challenge. It must also adhere to these 4 rules.
The score of your submission is the number of bytes in your code divided by the number of languages it can run in cubed. So, a 54 byte solution that is executable in 3 languages will have a score of 2:

54 / 3^3 = 2
Lower score is better.

"""

import sys

print(sys.version[0])
