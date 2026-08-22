/*

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Example
Given tree = [2,1] and node = 1:

    2
   /
  1
 return node 2.

Given tree = [2,1,3] and node = 2:

    2
   / \
  1  3

return node 3.

Note
If the given node has no in-order successor in the tree, return null.

Challenge
O(h), where h is the height of the BST.

*/

package main

import "fmt"

type Node struct {
	val   int
	left  *Node
	right *Node
}

func main() {
	root := &Node{
		val: 2,
		left: &Node{
			val: 1,
		},
		right: &Node{
			val: 3,
		},
	}

	node := root.left
	fmt.Println(inorderSuccessor(root, node))

	node = root
	fmt.Println(inorderSuccessor(root, node))
}

func inorderSuccessor(root, node *Node) *Node {
	var successor *Node
	for root != nil && root.val != node.val {
		if root.val > node.val {
			successor = root
			root = root.left
		} else {
			root = root.right
		}
	}
	if root == nil {
		return nil
	}

	if root.right == nil {
		return successor
	}

	root = root.right
	for root.left != nil {
		root = root.left
	}

	return root
}
