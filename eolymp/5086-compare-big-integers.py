#!/usr/bin/env python3

"""

Two big integers are given. Find which is bigger.

Input
Two lines contain two big integers a and b (1≤a,b≤10^1000).

Output
Print one of signs: "<", "=", ">".

Examples

Input #1
3
5

Answer #1
<

Input #2
5
5

Answer #2
=

Input #3
5
3

Answer #3
>

"""

def cmp(a, b):
    if a > b:
        return '>'
    if a < b:
        return '<'
    return '='

def main():
    assert(cmp(3, 5) == '<')
    assert(cmp(5, 5) == '=')
    assert(cmp(5, 3) == '>')

main()
