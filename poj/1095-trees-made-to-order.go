/*

Description

We can number binary trees using the following scheme:
The empty tree is numbered 0.
The single-node tree is numbered 1.
All binary trees having m nodes have numbers less than all those having m+1 nodes.
Any binary tree having m nodes with left and right subtrees L and R is numbered n such that all trees having m nodes numbered > n have either Left subtrees numbered higher than L, or A left subtree = L and a right subtree numbered higher than R.

The first 10 binary trees and tree number 20 in this sequence are shown below:

http://poj.org/images/1095/1095_1.gif

Your job for this problem is to output a binary tree when given its order number.

Input

Input consists of multiple problem instances. Each instance consists of a single integer n, where 1 <= n <= 500,000,000. A value of n = 0 terminates input. (Note that this means you will never have to output the empty tree.)

Output

For each problem instance, you should output one line containing the tree corresponding to the order number for that instance. To print out the tree, use the following scheme:

A tree with no children should be output as X.
A tree with left and right subtrees L and R should be output as (L')X(R'), where L' and R' are the representations of L and R.
If L is empty, just output X(R').
If R is empty, just output (L')X.

Sample Input

1
20
31117532
0

Sample Output

X
((X)X(X))X
(X(X(((X(X))X(X))X(X))))X(((X((X)X((X)X)))X)X)

Source

East Central North America 2001

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(tree(0) == "")
	assert(tree(1) == "X")
	assert(tree(2) == "X(X)")
	assert(tree(3) == "(X)X")
	assert(tree(4) == "X(X(X))")
	assert(tree(5) == "X((X)X)")
	assert(tree(6) == "(X)X(X)")
	assert(tree(7) == "(X(X))X")
	assert(tree(8) == "((X)X)X")
	assert(tree(9) == "X(X(X(X)))")
	assert(tree(20) == "((X)X(X))X")
	assert(tree(31117532) == "(X(X(((X(X))X(X))X(X))))X(((X((X)X((X)X)))X)X)")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tree(n int) string {
	w := new(bytes.Buffer)
	s := 0
	i := 1
	for ; s < n; i++ {
		s += catalan(i)
	}
	recurse(w, i-1, n-s+catalan(i-1))
	return w.String()
}

func recurse(w *bytes.Buffer, n, s int) {
	if n < 1 {
		return
	}

	if n == 1 {
		fmt.Fprint(w, "X")
		return
	}

	i, v := 0, 0
	for ; v < s; i++ {
		v += catalan(i) * catalan(n-i-1)
	}

	l := i - 1
	r := n - l - 1
	v -= catalan(i-1) * catalan(n-i)
	s -= v

	if l != 0 {
		fmt.Fprint(w, "(")
		recurse(w, l, (s-1)/catalan(r)+1)
		fmt.Fprint(w, ")")
	}
	fmt.Fprint(w, "X")
	if r != 0 {
		fmt.Fprint(w, "(")
		recurse(w, r, (s-1)%catalan(r)+1)
		fmt.Fprint(w, ")")
	}
}

// https://oeis.org/A000108
func catalan(n int) int {
	if n < 0 {
		return 0
	}
	return binomial(2*n, n) / (n + 1)
}

func binomial(n, k int) int {
	if k < 0 || k > n {
		return 0
	}
	if k == 0 || k == n {
		return 1
	}

	k = min(k, n-k)
	c := 1
	for i := 0; i < k; i++ {
		c = c * (n - i) / (i + 1)
	}
	return c
}
