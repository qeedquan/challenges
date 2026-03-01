#!/usr/bin/env python3

"""

Given a variable n,

If n is an integer, Return a string with dash'-'marks before and after each odd integer, but do not begin or end the string with a dash mark. If n is negative, then the negative sign should be removed.

If n is not an integer, return an empty value.

Ex:

dashatize(274) -> '2-7-4'
dashatize(6815) -> '68-1-5'

"""

def dashatize(n):
    if not isinstance(n, int):
        return ""

    odd = ('1', '3', '5', '7', '9')
    r = ""
    cp = None
    for c in str(abs(n)):
        if c in odd or cp in odd:
            r += '-'
        r += c
        cp = c
    r = r.lstrip('-')
    return r

def main():
    assert(dashatize(274) == "2-7-4")
    assert(dashatize(6815) == "68-1-5")
    assert(dashatize(5311) == "5-3-1-1")
    assert(dashatize(86320) == "86-3-20")
    assert(dashatize(974302) == "9-7-4-3-02")

    assert(dashatize(0) == "0")
    assert(dashatize(-1) == "1")
    assert(dashatize(-28369) == "28-3-6-9")

main()
