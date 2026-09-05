#!/usr/bin/env python3

"""

Implement something called str_repeat that repeats a string n-times. That something must not be a function.

Thanks wichu for the idea.

Enjoy! :)

"""

class str_repeater:
    def __call__(self, s, n):
        return s * n

str_repeat = str_repeater()

assert(str_repeat('a', 4) == 'aaaa')
assert(str_repeat('hello ', 3) == 'hello hello hello ')
assert(str_repeat('abc', 2) == 'abcabc')

