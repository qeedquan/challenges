#!/usr/bin/env python3

"""

This time we want to write calculations using functions and get the results. Let's have a look at some examples:

seven(times(five())); // must return 35
four(plus(nine())); // must return 13
eight(minus(three())); // must return 5
six(dividedBy(two())); // must return 3

Requirements:

There must be a function for each number from 0 ("zero") to 9 ("nine")
There must be a function for each of the following mathematical operations: plus, minus, times, dividedBy (divided_by in Ruby and Python)
Each calculation consist of exactly one operation and two numbers
The most outer function represents the left operand, the most inner function represents the right operand
Division should be integer division. For example, this should return 2, not 2.666666...:
eight(dividedBy(three()));

"""

def number(value, func=None):
    if func:
        return func(value)
    return value

def zero(func=None):
    return number(0, func)

def one(func=None):
    return number(1, func)

def two(func=None):
    return number(2, func)

def three(func=None):
    return number(3, func)

def four(func=None):
    return number(4, func)

def five(func=None):
    return number(5, func)

def six(func=None):
    return number(6, func)

def seven(func=None):
    return number(7, func)

def eight(func=None):
    return number(8, func)

def nine(func=None):
    return number(9, func)

def plus(value):
    return lambda x: x + value

def minus(value):
    return lambda x: x - value

def times(value):
    return lambda x: x * value

def dividedBy(value):
    return lambda x: x // value

def main():
    assert(seven(times(five())) == 35)
    assert(four(plus(nine())) == 13)
    assert(eight(minus(three())) == 5)
    assert(six(dividedBy(two())) == 3)
    assert(eight(dividedBy(three())) == 2)

main()
