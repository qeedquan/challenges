#!/usr/bin/env python3

"""

Given a wordlist of your choosing, make a program to unscramble scrambled words from that list. For sanity and brevity, disregard any words which have ambiguous unscramlings, such as "dgo" unscrambling to both "dog" and "god."

Input:

A file which contains scrambled words and a wordlist to match it against

Output:

The unscrambled words which match the scrambled ones

"""

import sys

def unscramble(scrambled, dictionary):
    f = open(scrambled, 'r')
    g = open(dictionary, 'r')

    for i in f.readlines():
        i = i.strip()
        g.seek(0)
        for j in g.readlines():
            j = j.strip()
            if set(i) == set(j):
                print('%s:%s' % (i, j))
    f.close()
    g.close()

def main():
    if len(sys.argv) != 3:
        print("usage: <scrambled> <dictionary>")
        exit(2)
    
    unscramble(sys.argv[1], sys.argv[2])

main()

