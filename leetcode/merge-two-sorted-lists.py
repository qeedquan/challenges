#!/usr/bin/env python3

"""

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

"""

class List:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

def makelist(a):
    h, p = None, None
    for v in a:
        q = List(v)
        if h == None:
            h = q
        else:
            p.next = q
        p = q
    return h

def list2array(l):
    r = []
    while l != None:
        r.append(l.val)
        l = l.next
    return r

def merge(a, b):
    if a == None:
        return b
    if b == None:
        return a

    h, p = None, None
    while a != None and b != None:
        if a.val < b.val:
            q, a = a, a.next
        else:
            q, b = b, b.next

        if p == None:
            h, p = q, q
        else:
            p.next, p = q, q

        p.next = None

    if p != None:
        if a != None:
            p.next = a
        else:
            p.next = b

    return h

def test(a, b, r):
    x = makelist(a)
    y = makelist(b)
    z = merge(x, y)
    p = list2array(z)
    print(p)
    assert(p == r)

def main():
    test([1, 2, 4], [1, 3, 4], [1, 1, 2, 3, 4, 4])
    test([], [], [])
    test([], [0], [0])
    test([1], [2, 3], [1, 2, 3])
    test([9, 10, 11], [12], [9, 10, 11, 12])

main()
