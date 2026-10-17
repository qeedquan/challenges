#!/usr/bin/env python3

"""

You are given two jugs with capacities jug1Capacity and jug2Capacity liters. There is an infinite amount of water supply available. Determine whether it is possible to measure exactly targetCapacity liters using these two jugs.

If targetCapacity liters of water are measurable, you must have targetCapacity liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full, or the first jug itself is empty.


Example 1:

Input: jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
Output: true
Explanation: The famous Die Hard example
Example 2:

Input: jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5
Output: false
Example 3:

Input: jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3
Output: true


Constraints:

1 <= jug1Capacity, jug2Capacity, targetCapacity <= 10^6

"""

from math import *

def measurable(jug1, jug2, target):
    if target <= 0:
        return True

    if jug1 + jug2 < target:
        return False

    return (target % gcd(jug1, jug2)) == 0

def main():
    assert(measurable(3, 5, 4) == True)
    assert(measurable(2, 6, 5) == False)
    assert(measurable(1, 2, 3) == True)

main()
