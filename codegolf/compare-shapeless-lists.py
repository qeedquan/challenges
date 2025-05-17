#!/usr/bin/env python3

"""

Let's have a ragged list containing no values, only more lists. For example:

[[[],[[]],[],[]],[],[[],[],[]],[]]
And the list will be finite, meaning that eventually every path terminates in an empty list [].

It's simple enough to determine if two of these are structurally equal. Check each element in order for equality and recurse. However what if we don't care about the order of the lists for equality? What if we only care that they have the same elements?

We can define this shapeless equality like so:

Two lists A, and B are shapeless equal if for every element in A there are as many elements in A shapeless equal to it as there are in B, and vice-versa for the elements of B.

Your task will be to take two ragged lists and determine if they are "shapeless equal" to each other. If they are you should output some consistent value, if they are not you should output some distinct consistent value.

This is code-golf so answers will be scored in bytes with fewer bytes being the goal.

Testcases
[] [] -> 1
[[],[[]]] [[[]],[]] -> 1
[[],[[],[[]]]] [[],[[[]],[]]] -> 1
[[],[[],[[]]]] [[[[]],[]],[]] -> 1
[[]] [] -> 0
[[],[]] [[[]]] -> 0
[[],[]] [[]] -> 0
[[[],[],[]],[[]]] [[[],[]],[[],[]]] -> 0
[[],[],[[]]] [[],[[]],[[]]] -> 0

"""

def equal(a):
    return sorted(map(equal, a))

def shapeless(x, y):
    return equal(x) == equal(y)

def main():
    assert(shapeless([], []) == True)
    assert(shapeless([[], [[]]], [[[]], []]) == True)
    assert(shapeless([[], [[], [[]]]], [[], [[[]], []]]) == True)
    assert(shapeless([[], [[], [[]]]], [[[[]], []], []]) == True)
    assert(shapeless([[]], []) == False)
    assert(shapeless([[], []], [[[]]]) == False)
    assert(shapeless([[], []], [[]]) == False)
    assert(shapeless([[[], [], []], [[]]], [[[], []], [[], []]]) == False)
    assert(shapeless([[], [], [[]]], [[], [[]], [[]]]) == False)

main()
