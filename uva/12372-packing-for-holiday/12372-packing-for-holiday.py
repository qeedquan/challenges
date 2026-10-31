#!/usr/bin/env python3

def fits(l, w, h):
    return l <= 20 and w <= 20 and h <= 20

def main():
    assert(fits(20, 20, 20) == True)
    assert(fits(1, 2, 21) == False)

main()
