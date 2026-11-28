/*

Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]

Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]

Constraints:

    The number of nodes in the tree is in the range [0, 10^4].
    0 <= Node.val <= 10^4
    The height of the n-ary tree is less than or equal to 1000.

Follow up: Recursive solution is trivial, could you do it iteratively?

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	t1 := &Node{
		val: 1,
		children: []*Node{
			{
				val: 3,
				children: []*Node{
					{val: 5},
					{val: 6},
				},
			},
			{val: 2},
			{val: 4},
		},
	}

	t2 := &Node{
		val: 1,
		children: []*Node{
			{val: 2},
			{
				val: 3,
				children: []*Node{
					{val: 6},
					{
						val: 7,
						children: []*Node{
							{
								val: 11,
								children: []*Node{
									{val: 14},
								},
							},
						},
					},
				},
			},
			{
				val: 4,
				children: []*Node{
					{val: 8,
						children: []*Node{
							{val: 12},
						},
					},
				},
			},
			{
				val: 5,
				children: []*Node{
					{
						val: 9,
						children: []*Node{
							{val: 13},
						},
					},
					{val: 10},
				},
			},
		},
	}

	test(t1, []int{5, 6, 3, 2, 4, 1})
	test(t2, []int{2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n *Node, r []int) {
	p := postorder(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

type Node struct {
	val      int
	children []*Node
}

func postorder(n *Node) []int {
	if n == nil {
		return []int{}
	}

	var r []int
	for _, c := range n.children {
		r = append(r, postorder(c)...)
	}
	r = append(r, n.val)
	return r
}
