#!/usr/bin/env python3

"""

Given two intervals A and B, decide if A can be translated and placed into B. You can assume both given interval has some measure(or say length).

aka. Exist d, for all x in A, x+d is in B.

Both extreme points are positive integers but can be either open or close(given in input, flexible form). Moved distance needn't be integer, though.

Test cases:

[1,2], [1,3] => true
[1,2], (1,3) => true  (d can't be integer but it's fine)
[1,2], [8,9] => true
[8,9), [1,2) => true
(1,9), (1,9) => true
[1,4], [3,5] => false
(8,9], [1,2) => false (rotating is not allowed)
(7,9), [1,2] => false
Now some simple challenges onto main, CMC isn't quite active

"""

from sympy.sets.sets import Interval

# ported from @tsh solution
def inside(a, b):
    c = a.xreplace({a.inf: b.inf, a.sup: b.sup})
    return a.measure < b.measure + c.issubset(b)

def main():
    assert(inside(Interval(1, 2), Interval(1, 3)) == True)
    assert(inside(Interval(1, 2), Interval(1, 3, left_open=True, right_open=True)) == True)
    assert(inside(Interval(1, 2), Interval(8, 9)) == True)
    assert(inside(Interval(8, 9, right_open=True), Interval(1, 2, right_open=True)) == True)
    assert(inside(Interval(1, 9, left_open=True, right_open=True), Interval(1, 9, left_open=True, right_open=True)) == True)
    assert(inside(Interval(1, 4), Interval(3, 5)) == False)
    assert(inside(Interval(8, 9, left_open=True), Interval(1, 2, right_open=True)) == False)
    assert(inside(Interval(7, 9, left_open=True, right_open=True), Interval(1, 2)) == False)

main()
