#!/usr/bin/env python3

"""

You have to write a function f which returns Infinity in less than 9 characters.

"""

from math import inf, isnan

def main():
    assert(inf == inf)
    assert(2**64 < inf)
    assert(-inf < inf)
    assert(inf + inf == inf)
    assert(inf * inf == inf)
    assert(isnan(inf - inf))
    assert(isnan(inf / inf))
    assert(isnan(inf * 0))

main()
