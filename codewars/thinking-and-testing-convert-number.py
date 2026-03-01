#!/usr/bin/env python3

"""

No Story

No Description

Only by Thinking and Testing

Look at result of testcase, guess the code!

"""

def testit(f):
    if f < -459.67:
        return "Invalid input!"
    r = 5/9 * (f - 32)
    return round(r * 100) / 100

def main():
    assert(testit(212) == 100)
    assert(testit(32) == 0)
    assert(testit(77) == 25)
    assert(testit(0) == -17.78)
    assert(testit(-500) == "Invalid input!")

main()
