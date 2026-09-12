/*

One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character'#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:


Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:


Input: "1,#"
Output: false
Example 3:


Input: "9,#,#,1"
Output: false

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	test("9,3,4,#,#,1,#,#,2,#,6,#,#", true)
	test("1,#", false)
	test("9,#,#,1", false)
	test("9,#,1,#,#", true)
	test("1,7,2,#,#,6,5,#,#,11,#,#,9,#,9,5,#,#,#", true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r bool) {
	assert(verify(s) == r)
	if r {
		t := serialize(construct(s))
		fmt.Println(t)
		assert(s == t)
	} else {
		fmt.Printf("%s - invalid\n", s)
	}
}

/*

https://techlarry.github.io/Leetcode/331.%20Verify%20Preorder%20Serialization%20of%20a%20Binary%20Tree/

In a binary tree, if we consider null as leaves, then

all non-null node provides 2 outdegree and 1 indegree (2 children and 1 parent), except root
all null node provides 0 outdegree and 1 indegree (0 child and 1 parent).
Suppose we try to build this tree. During building, we record the difference between out degree and in degree diff = outdegree - indegree.
When the next node comes, we then decrease diff by 1, because the node provides an in degree.
If the node is not null, we increase diff by 2, because it provides two out degrees.
If a serialization is correct, diff should never be negative and diff will be zero when finished.

*/

func verify(s string) bool {
	t := strings.Split(s, ",")
	d := 1
	for _, t := range t {
		if d--; d < 0 {
			return false
		}
		if t != "#" {
			d += 2
		}
	}
	return d == 0
}

type Node struct {
	val   string
	left  *Node
	right *Node
}

func construct(s string) *Node {
	if s == "" {
		return nil
	}

	t := strings.Split(s, ",")
	r := &Node{val: t[0]}
	p := []*Node{r}
	for i := 1; i < len(t); i++ {
		n := len(p) - 1
		if n < 0 {
			return nil
		}
		x := p[n]
		y := &Node{val: t[i]}
		if x.left == nil {
			x.left = y
		} else if x.right == nil {
			x.right = y
			p = p[:n]
		}
		if y.val != "#" {
			p = append(p, y)
		}
	}
	return r
}

func serialize(n *Node) string {
	if n == nil {
		return ""
	}

	s := fmt.Sprint(n.val)
	if n.left != nil {
		s += ","
	}
	s += serialize(n.left)

	if n.right != nil {
		s += ","
	}
	s += serialize(n.right)

	return s
}
