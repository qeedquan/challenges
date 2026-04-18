#!/usr/bin/env python3

from math import sqrt

# https://oeis.org/A006253
def solve(n):
    r = (2*(-1)**n + (2-sqrt(3))**(1+n) + (2+sqrt(3))**(1+n)) / 6
    r = round(r)
    return int(r) % 1000000007

def main():
    tab = [
        1, 2, 9, 32, 121, 450, 1681, 6272, 23409, 87362, 326041, 1216800, 4541161,
        16947842, 63250209, 236052992, 880961761, 3287794050, 12270214441,
        45793063712, 170902040409, 637815097922, 2380358351281, 8883618307200,
        33154114877521, 123732841202882, 461777249934009
    ]

    assert(solve(1) == 2)
    assert(solve(2) == 9)
    assert(solve(3) == 32)

    for i in range(len(tab)):
        assert(solve(i) == tab[i]% 1000000007)

main()

