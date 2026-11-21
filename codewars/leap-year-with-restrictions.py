#!/usr/bin/env python3

"""

Task
You're given a year n (1583 <= n < 10000). You need to create a function which return True if n is a leap year and False otherwise.

Restrictions
Your code mustn't contain:

def
if
eval or exec
return
import

Note
Feel free to rate the kata when you finish it :)

P.S.: Sofisticated cheats, which do not circumvent the testing framework itself, are welcome.

"""

isleap = lambda y: not (y%4 or (y%100 == 0 and y%400 != 0))

assert(isleap(2020) == True)
assert(isleap(2015) == False)
assert(isleap(2100) == False)
