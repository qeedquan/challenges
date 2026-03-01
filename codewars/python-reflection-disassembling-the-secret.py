#!/usr/bin/env python3

"""

There is a string of 32 alphanumeric characters hidden inside a dynamically generated function, which will then be passed into your function.

Your task is to recover this string and return it.

"""

def find_the_secret(f):
    for string in f.__code__.co_consts:
        if isinstance(string, str) and len(string) == 32:
            return string

def f():
    s = "ke" * 16
    if random() == 0:
        return s
    return None

print(find_the_secret(f))

