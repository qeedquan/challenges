#!/usr/bin/env python3

"""

Given a list of integers, return the nth smallest integer in the list. Only distinct elements should be considered when calculating the answer. n will always be positive (n > 0)

If the nth small integer doesn't exist, return -1 (C++) / None (Python) / nil (Ruby) / null (JavaScript).

Notes:

"indexing" starts from 1
huge lists (of 1 million elements) will be tested
Examples
nthSmallest([1, 3, 4, 5], 7)        ==> null  // n is more than the size of the list
nthSmallest([4, 3, 4, 5], 4)        ==> null  // 4th smallest integer doesn't exist
nthSmallest([45, -10, 4, 5, 4], 4)  ==> 45   // 4th smallest integer is 45
If you get a timeout, just try to resubmit your solution. However, if you always get a timeout, review your code.

"""

def nth_smallest(a, n):
    a = sorted(list(set(a)))
    if n > len(a):
        return None
    return a[n - 1]

def main():
    assert(nth_smallest([1, 3, 4, 5],  7) == None)
    assert(nth_smallest([4, 3, 4, 5],  4) == None)
    assert(nth_smallest([45, -10, 4, 5, 4],  4) == 45)
    assert(nth_smallest([14, 12, 46, 34, 334], 3) == 34)

    l = [455555, 2222222, 3333333, 9879799, 79977979, 79977979, 79977979, 79977979, 79977979, 79977979, 79977979, 79977979]
    assert(nth_smallest(l, 3) == 3333333)
    assert(nth_smallest(l, 6) == None)

main()

