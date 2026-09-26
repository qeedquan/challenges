#!/usr/bin/env python3

"""

Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:

Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]


Constraints:

The number of nodes in each tree is in the range [0, 5000].
-10^5 <= Node.val <= 10^5

"""

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def get_elements(root):
    result = []
    stack = [root]
    while len(stack) > 0:
        cur = stack.pop()
        if cur == None:
            continue
        
        stack.append(cur.left)
        stack.append(cur.right)

        result.append(cur.val)
    return result

def get_all_elements(root1, root2):
    list1 = get_elements(root1)
    list2 = get_elements(root2)
    list1.extend(list2)
    list1 = sorted(list1)
    return list1

def main():
    tree1 = Node(2, Node(1), Node(4))
    tree2 = Node(1, Node(0), Node(3))

    tree3 = Node(1, None, Node(8))
    tree4 = Node(8, Node(1), None)

    assert(get_all_elements(tree1, tree2) == [0, 1, 1, 2, 3, 4])
    assert(get_all_elements(tree3, tree4) == [1, 1, 8, 8])

main()
