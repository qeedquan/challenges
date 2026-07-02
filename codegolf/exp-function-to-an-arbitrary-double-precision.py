#!/usr/bin/env python3

"""

Write a function to find the solution of e^x given x, and a precision in the form 0.000001.

sample input and output: e(4,0.00001) will return 54.5981494762146, and the precision is +/- .00001. The output would be acceptable in the range 54.59814 <= output <= 54.59816, you are not required to truncate the answer to the number of significant figures in the input precision.

Your example will be expected to take a precision of at least size double (64 bits) and an x of at least size int (32 bits). Overflows will not be counted against you; I do not expect passing INT_MAX as x to work.

Use whatever algorithm suits you, but do not use math library functions such as builtin pow, factorial, exp, or builtin predefined constants for e, pi, etc.

The objective primary winning criterion is size of submission in bytes, ignoring comments and unnecessary whitespace.

Ties will be broken via runtime speed.

This will last at least one week (ending Thursday, May 16) with each new entry extending the deadline to three days from the entry date.

"""

def E(x, p):
    t = n = s = 1.0
    while t:
        t *= x/n
        n += 1
        s += t
    return s

print(E(4, 0.00001))

