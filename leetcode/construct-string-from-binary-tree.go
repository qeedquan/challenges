/*

Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:

Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"

Example 2:

Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -1000 <= Node.val <= 1000

*/

package main

import "fmt"

func main() {
	t1 := &Node{
		val: 1,
		left: &Node{
			val: 2,
			left: &Node{
				val: 4,
			},
		},
		right: &Node{
			val: 3,
		},
	}

	t2 := &Node{
		val: 1,
		left: &Node{
			val: 2,
			right: &Node{
				val: 4,
			},
		},
		right: &Node{
			val: 3,
		},
	}

	assert(tree2str(t1) == "1(2(4))(3)")
	assert(tree2str(t2) == "1(2()(4))(3)")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Node struct {
	val         int
	left, right *Node
}

func tree2str(n *Node) string {
	if n == nil {
		return ""
	}

	s := fmt.Sprint(n.val)
	x := tree2str(n.left)
	y := tree2str(n.right)
	if x != "" || (x == "" && y != "") {
		s += fmt.Sprintf("(%v)", x)
	}
	if y != "" {
		s += fmt.Sprintf("(%v)", y)
	}

	return s
}
