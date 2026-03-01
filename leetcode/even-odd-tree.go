/*

A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

Example 1:
https://assets.leetcode.com/uploads/2020/09/15/sample_1_1966.png
Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.

Example 2:
https://assets.leetcode.com/uploads/2020/09/15/sample_2_1966.png
Input: root = [5,4,2,3,3,7]
Output: false
Explanation: The node values on each level are:
Level 0: [5]
Level 1: [4,2]
Level 2: [3,3,7]
Node values in level 2 must be in strictly increasing order, so the tree is not Even-Odd.

Example 3:
https://assets.leetcode.com/uploads/2020/09/22/sample_1_333_1966.png
Input: root = [5,9,1,3,5,7]
Output: false
Explanation: Node values in the level 1 should be even integers.


Constraints:

The number of nodes in the tree is in the range [1, 10^5].
1 <= Node.val <= 10^6

Hint 1
Use the breadth-first search to go through all nodes layer by layer.

*/

package main

import "math"

type Node struct {
	val   int
	left  *Node
	right *Node
}

func main() {
	t1 := &Node{
		val: 1,
		left: &Node{
			val: 10,
			left: &Node{
				val: 3,
				left: &Node{
					val: 12,
				},
				right: &Node{
					val: 8,
				},
			},
		},
		right: &Node{
			val: 4,
			left: &Node{
				val: 7,
				left: &Node{
					val: 6,
				},
			},
			right: &Node{
				val: 9,
				right: &Node{
					val: 2,
				},
			},
		},
	}

	t2 := &Node{
		val: 5,
		left: &Node{
			val: 4,
			left: &Node{
				val: 3,
			},
			right: &Node{
				val: 3,
			},
		},
		right: &Node{
			val: 2,
			left: &Node{
				val: 7,
			},
		},
	}

	t3 := &Node{
		val: 5,
		left: &Node{
			val: 9,
			left: &Node{
				val: 3,
			},
			right: &Node{
				val: 5,
			},
		},
		right: &Node{
			val: 1,
			left: &Node{
				val: 7,
			},
		},
	}

	assert(evenoddtree(t1) == true)
	assert(evenoddtree(t2) == false)
	assert(evenoddtree(t3) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func evenoddtree(root *Node) bool {
	even := true
	queue := []*Node{root}
	for len(queue) > 0 {
		prev := math.MaxInt
		if even {
			prev = 0
		}

		for i := len(queue); i > 0; i-- {
			root = queue[0]
			queue = queue[1:]
			if even && (root.val%2 == 0 || prev >= root.val) {
				return false
			}
			if !even && (root.val%2 == 1 || prev <= root.val) {
				return false
			}
			prev = root.val
			if root.left != nil {
				queue = append(queue, root.left)
			}
			if root.right != nil {
				queue = append(queue, root.right)
			}
		}
		even = !even
	}
	return true
}
