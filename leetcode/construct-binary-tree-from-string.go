/*

Description
You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example 1:
Input: s = "4(2(3)(1))(6(5))"
Output: [4,2,6,3,1,5]

Example 2:
Input: s = "4(2(3)(1))(6(5)(7))"
Output: [4,2,6,3,1,5,7]

Example 3:
Input: s = "-4(2(3)(1))(6(5)(7))"
Output: [-4,2,6,3,1,5,7]

Constraints:

0 <= s.length <= 3 * 10^4
s consists of digits, '(', ')', and '-' only.
All numbers in the tree have value at most than 2^30.

*/

package main

import (
	"fmt"
	"reflect"
	"strconv"
	"strings"
)

type Node struct {
	val   int
	left  *Node
	right *Node
}

func main() {
	test("4(2(3)(1))(6(5))", []int{4, 2, 6, 3, 1, 5})
	test("4(2(3)(1))(6(5)(7))", []int{4, 2, 6, 3, 1, 5, 7})
	test("-4(2(3)(1))(6(5)(7))", []int{-4, 2, 6, 3, 1, 5, 7})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []int) {
	t := str2tree(s)
	p := bfs(t)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func str2tree(s string) *Node {
	return build(s)
}

func build(s string) *Node {
	if s == "" {
		return nil
	}

	p := strings.IndexAny(s, "(")
	if p == -1 {
		v, _ := strconv.Atoi(s)
		return &Node{val: v}
	}

	v, _ := strconv.Atoi(s[:p])
	r := &Node{val: v}
	j := p
	c := 0
	for i := p; i < len(s); i++ {
		if s[i] == '(' {
			c++
		} else if s[i] == ')' {
			c--
		}

		if c == 0 {
			if p == j {
				r.left = build(s[j+1 : i])
				j = i + 1
			} else {
				r.right = build(s[j+1 : i])
			}
		}
	}
	return r
}

func bfs(n *Node) []int {
	r := []int{}
	q := []*Node{n}
	for ; len(q) > 0; q = q[1:] {
		p := q[0]
		if p == nil {
			continue
		}

		r = append(r, p.val)
		if p.left != nil {
			q = append(q, p.left)
		}
		if p.right != nil {
			q = append(q, p.right)
		}
	}
	return r
}
