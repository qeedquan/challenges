#!/usr/bin/env python3

"""

Write a function unpack() that unpacks a list of elements that can contain objects(int, str, list, tuple, dict, set) within each other without any predefined depth, meaning that there can be many levels of elements contained in one another.

Example:

unpack([None, [1, ({2, 3}, {'foo': 'bar'})]]) == [None, 1, 2, 3, 'foo', 'bar']

Note: you don't have to bother about the order of the elements, especially when unpacking a dict or a set. Just unpack all the elements.

"""

def unpack(l):
    r, s = [], [l]
    while len(s) > 0:
        x = s.pop()
        if isinstance(x, (list, tuple, set)):
            s.extend(x)
        elif isinstance(x, dict):
            s.extend(x.items())
        else:
            r.append(x)
    return r[::-1]

assert(unpack([None, [1, ({2, 3}, {'foo': 'bar'})]]) == [None, 1, 2, 3, 'foo', 'bar'])

