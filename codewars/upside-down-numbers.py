#!/usr/bin/env python3

"""

Consider the numbers 6969 and 9116. When you rotate them 180 degrees (upside down), these numbers remain the same. To clarify, if we write them down on a paper and turn the paper upside down, the numbers will be the same. Try it and see! Some numbers such as 2 or 5 don't yield numbers when rotated.

Given a range, return the count of upside down numbers within that range.  For example, solve(0,10) = 3, because there are only 3 upside down numbers >= 0 and < 10. They are 0, 1, 8.

More examples in the test cases.

"""

from itertools import count, islice, product

def ud(s):
    s = s[::-1]
    s = s.translate({
        ord('6'): ord('9'),
        ord('9'): ord('6'),
    })
    return s

# https://oeis.org/A000787 (related)
def solve(n, m):
    if n >= m or m < 0:
        return 0

    c = 0
    if n <= 0:
        c += 1
    if n <= 1:
        c += 1
    if n <= 8:
        c += 1

    for d in count(2):
        for s in "1689":
            for r in product("01689", repeat=(d//2 - 1)):
                L = s + "".join(r)
                R = ud(L)
                for M in [[""], ["0", "1", "8"]][d % 2]:
                    x = int(L + M + R)
                    if x >= m:
                        return c
                    if x >= n:
                        c += 1

def main():
    assert(solve(0, 10) == 3)
    assert(solve(10, 100) == 4)
    assert(solve(100, 1000) == 12)
    assert(solve(1000, 10000) == 20)
    assert(solve(10000, 15000) == 6)
    assert(solve(15000, 20000) == 9)
    assert(solve(60000, 70000) == 15)
    assert(solve(60000, 130000) == 55)

main()
