#!/usr/bin/env python3

"""

Tetration, represented as b|a, is repeated exponentiation. For example, 3|2 is 2^2^2, which is 16.

Given two numbers a and b, print b|a.

Test cases
1 2 -> 1
2 2 -> 4
5 2 -> 3125
3 3 -> 7625597484987
etc.
Scientific notation is acceptable.

Remember, this is code-golf, so the code with the smallest number of bytes wins.

"""

def tetration(a, b):
    if b < 0:
        return 0
    if b == 1:
        return a

    p = a
    r = 1
    for i in range(1, b):
        r = a**p
        p = r
    return r

def main():
    assert(tetration(1, 2) == 1)
    assert(tetration(2, 2) == 4)
    assert(tetration(5, 2) == 3125)
    assert(tetration(3, 3) == 7625597484987)
    assert(tetration(4, 3) == 13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096)
    assert(tetration(2, 4) == 65536)
    assert(tetration(45, 0) == 1)
    assert(tetration(34, 1) == 34)

main()
