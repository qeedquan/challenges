#!/usr/bin/env python3

"""

The so-called Will Rogers phenomenon describes a way to tweak statistics by raising the average in two (multi)sets when one element is moved between the two sets. As a simple example, consider the two sets

A = {1, 2, 3}
B = {4, 5, 6}
Their arithmetic means are 2 and 5, respectively. If we move the 4 to A:

A = {1, 2, 3, 4}
B = {5, 6}
Now the averages are 2.5 and 5.5, respectively, so both averages have been raised through a simple regrouping.

As another example, consider

A = {3, 4, 5, 6} --> A = {3, 5, 6}
B = {2, 3, 4, 5} --> B = {2, 3, 4, 4, 5}
On the other hand, it's not possible to raise both averages for the sets

A = {1, 5, 9}
B = {4, 5, 7, 8}

The Challenge
Given two lists of non-negative integers, determine whether it is possible to raise both averages by moving a single integer from one list to the other.

The average of an empty list is not defined, so if one of the lists contains only one element, this element cannot be moved.

You may write a program or function, taking input via STDIN (or closest alternative), command-line argument or function argument and outputting the result via STDOUT (or closest alternative), function return value or function (out) parameter.

Input may be taken in any convenient string or list format.

You must not assume that the elements in each list are unique, nor that they are sorted. You may assume that both lists contain at least one element.

Output should be truthy if both averages can be raised by moving a single integer and falsy otherwise.

This is code golf, so the shortest answer (in bytes) wins.

Test Cases

Truthy:

[1], [2, 3]
[1, 2, 3], [4, 5, 6]
[3, 4, 5, 6], [2, 3, 4, 5]
[6, 5, 9, 5, 6, 0], [6, 2, 0, 9, 5, 2]
[0, 4], [9, 1, 0, 2, 8, 0, 5, 5, 4, 9]

Falsy:

[1], [2]
[2, 4], [5]
[1, 5], [2, 3, 4, 5]
[2, 1, 2, 3, 1, 3], [5, 1, 6]
[4, 4, 5, 2, 4, 0], [9, 2, 10, 1, 9, 0]

"""

import numpy as np

def check(a, b, μa, μb):
    return any(μb < x and x < μa for x in a)

"""

https://en.wikipedia.org/wiki/Will_Rogers_phenomenon

@xnor
Checks if the first list has an element that's bigger than it's average but smaller than the other one's. Then, does the same for the two inputs swapped.

"""

def willrogers(a, b):
    μa = np.mean(a)
    μb = np.mean(b)
    return check(a, b, μa, μb) or check(b, a, μb, μa)

def main():
    assert(willrogers([1], [2, 3]) == True)
    assert(willrogers([1, 2, 3], [4, 5, 6]) == True)
    assert(willrogers([3, 4, 5, 6], [2, 3, 4, 5]) == True)
    assert(willrogers([6, 5, 9, 5, 6, 0], [6, 2, 0, 9, 5, 2]) == True)
    assert(willrogers([0, 4], [9, 1, 0, 2, 8, 0, 5, 5, 4, 9]) == True)
    assert(willrogers([1, 2, 3, 4], [5, 6, 7, 8, 9]) == True)
    assert(willrogers([1, 2], [99, 10000, 20000]) == True)
    assert(willrogers([1, 3, 5, 7, 9, 11, 13], [6, 8, 10, 12, 14, 16, 18]) == True)

    assert(willrogers([1, 5, 9], [4, 5, 7, 8]) == False)
    assert(willrogers([1], [2]) == False)
    assert(willrogers([2, 4], [5]) == False)
    assert(willrogers([1, 5], [2, 3, 4, 5]) == False)
    assert(willrogers([2, 1, 2, 3, 1, 3], [5, 1, 6]) == False)
    assert(willrogers([4, 4, 5, 2, 4, 0], [9, 2, 10, 1, 9, 0]) == False)

main()

