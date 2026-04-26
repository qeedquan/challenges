#!/usr/bin/env python3

def solve(p, e, i, d):
    days = p*pow(28*33, -1, 23)*28*33
    days += e*pow(23*33, -1, 28)*23*33
    days += i*pow(23*28, -1, 33)*23*28
    days -= d
    days += 21251
    days %= 21252
    return days + 1

def main():
    assert(solve(0, 0, 0, 0) == 21252)
    assert(solve(0, 0, 0, 100) == 21152)
    assert(solve(5, 20, 34, 325) == 19575)
    assert(solve(4, 5, 6, 7) == 16994)
    assert(solve(283, 102, 23, 320) == 8910)
    assert(solve(203, 301, 203, 40) == 10789)

main()

