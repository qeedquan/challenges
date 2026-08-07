#!/usr/bin/env python3

"""

Task
Given a list of digits, return the smallest number that could be formed from these digits, using the digits only once (ignore duplicates).

Notes:
Only positive integers will be passed to the function (> 0 ), no negatives or zeros.
Input >> Output Examples
minValue ({1, 3, 1})  ==> return (13)
Explanation:
(13) is the minimum number could be formed from {1, 3, 1} , Without duplications

minValue({5, 7, 5, 9, 7})  ==> return (579)
Explanation:
(579) is the minimum number could be formed from {5, 7, 5, 9, 7} , Without duplications

minValue({1, 9, 3, 1, 7, 4, 6, 6, 7}) return  ==> (134679)
Explanation:
(134679) is the minimum number could be formed from {1, 9, 3, 1, 7, 4, 6, 6, 7} , Without duplications

"""

def minvalue(a):
    d = [0] * 10
    for i in a:
        d[i] = 1

    r = 0
    for i in range(len(d)):
        if d[i] > 0:
            r = (r * 10) + i
    return r

def main():
    assert(minvalue([1, 3, 1]) == 13)
    assert(minvalue([5, 7, 5, 9, 7]) == 579)
    assert(minvalue([1, 9, 3, 1, 7, 4, 6, 6, 7]) == 134679)

main()
