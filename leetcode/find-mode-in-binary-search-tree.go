/*

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than or equal to the node's key.
    The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

Input: root = [1,null,2,2]
Output: [2]

Example 2:

Input: root = [0]
Output: [0]



Constraints:

    The number of nodes in the tree is in the range [1, 10^4].
    -10^5 <= Node.val <= 10^5


Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

*/

package main

import (
	"math"
)

func main() {
	t1 := &Node{
		val: 1,
		right: &Node{
			val: 2,
			left: &Node{
				val: 2,
			},
		},
	}

	t2 := &Node{
		val: 0,
	}

	assert(mode(t1) == 2)
	assert(mode(t2) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Node struct {
	val   int
	left  *Node
	right *Node
}

func mode(n *Node) int {
	m := make(map[int]int)
	traverse(n, m)
	return findmax(m)
}

func findmax(m map[int]int) int {
	r, u := math.MinInt, 0
	for k, v := range m {
		if u < v {
			r, u = k, v
		}
	}
	return r
}

func traverse(n *Node, m map[int]int) {
	if n == nil {
		return
	}

	m[n.val]++
	traverse(n.left, m)
	traverse(n.right, m)
}
