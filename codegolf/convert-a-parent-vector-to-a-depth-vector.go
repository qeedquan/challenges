/*

Consider the following diagram of a tree structure, with each node numbered by its index in a depth-first pre-order traversal:

0
├─────┬──┬──┐
1     5  6  8
├──┐     │  ├──┬───────┐
2  3     7  9  10      13
   │           ├───┐
   4           11  12
Label each node by its depth—that is, the number of ancestors it has, with the root node having depth zero. (In this diagram, this corresponds with the node's vertical placement.)

0
├─────┬──┬──┐
1     1  1  1
├──┐     │  ├──┬───────┐
2  2     2  2  2       2
   │           ├───┐
   3           3   3
Flattening this tree, again by depth-first pre-order traversal, gives the depth vector:

0 1 2 2 3 1 1 2 1 2 2 3 3 2
In this representation, the depth of the Nth node is at index N.

Now consider the same tree but with each node numbered by its parent's index (with the root node said to be its own parent.)

0
├─────┬──┬──┐
0     0  0  0
├──┐     │  ├──┬───────┐
1  1     6  8  8       8
   │           ├───┐
   3           10  10
Flattening this, similarly, gives the parent vector:

0 0 1 1 3 0 0 6 0 8 8 10 10 8
In this representation, the parent of the Nth node is at index N.

Either of these representations is enough to reconstruct the original tree structure. Often, when writing parsers in array languages, a depth vector is a convenient way to build the tree while parsing, but a parent vector is more useful when operating on the nodes of the tree. Therefore, converting from a depth vector to a parent vector is a somewhat common operation, and a quite simple one: for each node N, its parent is the closest node to the left whose depth is one less than N's. Converting from a parent vector to a depth vector is a less common operation, but I think a more interesting one. It is still fairly simple, but has somewhat more to it than the inverse and I think it has some room for interesting golf tricks.

In this challenge, you are tasked to construct the depth vector given the parent vector.

You may choose to omit the root node in both the input and output. If you do, you may count depth one in the test cases as zero. You may use either zero- or one-based indices for the parent vector. The input will never represent an invalid tree (e.g. nodes which point to themselves or are out of order.)

Test cases:

  0 0
→ 0 1

  0
→ 0

  0 0 1 2 3 4 1 6
→ 0 1 2 3 4 5 2 3

  0 0 1 2 3 3 0 6 6 6 9
→ 0 1 2 3 4 4 1 2 2 2 3

  0 0 1 1 3 0 0 6 0 8 8 10 10 8
→ 0 1 2 2 3 1 1 2 1 2 2  3  3 2

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{0, 1}, []int{0, 1})
	test([]int{0}, []int{0})
	test(
		[]int{0, 0, 1, 2, 3, 4, 1, 6},
		[]int{0, 1, 2, 3, 4, 5, 2, 3},
	)
	test(
		[]int{0, 0, 1, 2, 3, 3, 0, 6, 6, 6, 9},
		[]int{0, 1, 2, 3, 4, 4, 1, 2, 2, 2, 3},
	)
	test(
		[]int{0, 0, 1, 1, 3, 0, 0, 6, 0, 8, 8, 10, 10, 8},
		[]int{0, 1, 2, 2, 3, 1, 1, 2, 1, 2, 2, 3, 3, 2},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, r []int) {
	p := conv(x)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

// Ported from @Mukundan314 solution
func conv(x []int) []int {
	if len(x) == 0 {
		return []int{}
	}

	m := make(map[int]int)
	for i, j := range x[1:] {
		m[i] = j
	}

	r := []int{x[0]}
	for i, j := range x[1:] {
		m[^i] = m[-j] + 1
		r = append(r, m[^i])
	}
	return r
}
