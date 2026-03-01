#!/usr/bin/env python3

"""

Given a non-empty list/array containing only non-negative integers like this:

[0, 0, 0, 8, 1, 4, 3, 5, 6, 4, 1, 2, 0, 0, 0, 0]
Output the list with trailing and leading zeroes removed.

The output for this would be:

[8, 1, 4, 3, 5, 6, 4, 1, 2]
Some other test cases:

[0, 4, 1, 2, 0, 1, 2, 4, 0] > [4, 1, 2, 0, 1, 2, 4]
[0, 0, 0, 0, 0, 0] > nothing
[3, 4, 5, 0, 0] > [3, 4, 5]
[6] > [6]

Shortest code wins

"""

def trimzeros(a):
    i = 0
    j = len(a) - 1
    while i < j:
        if a[i] == 0:
            i += 1
        elif a[j] == 0:
            j -= 1
        else:
            break

    a = a[i:j+1]
    if len(a) > 0 and a[0] == 0:
        a = a[1:]
    
    return a

def main():
    assert(trimzeros([0, 0, 0, 8, 1, 4, 3, 5, 6, 4, 1, 2, 0, 0, 0, 0]) == [8, 1, 4, 3, 5, 6, 4, 1, 2])
    assert(trimzeros([0, 4, 1, 2, 0, 1, 2, 4, 0]) == [4, 1, 2, 0, 1, 2, 4])
    assert(trimzeros([0, 0, 0, 0, 0, 0]) == [])
    assert(trimzeros([3, 4, 5, 0, 0]) == [3, 4, 5])
    assert(trimzeros([6]) == [6])
    assert(trimzeros([0, 1]) == [1])

main()
