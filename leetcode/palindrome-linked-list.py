#!/usr/bin/env python3

"""

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false

Constraints:

    The number of nodes in the list is in the range [1, 10^5].
    0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?

"""

class List:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

def makelist(a):
    h = p = None
    for v in a:
        q = List(v)
        if h == None:
            h = q
        else:
            p.next = q
        p = q
    return h

def traverse(h, t):
    if t == None:
        return (h, True)
    
    (h, ok) = traverse(h, t.next)
    if not ok or t.val != h.val:
        return (None, False)

    return (h.next, True)

def palindrome(h):
    (_, ok) = traverse(h, h)
    return ok

def main():
    assert(palindrome(makelist([1, 2, 2, 1])) == True)
    assert(palindrome(makelist([1, 2])) == False)
    assert(palindrome(makelist([1, 0, 1, 2])) == False)
    assert(palindrome(makelist([1])) == True)
    assert(palindrome(makelist([])) == True)
    assert(palindrome(makelist([1, 2, 3, 4, 5, 4, 3, 2, 1])) == True)
    assert(palindrome(makelist([1, 1])) == True)

main()
