#!/usr/bin/env python3

"""

Mash 2 arrays together so that the returning array has alternating elements of the 2 arrays . Both arrays will always be the same length.

eg. [1,2,3] + ['a','b','c'] = [1, 'a', 2, 'b', 3, 'c']

"""

def mash(a, b):
    r = []
    for i in range(len(a)):
        r.append(a[i])
        r.append(b[i])
    return r

def main():
    print(mash([1, 2, 3], ['a', 'b', 'c']))

main()

