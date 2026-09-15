#!/usr/bin/env python3

"""

Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

Example 1:

Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]

Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.

"""

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def levelorder(root):
    if root == None:
        return []

    result = []
    queue = [root]
    while len(queue) > 0:
        cur = queue[0]
        if cur.left != None:
            queue.append(cur.left)
        if cur.right != None:
            queue.append(cur.right)
        queue = queue[1:]
        
        result.append(cur.val)

    return result

# https://twchen.gitbook.io/leetcode/construct-binary-tree-from-preorder-and-postorder-traversal
def prepost(pre, post):
    if len(pre) == 0 or len(pre) != len(post):
        return None

    root = Node(pre[0])
    stack = [root]

    npre = 1
    npost = 0
    while npre < len(pre):
        while len(stack) > 0 and npost < len(post) and stack[-1].val == post[npost]:
            stack.pop()
            npost += 1
        
        if len(stack) == 0:
            return None
        
        node = Node(pre[npre])
        cur = stack[-1]
        if cur.left == None:
            cur.left = node
        else:
            cur.right = node
        stack.append(node)
        npre += 1

    return root

def test(pre, post, result):
    root = prepost(pre, post)
    values = levelorder(root)
    print(values)
    assert(values == result)

def main():
    test([1, 2, 4, 5, 3, 6, 7], [4, 5, 2, 6, 7, 3, 1], [1, 2, 3, 4, 5, 6, 7])
    test([1], [1], [1])

main()
