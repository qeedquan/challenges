#!/usr/bin/env python3

"""

Create the hi_all() function without using strings, numbers and booleans.
The return value is "Hello World". No, it is not impossible, use the builtin functions. Good luck :)

"""

def hi_all():
    n = len(id.__name__)
    s0 = hex.__name__[:n]
    s1 = next(iter(list.__name__))
    s2 = locals.__name__[:n]
    s3 = next(filter(str.isspace, str.join.__doc__))
    s4 = next(reversed(pow.__name__))
    s5 = ord.__name__[:n]
    s6 = next(iter(list.__name__))
    s7 = next(reversed(ord.__name__))
    s = s0 + s1 + s2 + s3 + s4 + s5 + s6 + s7
    return s.title()

print(hi_all())
