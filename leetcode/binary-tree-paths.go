/*

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:

Input: root = [1]
Output: ["1"]

Constraints:

    The number of nodes in the tree is in the range [1, 100].
    -100 <= Node.val <= 100

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	t1 := &Node{
		val: 1,
		left: &Node{
			val: 2,
			right: &Node{
				val: 5,
			},
		},
		right: &Node{
			val: 3,
		},
	}
	t2 := &Node{
		val: 1,
	}

	test(t1, [][]int{{1, 2, 5}, {1, 3}})
	test(t2, [][]int{{1}})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n *Node, r [][]int) {
	p := treepaths(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

type Node struct {
	val   int
	left  *Node
	right *Node
}

func treepaths(n *Node) [][]int {
	var r [][]int
	recurse(n, &r, []int{})
	return r
}

func recurse(n *Node, r *[][]int, p []int) {
	if n == nil {
		return
	}

	p = append(p, n.val)
	if n.left == nil && n.right == nil {
		*r = append(*r, p)
	}

	recurse(n.left, r, p)
	recurse(n.right, r, p)
}
