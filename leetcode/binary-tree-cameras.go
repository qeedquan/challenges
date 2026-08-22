/*

You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:
https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_01.png
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:
https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_02.png
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val == 0

*/

package main

const (
	UNCOVERED = iota
	COVERED
	CAMERA
)

type Node struct {
	val   int
	left  *Node
	right *Node
}

func main() {
	root1 := &Node{
		left: &Node{
			left:  &Node{},
			right: &Node{},
		},
	}

	root2 := &Node{
		left: &Node{
			left: &Node{
				left: &Node{
					right: &Node{},
				},
			},
		},
	}

	assert(cover(root1) == 1)
	assert(cover(root2) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cover(root *Node) int {
	result := 0
	if dfs(root, &result) == UNCOVERED {
		result += 1
	}
	return result
}

func dfs(root *Node, result *int) int {
	left, right := COVERED, COVERED
	if root.left != nil {
		left = dfs(root.left, result)
	}
	if root.right != nil {
		right = dfs(root.right, result)
	}

	if left == UNCOVERED || right == UNCOVERED {
		*result += 1
		return CAMERA
	}

	if left == CAMERA || right == CAMERA {
		return COVERED
	}

	return UNCOVERED
}
