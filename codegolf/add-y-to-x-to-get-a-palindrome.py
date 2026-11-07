#!/usr/bin/env python3

"""

Given X>0, return the smallest Y>=0 such that X+Y is a palindrome. Code golf.

Tests:

5 => 0
14 => 8
200 => 2
819 => 9
1100 => 11
1122 => 99

"""

# https://oeis.org/A052036
def f(x):
    y = 0
    while True:
        s = str(x + y)
        if s == s[::-1]:
            break
        y += 1
    return y

def main():
    tab = [
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 10,
        9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 10, 9,
        8, 7, 6, 5, 4, 3, 2, 1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 10, 9, 8,
        7, 6, 5, 4, 3, 2, 1, 0
    ]

    assert(f(5) == 0)
    assert(f(14) == 8)
    assert(f(200) == 2)
    assert(f(819) == 9)
    assert(f(1100) == 11)
    assert(f(1122) == 99)
    for i in range(len(tab)):
        assert(f(i) == tab[i])

main()
