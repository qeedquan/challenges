#!/usr/bin/env python3

"""

Write a program to left or right justify a text file

"""

import sys

def justify(name, kind, width):
    file = open(name)
    for line in file.readlines():
        line = line.rstrip()
        line = line.lstrip()
        if kind == 'left':
            print(('{:<' + width + '}').format(line))
        elif kind == 'right':
            print(('{:>' + width + '}').format(line))
        else:
            print(line)

def main():
    if len(sys.argv) != 4:
        print("usage: left|right width file")
        exit(2)

    justify(sys.argv[3], sys.argv[1], sys.argv[2])

main()
