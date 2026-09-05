/*

Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.

Example 1:
https://assets.leetcode.com/uploads/2020/10/13/ex1.jpg
Input: root = [5,4,5,1,1,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 5).

Example 2:
https://assets.leetcode.com/uploads/2020/10/13/ex2.jpg
Input: root = [1,4,5,4,4,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 4).

Constraints:

The number of nodes in the tree is in the range [0, 10^4].
-1000 <= Node.val <= 1000
The depth of the tree will not exceed 1000.

*/

package main

type Node struct {
	val   int
	left  *Node
	right *Node
}

func main() {
	tree1 := &Node{
		val: 5,
		left: &Node{
			val: 4,
			left: &Node{
				val: 1,
			},
			right: &Node{
				val: 2,
			},
		},
		right: &Node{
			val: 5,
			right: &Node{
				val: 5,
			},
		},
	}

	tree2 := &Node{
		val: 1,
		left: &Node{
			val: 4,
			left: &Node{
				val: 4,
			},
			right: &Node{
				val: 4,
			},
		},
		right: &Node{
			val: 5,
			right: &Node{
				val: 5,
			},
		},
	}

	assert(path(tree1) == 2)
	assert(path(tree2) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func path(root *Node) int {
	result := 0
	dfs(root, &result)
	return result
}

func dfs(node *Node, result *int) int {
	if node == nil {
		return 0
	}

	left := dfs(node.left, result)
	right := dfs(node.right, result)

	if node.left != nil && node.val == node.left.val {
		left += 1
	} else {
		left = 0
	}

	if node.right != nil && node.val == node.right.val {
		right += 1
	} else {
		right = 0
	}

	*result = max(*result, left+right)

	return max(left, right)
}
