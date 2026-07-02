#!/usr/bin/env python3

"""

Task
Given a non-empty array of 0 and 1, halve the lengths of the runs of 0.

Input
An array of 0 and 1. Acceptable format:

Real array in your language
Linefeed-separated string of 0 and 1
Contiguous string of 0 and 1
Any other reasonable format
For example, the following three inputs are all acceptable:

[1, 0, 0, 1]
"1\n0\n0\n1" (where \n is a linefeed U+000A)
"1001"
You may assume that the runs of 0 will have even length.

Output
An array of 0 and 1, in the acceptable formats above.

Testcases
input ↦ output
[1,0,0,1,0,0,1] ↦ [1,0,1,0,1]
[1,1,0,0,1,1,0,0,1] ↦ [1,1,0,1,1,0,1]
[1,1,0,0,1,1,1,0,0,1,1] ↦ [1,1,0,1,1,1,0,1,1]
[1,1,1] ↦ [1,1,1]
[0,0,1] ↦ [0,1]
[0,0] ↦ [0]
[1,1,1,0,0,0,0,1,1,1,1,0,0,1,0,0,1,1,0,0,1,1,1,1,0,0,1,0,0] ↦ [1,1,1,0,0,1,1,1,1,0,1,0,1,1,0,1,1,1,1,0,1,0]

Scoring
This is code-golf. Shortest answer in bytes wins.

Standard loopholes apply.

"""

def halve_zeroes(a):
    r = []
    n = len(a)
    i = 0
    while i < n:
        j = i
        while j < n and a[i] == a[j]:
            j += 1
        
        k = j - i
        if a[i] == 0:
            k //= 2
        for _ in range(k):
            r.append(a[i])

        i = j
    return r

def main():
    assert(halve_zeroes([1, 0, 0, 1, 0, 0, 1]) == [1, 0, 1, 0, 1])
    assert(halve_zeroes([1, 1, 0, 0, 1, 1, 0, 0, 1]) == [1, 1, 0, 1, 1, 0, 1])
    assert(halve_zeroes([1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1]) == [1, 1, 0, 1, 1, 1, 0, 1, 1])
    assert(halve_zeroes([1, 1, 1]) == [1, 1, 1])
    assert(halve_zeroes([0, 0, 1]) == [0, 1])
    assert(halve_zeroes([0, 0]) == [0])
    assert(halve_zeroes([1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0]) == [1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0])

main()
