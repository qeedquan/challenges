#!/usr/bin/env python3

"""

Definition
Narcissistic 1 integers of an array think they are better than their neighbours, because they are strictly higher than their arithmetic mean.

Neighbours are defined as follows:

If the integer is at index 0 (the first), then its neighbours are the last and the second elements of the list.

If the integer is not the first nor the last, then its neighbours are the two immediately adjacent elements.

If the integer is at index -1 (the last), then its neighbours are the second-last and the first elements of the list.

Task
Given an array of integers, your task is to discard the narcissistic ones.

The integers can be positive, negative or zero.

You may assume that the array contains at least three elements.

All standard rules apply. This is code-golf, so the shortest code in bytes wins.

Examples
Consider the array [6, 9, 4, 10, 16, 18, 13]. Then we can built the following table:

Element | Neighbours | Neighbours' Mean | Is Narcissistic?
--------+------------+------------------+-----------------
6       | 13, 9      | 11               | False.
9       | 6, 4       | 5                | True.
4       | 9, 10      | 9.5              | False.
10      | 4, 16      | 10               | False.
16      | 10, 18     | 14               | True.
18      | 16, 13     | 14.5             | True.
13      | 18, 6      | 12               | True.
By filtering the Narcissistic ones out, we are left with [6, 4, 10]. And that's it!

Test Cases
Input -> Output

[5, -8, -9]                         -> [-8, -9]
[8, 8, 8, 8]                        -> [8, 8, 8, 8]
[11, 6, 9, 10]                      -> [6, 10]
[1, 2, 0, 1, 2]                     -> [1, 0, 1]
[6, 9, 4, 10, 16, 18, 13]           -> [6, 4, 10]
[6, -5, 3, -4, 38, 29, 82, -44, 12] -> [-5, -4, 29, -44]
1 - Narcissist does not mean mathematically Narcissistic.

"""

def filter(values):
    result = []
    for index, value in enumerate(values):
        if 2*value <= values[index - 1] + values[(index + 1) % len(values)]:
            result.append(value)
    return result

def main():
    assert(filter([5, -8, -9]) == [-8, -9])
    assert(filter([8, 8, 8, 8]) == [8, 8, 8, 8])
    assert(filter([11, 6, 9, 10]) == [6, 10])
    assert(filter([1, 2, 0, 1, 2]) == [1, 0, 1])
    assert(filter([6, 9, 4, 10, 16, 18, 13]) == [6, 4, 10])
    assert(filter([6, -5, 3, -4, 38, 29, 82, -44, 12]) == [-5, -4, 29, -44])

main()
