/*

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Example 1:

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100


Follow up: Can you flatten the tree in-place (with O(1) extra space)?

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]any{1, 2, 5, 3, 4, nil, 6}, []any{1, nil, 2, nil, 3, nil, 4, nil, 5, nil, 6})
	test([]any{}, []any{})
	test([]any{0}, []any{0})
	test([]any{1, nil, 2}, []any{1, nil, 2})
	test([]any{1, nil, 2, nil, 3, nil, nil}, []any{1, nil, 2, nil, 3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []any) {
	f := flatten(mklvl(a))
	p := lvl(f)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

type Node struct {
	val   int
	left  *Node
	right *Node
}

func flatten(r *Node) *Node {
	y := (*Node)(nil)
	p := []*Node{r}
	for {
		n := len(p)
		if n == 0 {
			break
		}

		x := p[n-1]
		p = p[:n-1]
		if x != nil {
			if y != nil {
				y.right, y.left = x, nil
			}
			y = x
			p = append(p, x.right, x.left)
		}
	}
	return r
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

func lvl(r *Node) []any {
	p := []any{}
	if r == nil {
		return p
	}

	q := []*Node{r}
	for ; len(q) > 0; q = q[1:] {
		x := q[0]
		if x != nil {
			p = append(p, x.val)
			q = append(q, x.left, x.right)
		} else {
			p = append(p, nil)
		}
	}

	for {
		n := len(p)
		if n == 0 {
			break
		}
		if p[n-1] != nil {
			break
		}
		p = p[:n-1]
	}

	return p
}
