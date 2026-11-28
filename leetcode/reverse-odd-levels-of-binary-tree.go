/*

Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node.

Example 1:
https://assets.leetcode.com/uploads/2022/07/28/first_case1.png

Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]
Explanation:
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.

Example 2:
https://assets.leetcode.com/uploads/2022/07/28/second_case3.png

Input: root = [7,13,11]
Output: [7,11,13]
Explanation:
The nodes at level 1 are 13, 11, which are reversed and become 11, 13.
Example 3:

Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
Explanation:
The odd levels have non-zero values.
The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1 after the reversal.


Constraints:

The number of nodes in the tree is in the range [1, 2^14].
0 <= Node.val <= 10^5
root is a perfect binary tree.

Hint:
Try to solve recursively for each level independently.
While performing a depth-first search, pass the left and right nodes (which should be paired) to the next level. If the current level is odd, then reverse their values, or else recursively move to the next level.

*/

package main

func main() {
	a1 := &Node{
		val: 2,
		left: &Node{
			val: 3,
			left: &Node{
				val: 8,
			},
			right: &Node{
				val: 13,
			},
		},
		right: &Node{
			val: 5,
			left: &Node{
				val: 21,
			},
			right: &Node{
				val: 34,
			},
		},
	}
	b1 := &Node{
		val: 2,
		left: &Node{
			val: 5,
			left: &Node{
				val: 8,
			},
			right: &Node{
				val: 13,
			},
		},
		right: &Node{
			val: 3,
			left: &Node{
				val: 21,
			},
			right: &Node{
				val: 34,
			},
		},
	}

	a2 := &Node{
		val: 7,
		left: &Node{
			val: 13,
		},
		right: &Node{
			val: 11,
		},
	}
	b2 := &Node{
		val: 7,
		left: &Node{
			val: 11,
		},
		right: &Node{
			val: 13,
		},
	}

	a3 := &Node{
		val: 0,
		left: &Node{
			val: 1,
			left: &Node{
				val: 0,
				left: &Node{
					val: 1,
				},
				right: &Node{
					val: 1,
				},
			},
			right: &Node{
				val: 0,
				left: &Node{
					val: 1,
				},
				right: &Node{
					val: 1,
				},
			},
		},
		right: &Node{
			val: 2,
			left: &Node{
				val: 0,
				left: &Node{
					val: 2,
				},
				right: &Node{
					val: 2,
				},
			},
			right: &Node{
				val: 0,
				left: &Node{
					val: 2,
				},
				right: &Node{
					val: 2,
				},
			},
		},
	}
	b3 := &Node{
		val: 0,
		left: &Node{
			val: 2,
			left: &Node{
				val: 0,
				left: &Node{
					val: 2,
				},
				right: &Node{
					val: 2,
				},
			},
			right: &Node{
				val: 0,
				left: &Node{
					val: 2,
				},
				right: &Node{
					val: 2,
				},
			},
		},
		right: &Node{
			val: 1,
			left: &Node{
				val: 0,
				left: &Node{
					val: 1,
				},
				right: &Node{
					val: 1,
				},
			},
			right: &Node{
				val: 0,
				left: &Node{
					val: 1,
				},
				right: &Node{
					val: 1,
				},
			},
		},
	}

	test(a1, b1)
	test(a2, b2)
	test(a3, b3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b *Node) {
	revoddlvls(a)
	assert(equal(a, b))
}

type Node struct {
	val   int
	left  *Node
	right *Node
}

func revoddlvls(n *Node) *Node {
	recurse(n.left, n.right, true)
	return n
}

func recurse(l, r *Node, odd bool) {
	if l == nil {
		return
	}
	if odd {
		l.val, r.val = r.val, l.val
	}

	recurse(l.left, r.right, !odd)
	recurse(l.right, r.left, !odd)
}

func equal(a, b *Node) bool {
	if a == nil && b == nil {
		return true
	}
	if (a == nil && b != nil) || (a != nil && b == nil) || a.val != b.val {
		return false
	}
	return equal(a.left, b.left) && equal(a.right, b.right)
}
