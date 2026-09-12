#!/usr/bin/env python3

"""

You are given a string S.
S contains alphanumeric characters only.

Your task is to sort the string S in the following manner:

All sorted lowercase letters are ahead of uppercase letters.
All sorted uppercase letters are ahead of digits.
All sorted odd digits are ahead of sorted even digits.

Input Format

A single line of input contains the string S.

Constraints
0 < len(S) < 1000

Output Format
Output the sorted string S.

Sample Input
Sorting1234

Sample Output
ginortS1324

"""

from functools import cmp_to_key

def cmp(x, y):
    l0 = x.islower()
    l1 = y.islower()
    if l0 and not l1:
        return -1
    if not l0 and l1:
        return 1

    u0 = x.isupper()
    u1 = y.isupper()
    if u0 and not u1:
        return -1
    if not u0 and u1:
        return 1

    try:
        n0 = int(x) & 1
        n1 = int(y) & 1
        if n0 != 0 and n1 == 0:
            return -1
        if n0 == 0 and n1 != 0:
            return 1
    except:
        pass

    return ord(x) - ord(y)

def strsort(s):
    l = sorted(s, key=cmp_to_key(cmp))
    return ''.join(l)

def main():
    assert(strsort("Sorting1234") == "ginortS1324")

main()
