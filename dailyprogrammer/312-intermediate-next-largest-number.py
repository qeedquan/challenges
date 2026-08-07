#!/usr/bin/env python3

"""

Description
Given an integer, find the next largest integer using ONLY the digits from the given integer.

Input Description
An integer, one per line.

Output Description
The next largest integer possible using the digits available.

Example
Given 292761 the next largest integer would be 296127.

Challenge Input
1234
1243
234765
19000

Challenge Output
1243
1324
235467
90001

Credit
This challenge was suggested by user u/caa82437, many thanks. If you have a challenge idea, please share it in r/dailyprogrammer_ideas and there's a good chance we'll use it.

"""

from itertools import permutations

def next_largest(x):
    p = sorted(list({''.join(i) for i in permutations(x, len(x))}))
    return p[p.index(x)+1]

def main():
    assert(next_largest('1234') == '1243')
    assert(next_largest('1243') == '1324')
    assert(next_largest('234765') == '235467')
    assert(next_largest('19000') == '90001')
    assert(next_largest('292761') == '296127')

main()

