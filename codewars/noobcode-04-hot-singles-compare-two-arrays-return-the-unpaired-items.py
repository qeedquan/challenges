#!/usr/bin/env python3

"""

Write a function that takes two array arguments, and returns a new array populated with the elements that appear in either array, but not in both.
Elements should only appear once in the returned array.

The order of the elements in the result should follow what appears in the first array, then the second one.

Examples
[1, 2, 3, 3], [3, 2, 1, 4, 5]) --> [4, 5]

["tartar", "blanket", "cinnamon"], ["cinnamon", "blanket", "domino"] --> ["tartar", "domino"]

[77, "ciao"], [78, 42, "ciao"] --> [77, 78, 42]

[1, 2, 3, 3], [3, 2, 1, 4, 5, 4] --> [4,5]

[1, 2, 3] , [3, 3, 2, 1] --> []

"""

def hot_singles(a, b):
    return set(a) ^ set(b)

def main():
    assert(hot_singles([1, 2, 3, 3], [3, 2, 1, 4, 5]) == set([4, 5]))
    assert(hot_singles(["tartar", "blanket", "cinnamon"], ["cinnamon", "blanket", "domino"]) == set(["tartar", "domino"]))
    assert(hot_singles([77, "ciao"], [78, 42, "ciao"]) == set([77, 78, 42]))
    assert(hot_singles([1, 2, 3, 3], [3, 2, 1, 4, 5, 4]) == set([4, 5]))
    assert(hot_singles([1, 2, 3], [3, 3, 2, 1]) == set([]))

main()

