#!/usr/bin/env python3

def times(l, p):
    mi = 0
    ma = 0
    for v in p:
        mi = max(mi, min(v, l-v))
        ma = max(ma, v, l-v)
    return (mi, ma)

def main():
    assert(times(10, [2, 6, 7]) == (4, 8))
    assert(times(214, [11, 12, 7, 13, 176, 23, 191]) == (38, 207))

main()
