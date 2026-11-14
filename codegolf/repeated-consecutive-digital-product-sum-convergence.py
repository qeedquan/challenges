#!/usr/bin/env python3

"""

Given a positive integer n (Example: n=1234444999)

Separate into consecutive digit runs:
[1, 2, 3, 4444, 999]
Take the digital product of each run.
[1, 2, 3, 4*4*4*4, 9*9*9] = [1, 2, 3, 256, 729]
Sum it...
991
Repeat until this converges to a single number:
1234444999
991
82
10
1
Return last number.
Test Cases
BASE CASES:
0 = 0
...
9 = 9

OTHER CASES:
1234444999                     = 1
222222222222222                = 8
111222333444555666777888999000 = 9
11122233344455566677788899     = 8
1112223334445                  = 6
14536                          = 1
99                             = 9

Requested Example:
334455553666333
9+16+625+3+216+27
896
8+9+6
23
2+3
**5**

Winning?
It's code-golf, lowest byte-count is the winner.

"""

from itertools import *

def rcdps(n):
    if n < 10:
        return n
    return rcdps(sum(int(k)**len([*g]) for k, g in groupby(str(n))))

def main():
    for i in range(10):
        assert(rcdps(i) == i)
    assert(rcdps(1234444999) == 1)
    assert(rcdps(222222222222222) == 8)
    assert(rcdps(111222333444555666777888999000) == 9)
    assert(rcdps(11122233344455566677788899) == 8)
    assert(rcdps(1112223334445) == 6)
    assert(rcdps(14536) == 1)
    assert(rcdps(99) == 9)
    assert(rcdps(334455553666333) == 5)

main()

