#!/usr/bin/env python3

r"""

Write a timer() decorator that validates if a function it decorates is executed within (less than) a given seconds interval and returns a boolean True or False accordingly.

Example:

from time import sleep

@timer(1)
def foo():
    sleep(0.1)

@timer(1)
def bar():
    sleep(1.1)


>>> foo()
True

>>> bar()
False

"""

import time

def timer(limit):
    def decorator(func):
        def wrapper(*args, **kwargs):
            start = time.time()
            func(*args, **kwargs)
            end = time.time()
            return end-start < limit
        return wrapper
    return decorator

@timer(1)
def foo():
    time.sleep(0.1)

@timer(1)
def bar():
    time.sleep(1.1)

def main():
    assert(foo() == True)
    assert(bar() == False)

main()
