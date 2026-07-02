#!/usr/bin/env python3

"""

If you place the positive integers together and read each set of two adjacent digits at the same time, you get: (A136414)

12, 23, 34, 45, 56, 67, 78, 89, 91, 10, 1, 11, ...
However, if you squash that sequence again:

12, 22, 23, 33, 34, 44, 45, 55, 56, 66, 67, 77, 78, 88, 89, 99, 91, 11, 10, 1, 11, 11
and so on.

Your task is to output the sequence of the positive integers squashed m times.

Squashing process
[1, 2, 3, 4, 5]
       ↓
    "12345"
       ↓
[12, 23, 34, 45]
Python squashing script

Rules
You have to receive m (a positive integer) as the input or you can output the sequences for all m
Numbers in the sequence can appear more than once
Leading zeros must be removed (eg. 04 is 4)
Default sequence rules
Default Loopholes apply
Test cases
[In]: 1
[Out]: [12, 23, 34, 45, 56, 67, 78, 89, 91, 10, 1, 11, 11, 12, 21, 13, 31, 14, 41, 15, ...]

[In]: 2
[Out]: [12, 22, 23, 33, 34, 44, 45, 55, 56, 66, 67, 77, 78, 88, 89, 99, 91, 11, 10, 1, 11, 11, 11, 11, 11, 12, 22, 21, 11, 13, 33, 31, 11, 14, 44, 41, 11, 15, ...]

[In]: 3
[Out]: [12, 22, 22, 22, 23, 33, 33, 33, 34, 44, 44, 44, 45, 55, 55, 55, 56, 66, 66, 66, 67, 77, 77, 77, 78, 88, 88, 88, 89, 99, 99, 99, 91, 11, 11, 11, 10, 1, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 22, 22, 22, 21, 11, 11, 11, 13, 33, 33, 33, 31, 11, 11, 11, 14, 44, 44, 44, 41, 11, 11, 11, 15, ...]

"""

from itertools import islice

# ported from @loopy walt solution
def gen(n, c=0):
    while n < 1:
        c += 1
        yield c

    for s in gen(n - 1):
        for b in str(s):
            if c:
                yield int(c + b)
            c = b

def main():
    tab1 = [12, 23, 34, 45, 56, 67, 78, 89, 91, 10, 1, 11, 11, 12, 21, 13, 31, 14, 41, 15]
    tab2 = [12, 22, 23, 33, 34, 44, 45, 55, 56, 66, 67, 77, 78, 88, 89, 99, 91, 11, 10, 1, 11, 11, 11, 11, 11, 12, 22, 21, 11, 13, 33, 31, 11, 14, 44, 41, 11, 15]
    tab3 = [12, 22, 22, 22, 23, 33, 33, 33, 34, 44, 44, 44, 45, 55, 55, 55, 56, 66, 66, 66, 67, 77, 77, 77, 78, 88, 88, 88, 89, 99, 99, 99, 91, 11, 11, 11, 10, 1, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 22, 22, 22, 21, 11, 11, 11, 13, 33, 33, 33, 31, 11, 11, 11, 14, 44, 44, 44, 41, 11, 11, 11, 15]

    assert(list(islice(gen(1), len(tab1))) == tab1)
    assert(list(islice(gen(2), len(tab2))) == tab2)
    assert(list(islice(gen(3), len(tab3))) == tab3)

main()
