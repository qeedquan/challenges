/*

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Example 1:

Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true

Example 2:

Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false

Constraints:

    The number of nodes in each tree will be in the range [1, 200].
    Both of the given trees will have values in the range [0, 200].

*/

package main

import (
	"reflect"
)

func main() {
	a1 := &Node{
		val: 3,
		left: &Node{
			val: 5,
			left: &Node{
				val: 6,
			},
			right: &Node{
				val: 2,
				left: &Node{
					val: 7,
				},
				right: &Node{
					val: 4,
				},
			},
		},
		right: &Node{
			val: 1,
			left: &Node{
				val: 9,
			},
			right: &Node{
				val: 8,
			},
		},
	}
	b1 := &Node{
		val: 3,
		left: &Node{
			val: 5,
			left: &Node{
				val: 6,
			},
			right: &Node{
				val: 7,
			},
		},
		right: &Node{
			val: 1,
			left: &Node{
				val: 4,
			},
			right: &Node{
				val: 2,
				left: &Node{
					val: 9,
				},
				right: &Node{
					val: 8,
				},
			},
		},
	}

	a2 := &Node{
		val: 1,
		left: &Node{
			val: 2,
		},
		right: &Node{
			val: 3,
		},
	}
	b2 := &Node{
		val: 1,
		left: &Node{
			val: 3,
		},
		right: &Node{
			val: 2,
		},
	}

	assert(similar(a1, b1) == true)
	assert(similar(a2, b2) == false)
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

func similar(a, b *Node) bool {
	var p, q []int
	leaves(a, &p)
	leaves(b, &q)
	return reflect.DeepEqual(p, q)
}

func leaves(n *Node, r *[]int) {
	if n == nil {
		return
	}

	if n.left == nil && n.right == nil {
		*r = append(*r, n.val)
	}

	leaves(n.left, r)
	leaves(n.right, r)
}
