/*

Given a binary tree root and a linked list with head as the first node.

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

Example 1:

Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.

Example 2:

Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Example 3:

Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.


Constraints:

The number of nodes in the tree will be in the range [1, 2500].
The number of nodes in the list will be in the range [1, 100].
1 <= Node.val <= 100 for each node in the linked list and binary tree.

*/

package main

func main() {
	t1 := mklvl([]any{1, 4, 4, nil, 2, 2, nil, 1, nil, 6, 8, nil, nil, nil, nil, 1, 3})
	l1 := mklist(1, 4, 2, 6)
	l2 := mklist(1, 4, 2, 6, 8)
	l3 := mklist(2, 8, 1)
	l4 := mklist(3)

	assert(subpath(t1, l1) == true)
	assert(subpath(t1, l2) == false)
	assert(subpath(t1, l3) == true)
	assert(subpath(t1, l4) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Node struct {
	val   int
	left  *Node
	right *Node
}

type Element struct {
	val  int
	next *Element
}

func subpath(n *Node, e *Element) bool {
	if match(n, e) {
		return true
	}

	if n != nil {
		if n.left != nil && subpath(n.left, e) {
			return true
		}
		if n.right != nil && subpath(n.right, e) {
			return true
		}
	}

	return false
}

func match(n *Node, e *Element) bool {
	if e == nil {
		return true
	}
	if n == nil || n.val != e.val {
		return false
	}
	return match(n.left, e.next) || match(n.right, e.next)
}

func mknode(x any) *Node {
	if x == nil {
		return nil
	}
	return &Node{val: x.(int)}
}

func mklvl(a []any) *Node {
	if len(a) == 0 {
		return nil
	}

	var (
		c *Node
		l int
	)
	r := mknode(a[0])
	q := []*Node{r}
	for i := 1; i < len(a); i++ {
		n := mknode(a[i])
		if l == 0 {
			c, q = q[0], q[1:]
			c.left, l = n, 1
		} else {
			c.right, l = n, 0
		}
		if a[i] != nil {
			q = append(q, n)
		}
	}
	return r
}

func mklist(v ...int) *Element {
	var h *Element

	p := &h
	for _, v := range v {
		q := &Element{val: v}
		*p, p = q, &q.next
	}
	return h
}
