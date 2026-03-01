/*

A maximum tree is a tree where every node has a value greater than any other value in its subtree.

You are given the root of a maximum binary tree and an integer val.

Just as in the previous problem, the given tree was constructed from a list a (root = Construct(a)) recursively with the following Construct(a) routine:

If a is empty, return null.
Otherwise, let a[i] be the largest element of a. Create a root node with the value a[i].
The left child of root will be Construct([a[0], a[1], ..., a[i - 1]]).
The right child of root will be Construct([a[i + 1], a[i + 2], ..., a[a.length - 1]]).
Return root.
Note that we were not given a directly, only a root node root = Construct(a).

Suppose b is a copy of a with the value val appended to it. It is guaranteed that b has unique values.

Return Construct(b).

Example 1:
https://assets.leetcode.com/uploads/2021/08/09/maxtree1.JPG
Input: root = [4,1,3,null,null,2], val = 5
Output: [5,4,null,1,3,null,null,2]
Explanation: a = [1,4,2,3], b = [1,4,2,3,5]

Example 2:
https://assets.leetcode.com/uploads/2021/08/09/maxtree21.JPG
Input: root = [5,2,4,null,1], val = 3
Output: [5,2,4,null,1,null,3]
Explanation: a = [2,1,5,4], b = [2,1,5,4,3]

Example 3:
https://assets.leetcode.com/uploads/2021/08/09/maxtree3.JPG
Input: root = [5,2,3,null,1], val = 4
Output: [5,2,4,null,1,3]
Explanation: a = [2,1,5,3], b = [2,1,5,3,4]


Constraints:

The number of nodes in the tree is in the range [1, 100].
1 <= Node.val <= 100
All the values of the tree are unique.
1 <= val <= 100

*/

package main

import (
	"cmp"
)

type Node[T cmp.Ordered] struct {
	val   T
	left  *Node[T]
	right *Node[T]
}

func main() {
	t1 := N(4, N(1), N(3, N(2)))
	t2 := N(5, N(2, nil, N(1)), N(4))
	t3 := N(5, N(2, nil, N(1)), N(3))

	t1 = insertmax(t1, 5)
	t2 = insertmax(t2, 3)
	t3 = insertmax(t3, 4)

	assert(t1.val == 5)
	assert(t2.right.right.val == 3)
	assert(t3.right.val == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func N[T cmp.Ordered](val T, child ...*Node[T]) *Node[T] {
	node := &Node[T]{val: val}
	if len(child) > 0 {
		node.left = child[0]
	}
	if len(child) > 1 {
		node.right = child[1]
	}
	return node
}

func insertmax[T cmp.Ordered](root *Node[T], val T) *Node[T] {
	if root == nil {
		return &Node[T]{val: val}
	}

	if val > root.val {
		node := &Node[T]{val: val}
		node.left = root
		return node
	}

	curr := root
	for curr.right != nil && curr.right.val > val {
		curr = curr.right
	}

	node := &Node[T]{val: val}
	curr.right, node.left = node, curr.right
	return root
}
