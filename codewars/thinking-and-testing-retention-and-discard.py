#!/usr/bin/env python3

"""

No Story

No Description

Only by Thinking and Testing

Look at the results of the testcases, and guess the code!

"""

def testit(n):
    r = []
    if n < 1:
        return r
    for i in range(1, n + 1, 2):
        if n%i == 0:
            r.append(i)
    return r

def main():
    assert(testit(-1) == [])
    assert(testit(0) == [])
    assert(testit(1) == [1])
    assert(testit(2) == [1])
    assert(testit(3) == [1, 3])
    assert(testit(4) == [1])
    assert(testit(5) == [1, 5])
    assert(testit(6) == [1, 3])
    assert(testit(7) == [1, 7])
    assert(testit(8) == [1])
    assert(testit(9) == [1, 3, 9])
    assert(testit(10) == [1, 5])

main()
