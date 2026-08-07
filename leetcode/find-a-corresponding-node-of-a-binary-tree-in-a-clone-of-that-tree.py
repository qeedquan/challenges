#!/usr/bin/env python3

"""

Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.


Example 1:

Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.

Example 2:

Input: tree = [7], target =  7
Output: 7

Example 3:

Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4


Constraints:

The number of nodes in the tree is in the range [1, 10^4].
The values of the nodes of the tree are unique.
target node is a node from the original tree and is not null.


Follow up: Could you solve the problem if repeated values on the tree are allowed?

"""

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def clone(n):
    if n == None:
        return None
    return Node(n.val, clone(n.left), clone(n.right))

def find(a, b, v):
    if b == None:
        return None

    p = [b]
    while len(p) > 0:
        n = p.pop()
        if n.val == v:
            return n
        if n.left != None:
            p.append(n.left)
        if n.right != None:
            p.append(n.right)
    
    return None

def test(n, v):
    m = find(n, clone(n), v)
    assert(m != None and m.val == v)

def main():
    t1 = Node(7, Node(4), Node(3, Node(6), Node(9)))
    t2 = Node(8, None, Node(6, None, Node(5, None, Node(4, None, Node(3, None, Node(2, None, Node(1)))))))

    test(t1, 3)
    test(t2, 4)

main()
