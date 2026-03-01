/*

Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:

Input: [1,2,3,4,5]

          1
         / \
        2   3
       / \
      4   5

Output: [[4,5,3],[2],[1]]


Explanation:

1. Removing the leaves [4,5,3] would result in this tree:

          1
         /
        2


2. Now removing the leaf [2] would result in this tree:

          1


3. Now removing the leaf [1] would result in the empty tree:

          []

*/

package main

import (
	"fmt"
	"reflect"
)

type Node struct {
	val   int
	left  *Node
	right *Node
}

func main() {
	root1 := &Node{
		val: 1,
		left: &Node{
			val: 2,
			left: &Node{
				val: 4,
			},
			right: &Node{
				val: 5,
			},
		},
		right: &Node{
			val: 3,
		},
	}

	test(root1, [][]int{{4, 5, 3}, {2}, {1}})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(root *Node, expected [][]int) {
	result := leaves(root)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func leaves(root *Node) [][]int {
	result := [][]int{}
	recurse(root, &result)
	return result
}

func recurse(node *Node, result *[][]int) int {
	if node == nil {
		return -1
	}

	level := 1 + max(recurse(node.left, result), recurse(node.right, result))
	if len(*result) < level+1 {
		*result = append(*result, []int{})
	}
	(*result)[level] = append((*result)[level], node.val)
	return level
}
