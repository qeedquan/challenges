#!/usr/bin/env python3

r"""

You have a function that takes an integer n and returns a list of length n of function objects that
take an integer x and return x multiplied by the index of that object in this list(remember that in python the indexes of elements start from 0):

[f_0, f_1, ... f_n]
f_0 returns x * 0,
f_1 returns x * 1,
...
f_n returns x * n,

def create_multiplications(n):
    return [lambda x : i * x for i in range(n)]

This code:

for m in create_multiplications(3):
    print(m(3), ' ... ')

should output:

>>> 0 ... 3 ... 6 ...

But it outputs:

>>> 6 ... 6 ... 6 ...

You need to fix this bug.

Input/Output
All inputs will be integers, output must be list of function objects.

Good luck!

Please rate this kata.

"""

def create_multiplications(n):
    return [lambda x, i=i: i*x for i in range(n)]

for m in create_multiplications(3):
    print(m(3), '...')

