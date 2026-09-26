#!/usr/bin/env python3

"""

Given an array of size n, find its majority element. The majority element is the element that appears more than ⌊n/2⌋ times.

If there is no such element, output −1.

Input
The first line contains the integer n (1≤n≤100).

The second line contains n positive integers.

Output
If a majority element exists in the array, output it. Otherwise, output −1.

Examples

Input #1
7
3 5 3 4 2 3 3

Answer #1
3

Input #2
4
2 3 2 3

Answer #2
-1

"""

# https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
def majority(numbers):
    candidate = None
    count = 0
    for number in numbers:
        if count == 0:
            candidate = number
            count = 1
        elif number == candidate:
            count += 1
        else:
            count -= 1
            
    actual_count = sum(1 for x in numbers if x == candidate)
    if actual_count > len(numbers)//2:
        return candidate
    return -1

def main():
    assert(majority([3, 5, 3, 4, 2, 3, 3]) == 3)
    assert(majority([2, 3, 2, 3]) == -1)

main()
