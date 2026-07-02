/*

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{9, 3, 15, 20, 7}, []int{9, 15, 7, 20, 3}, []int{3, 9, 20, 15, 7})
	test([]int{-1}, []int{-1}, []int{-1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(in, post, result []int) {
	root := inpost(in, post)
	values := levelorder(root)
	fmt.Println(values)
	assert(reflect.DeepEqual(values, result))
}

type Node struct {
	val   int
	left  *Node
	right *Node
}

/*

https://ttzztt.gitbooks.io/lc/content/construct-binary-tree-from-inorder-and-postorder-traversal.html

The the basic idea is to take the last element in postorder array as the root, find the position of the root in the inorder array;
then locate the range for left sub-tree and right sub-tree and do recursion. Use a HashMap to record the index of root in the inorder array.

*/

func inpost(in, post []int) *Node {
	inlut := make(map[int]int)
	for i, v := range in {
		inlut[v] = i
	}

	return build(post, len(post)-1, in, 0, len(in)-1, inlut)
}

func build(post []int, npost int, in []int, nin0, nin1 int, inlut map[int]int) *Node {
	if nin0 > nin1 || npost < 0 {
		return nil
	}

	root := &Node{val: post[npost]}
	i, ok := inlut[post[npost]]
	if !ok {
		return nil
	}

	root.right = build(post, npost-1, in, i+1, nin1, inlut)
	root.left = build(post, npost-1-(nin1-i), in, nin0, i-1, inlut)
	return root
}

func levelorder(root *Node) []int {
	if root == nil {
		return []int{}
	}

	result := []int{}
	queue := []*Node{root}
	for len(queue) > 0 {
		cur := queue[0]
		if cur.left != nil {
			queue = append(queue, cur.left)
		}
		if cur.right != nil {
			queue = append(queue, cur.right)
		}
		queue = queue[1:]

		result = append(result, cur.val)
	}
	return result
}
