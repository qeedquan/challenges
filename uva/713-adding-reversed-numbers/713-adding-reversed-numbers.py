#!/usr/bin/env python3

def rev(n):
    return int(str(n)[::-1])

def revadd(a, b):
    return rev(rev(a) + rev(b))

def main():
    assert(revadd(24, 1) == 34)
    assert(revadd(4358, 754) == 1998)
    assert(revadd(305, 794) == 1)

main()
