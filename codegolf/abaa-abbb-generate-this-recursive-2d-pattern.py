#!/usr/bin/env python3

"""

I was messing around with infinite resistor networks (long story) when I came across the following interesting recursive pattern:

|-||
|---
Each instance of this pattern is twice as wide as it is tall. To go from one level of the pattern to the next, you break up this rectangle into two sub-blocks (each of which is a NxN square):

AB =
|-||
|---

so A =
|-
|-

and B =
||
--
These halves are then duplicated and rearranged according to the following pattern:

ABAA
ABBB

giving

|-|||-|-
|---|-|-
|-||||||
|-------
Challenge

Write a program/function which, given a number N, outputs the Nth iteration of this recursive design. This is golf.

I/O format is relatively lenient: you may return a single string, a list of strings, a 2D array of characters, etc. Arbitrary trailing whitespace is allowed. You may also use either 0 or 1 indexing.

Examples

The first several iterations of the pattern are as follows:

N = 0
|-

N = 1
|-||
|---

N = 2
|-|||-|-
|---|-|-
|-||||||
|-------

N = 3
|-|||-|-|-|||-||
|---|-|-|---|---
|-|||||||-|||-||
|-------|---|---
|-|||-|-|-|-|-|-
|---|-|-|-|-|-|-
|-||||||||||||||
|---------------

N = 4
|-|||-|-|-|||-|||-|||-|-|-|||-|-
|---|-|-|---|---|---|-|-|---|-|-
|-|||||||-|||-|||-|||||||-||||||
|-------|---|---|-------|-------
|-|||-|-|-|-|-|-|-|||-|-|-|||-|-
|---|-|-|-|-|-|-|---|-|-|---|-|-
|-|||||||||||||||-|||||||-||||||
|---------------|-------|-------
|-|||-|-|-|||-|||-|||-|||-|||-||
|---|-|-|---|---|---|---|---|---
|-|||||||-|||-|||-|||-|||-|||-||
|-------|---|---|---|---|---|---
|-|||-|-|-|-|-|-|-|-|-|-|-|-|-|-
|---|-|-|-|-|-|-|-|-|-|-|-|-|-|-
|-||||||||||||||||||||||||||||||
|-------------------------------
I wonder if there is some short algebraic way to compute this structure.

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def recurse(n):
    if n < 0:
        return [""]
    if n < 1:
        return ["|-"]

    h = 2**n // 2
    r = []
    for i in (0, h):
        for p in recurse(n - 1):
            r.append(p + 2*p[i:i+h])
    return r

def gen(n):
    return '\n'.join(recurse(n))

def main():
    for i in range(5):
        print("n=%d" % (i))
        print(gen(i))
        print()

main()

