#!/usr/bin/env python3

r"""

It is kind of quine.

You should write a program or function that receives a positive integer N as input and prints out Nth line of your code. If N is larger than number of lines of your code, then you have two options.

Your code must not print any single byte.
Your code must print newline character \n. (what is output of print() of Python.)
You should apply the same options for all N's. For example, if you write an 8-line code that prints a newline character when N=9 and prints nothing when N=10, that's not what I want.

Winning Criteria
Length of code must be shorter than 1<<12 = 4096 Bytes.

The person who wrote the most non-empty lines wins. If tie, then author of shorter code wins.

Example) Python3, 117 Bytes, 1 Non-empty line
Below is the sample code written by wlaud. It chose option 2.

print('print({0!r}.format({0!r})*(input()=="1"))'.format('print({0!r}.format({0!r})*(input()=="1"))')*(input()=="1"))
Try it online!

Clarification
Your code must be not empty, that is, at least 1 byte long.

"""

print('print({0!r}.format({0!r})*(input()=="1"))'.format('print({0!r}.format({0!r})*(input()=="1"))')*(input()=="1"))

