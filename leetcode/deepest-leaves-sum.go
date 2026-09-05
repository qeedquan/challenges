/*

Given the root of a binary tree, return the sum of values of its deepest leaves.

Example 1:
https://assets.leetcode.com/uploads/2019/07/31/1483_ex1.png
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19


Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100

*/

package main

type Node struct {
	val   int
	left  *Node
	right *Node
}

func main() {
	t1 := &Node{
		val: 1,
		left: &Node{
			val: 2,
			left: &Node{
				val: 4,
				left: &Node{
					val: 7,
				},
			},
			right: &Node{
				val: 5,
			},
		},
		right: &Node{
			val: 3,
			right: &Node{
				val: 6,
				right: &Node{
					val: 8,
				},
			},
		},
	}

	t2 := &Node{
		val: 6,
		left: &Node{
			val: 7,
			left: &Node{
				val: 2,
				left: &Node{
					val: 9,
				},
			},
			right: &Node{
				val: 7,
				left: &Node{
					val: 1,
				},
				right: &Node{
					val: 4,
				},
			},
		},
		right: &Node{
			val: 8,
			left: &Node{
				val: 1,
			},
			right: &Node{
				val: 3,
				right: &Node{
					val: 5,
				},
			},
		},
	}

	assert(deepestleavessum(t1) == 15)
	assert(deepestleavessum(t2) == 19)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func deepestleavessum(root *Node) int {
	queue := []*Node{root}
	total := 0
	for len(queue) > 0 {
		total = 0
		for i := len(queue); i > 0; i-- {
			node := queue[0]
			queue = queue[1:]
			total += node.val
			if node.left != nil {
				queue = append(queue, node.left)
			}
			if node.right != nil {
				queue = append(queue, node.right)
			}
		}
	}
	return total
}
