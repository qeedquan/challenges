/*

You are given all the nodes of an N-ary tree as an array of Node objects, where each node has a unique value.

Return the root of the N-ary tree.

Custom testing:

An N-ary tree can be serialized as represented in its level order traversal where each group of children is separated by the null value (see examples).
For example, the above tree is serialized as [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].

The testing will be done in the following way:

The input data should be provided as a serialization of the tree.
The driver code will construct the tree from the serialized input data and put each Node object into an array in an arbitrary order.
The driver code will pass the array to findRoot, and your function should find and return the root Node object in the array.
The driver code will take the returned Node object and serialize it. If the serialized value and the input data are the same, the test passes.

Example 1:
Input: tree = [1,null,3,2,4,null,5,6]
Output: [1,null,3,2,4,null,5,6]
Explanation: The tree from the input data is shown above.
The driver code creates the tree and gives findRoot the Node objects in an arbitrary order.
For example, the passed array could be [Node(5),Node(4),Node(3),Node(6),Node(2),Node(1)] or [Node(2),Node(6),Node(1),Node(3),Node(5),Node(4)].
The findRoot function should return the root Node(1), and the driver code will serialize it and compare with the input data.
The input data and serialized Node(1) are the same, so the test passes.

Example 2:
Input: tree = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]

Constraints:

The total number of nodes is between [1, 5 * 10^4].
Each node has a unique value.

Follow up:

Could you solve this problem in constant space complexity with a linear time algorithm?

*/

package main

type Node struct {
	val      int
	children []*Node
}

func main() {
	n1 := &Node{val: 1}
	n2 := &Node{val: 2}
	n3 := &Node{val: 3}
	n4 := &Node{val: 4}
	n5 := &Node{val: 5}
	n6 := &Node{val: 6}
	n7 := &Node{val: 7}
	n8 := &Node{val: 8}
	n9 := &Node{val: 9}
	n10 := &Node{val: 10}
	n11 := &Node{val: 11}
	n12 := &Node{val: 12}
	n13 := &Node{val: 13}
	n14 := &Node{val: 14}

	n1.children = []*Node{n3, n2, n4}
	n3.children = []*Node{n5, n6}
	assert(findroot([]*Node{n5, n4, n3, n6, n2, n1}) == n1)
	assert(findroot([]*Node{n2, n6, n1, n3, n5, n4}) == n1)

	n1.children = []*Node{n2, n3, n4, n5}
	n3.children = []*Node{n6, n7}
	n4.children = []*Node{n8}
	n5.children = []*Node{n9, n10}
	n7.children = []*Node{n11, n14}
	n8.children = []*Node{n12}
	n9.children = []*Node{n13}
	assert(findroot([]*Node{n14, n13, n12, n11, n10, n9, n8, n7, n6, n5, n4, n3, n2, n1}) == n1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func findroot(tree []*Node) *Node {
	xor := 0
	for _, node := range tree {
		xor ^= node.val
		for _, child := range node.children {
			xor ^= child.val
		}
	}

	for i := range tree {
		if tree[i].val == xor {
			return tree[i]
		}
	}
	return nil
}
