/*

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	t1 := &Node{
		val: 3,
		left: &Node{
			val: 9,
		},
		right: &Node{
			val: 20,
			left: &Node{
				val: 15,
			},
			right: &Node{
				val: 7,
			},
		},
	}

	test(t1, [][]int{{3}, {9, 20}, {15, 7}})
	test(nil, [][]int{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n *Node, r [][]int) {
	p := levelorder(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

type Node struct {
	val   int
	left  *Node
	right *Node
}

func levelorder(n *Node) [][]int {
	if n == nil {
		return [][]int{}
	}

	m := make(map[int][]int)
	q := []*Node{n}
	d := []int{0}
	h := 0
	for ; len(q) > 0; q, d = q[1:], d[1:] {
		p := q[0]
		l := d[0]
		h = max(h, l)

		if p.left != nil {
			q = append(q, p.left)
			d = append(d, l+1)
		}
		if p.right != nil {
			q = append(q, p.right)
			d = append(d, l+1)
		}

		m[l] = append(m[l], p.val)
	}

	r := make([][]int, h+1)
	for i, v := range m {
		r[i] = v
	}

	return r
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
