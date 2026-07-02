/*

Given the root of a binary tree, return the leftmost value in the last row of the tree.

Example 1:


Input: root = [2,1,3]
Output: 1
Example 2:


Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7


Constraints:

The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1

*/

package main

func main() {
	t1 := &Node{
		val: 2,
		left: &Node{
			val: 1,
		},
		right: &Node{
			val: 3,
		},
	}

	t2 := &Node{
		val: 1,
		left: &Node{
			val: 2,
			left: &Node{
				val: 4,
			},
		},
		right: &Node{
			val: 3,
			left: &Node{
				val: 5,
				left: &Node{
					val: 7,
				},
			},
			right: &Node{
				val: 6,
			},
		},
	}

	assert(bottomleft(t1) == 1)
	assert(bottomleft(t2) == 7)
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

func bottomleft(n *Node) int {
	if n == nil {
		return 0
	}

	m := [2]int{}
	p := []*Node{n}
	d := [][2]int{m}
	r := n.val
	for ; len(p) > 0; p, d = p[1:], d[1:] {
		x, l := p[0], d[0]
		if l[0] > m[0] || (l[0] == m[0] && l[1] < m[1]) {
			r, m = x.val, l
		}
		if x.left != nil {
			p = append(p, x.left)
			d = append(d, [2]int{l[0] + 1, l[1] - 1})
		}
		if x.right != nil {
			p = append(p, x.right)
			d = append(d, [2]int{l[0] + 1, l[1] + 1})
		}
	}
	return r
}
