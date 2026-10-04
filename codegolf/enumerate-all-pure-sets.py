#!/usr/bin/env python3

"""

In set theory, a set is an unordered group of unique elements. A pure set is either the empty set {} or a set containing only pure sets, like {{},{{}}}.

Your challenge is to write a program that enumerates all pure sets, in some order of your choice. Standard sequence rules apply - you may:

Output all pure sets
Take an integer n and output the nth set by your definition
Take an integer n and output the first n sets. (n may be 0 or 1-indexed)

Pure sets may be represented in any reasonable format.

This is code-golf, shortest wins.

"""

def pureset(n):
    r = []
    for i in range(n):
        if (n>>i)&1 != 0:
            r.append(pureset(i))
    return r

def main():
    for i in range(256):
        print(i, pureset(i))

main()
