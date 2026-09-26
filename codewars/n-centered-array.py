#!/usr/bin/env python3

"""

An array is called centered-N if some consecutive sequence of elements of the array sum to N and this sequence is preceded and followed by the same number of elements.

Example:

[3,2,10,4,1,6,9] is centered-15
because the sequence 10,4,1 sums to 15 and the sequence 
is preceded by two elements [3,2] and followed by two elements [6,9]

Write a method called isCenteredN that returns :

true if its array argument is not empty and centered-N or empty and centered-0
otherwise returns false.

"""

def is_centered(x, n):
    for i in range(len(x)//2 + 1):
        if sum(x[i : len(x)-i]) == n:
            return True
    return False

def main():
    assert(is_centered([0, 0, 0], 0) == True)
    assert(is_centered([2, 10, 4, 1, 6, 9], 15) == False)
    assert(is_centered([9, 0, 6], 0) == True)
    assert(is_centered([], 25) == False)
    assert(is_centered([25], 25) == True)
    assert(is_centered([25, 26, 23, 24], 0) == True)
    assert(is_centered([2, 1, 2], 0) == False)
    assert(is_centered([1, 1, 15, -1, -1], 15) == True)
    assert(is_centered([1, 1, 15, -1, -1], 6) == False)
    assert(is_centered([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 0) == True)

main()

