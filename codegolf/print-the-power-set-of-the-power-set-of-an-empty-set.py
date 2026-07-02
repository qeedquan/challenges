#!/usr/bin/env python3

"""

Given a non-negative integer n, print the result of P(P(...P({}))), where the number of P's is n (P is the power set function).

0 => {}
1 => P({})
2 => P(P({}))
3 => P(P(P({})))
n => P(f(n-1))

input   result
0       {}
1       {{}}
2       {{},{{}}}
3       {{},{{}},{{{}}},{{},{{}}}}
...
The result should only contain parentheses/brackets/braces and commas, spaces and newlines are allowed.

"""

from itertools import *

def f(n):
    if not n:
        return ()

    r = []
    for i in range(n + 1):
        r = chain(r, combinations(f(n - 1), i))
    return list(r)

def main():
    for i in range(4):
        print(i, f(i))

main()
