/*

Background
A Young diagram is a diagram that represents a nonincreasing sequence of positive integers using left-justified rows of squares. As an example, 5, 4, 1 is drawn as

OOOOO
OOOO
O
A Young diagram is said to be symmetric if it is identical to its transpose (reflection along the NW-SE diagonal). The above diagram of 5, 4, 1 is not symmetric, since its transpose represents 3, 2, 2, 2, 1 instead:

5 OOOOO    3 OOO
4 OOOO     2 OO
1 O     => 2 OO
           2 OO
           1 O
A symmetric example is that of 4, 2, 1, 1:

OOOO
OO
O
O

Challenge
Given a nonincreasing sequence of positive integers, add as few numbers as possible to the front of it so that its Young diagram becomes symmetric. If the input is already symmetric, your code is expected to output it as-is. You may take input and give output in reverse order (numbers in increasing order; e.g. [1, 1, 2, 2] -> [1, 1, 2, 2, 4, 6]).

Standard code-golf rules apply. The shortest code in bytes wins.

Test cases
[1] -> [1]
[2] -> [2, 2]
[3] -> [3, 3, 3]
[1, 1] -> [3, 1, 1]
[2, 1] -> [2, 1]
[3, 1] -> [4, 3, 3, 1]
[2, 2, 1] -> [5, 4, 2, 2, 1]
[3, 2, 1] -> [3, 2, 1]
[4, 2, 2] -> [4, 4, 2, 2]
[4, 2, 1] -> [6, 5, 4, 4, 2, 1]
[4, 4, 3] -> [4, 4, 4, 3]
[5, 4, 1] -> [6, 5, 5, 5, 4, 1]
[4, 2, 1, 1] -> [4, 2, 1, 1]
[2, 2, 1, 1] -> [6, 4, 2, 2, 1, 1]

*/

package main

import (
	"fmt"
	"reflect"
	"slices"
	"sort"
)

func main() {
	test([]int{1}, []int{1})
	test([]int{2}, []int{2, 2})
	test([]int{3}, []int{3, 3, 3})
	test([]int{1, 1}, []int{3, 1, 1})
	test([]int{2, 1}, []int{2, 1})
	test([]int{3, 1}, []int{4, 3, 3, 1})
	test([]int{2, 2, 1}, []int{5, 4, 2, 2, 1})
	test([]int{3, 2, 1}, []int{3, 2, 1})
	test([]int{4, 2, 2}, []int{4, 4, 2, 2})
	test([]int{4, 2, 1}, []int{6, 5, 4, 4, 2, 1})
	test([]int{4, 4, 3}, []int{4, 4, 4, 3})
	test([]int{5, 4, 1}, []int{6, 5, 5, 5, 4, 1})
	test([]int{4, 2, 1, 1}, []int{4, 2, 1, 1})
	test([]int{2, 2, 1, 1}, []int{6, 4, 2, 2, 1, 1})
	test([]int{1, 1, 2, 2}, []int{1, 1, 2, 2, 4, 6})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, r []int) {
	p := youngdiagram(x)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, reversesort(r)))
}

// ported from @gsitcia solution
func youngdiagram(x []int) []int {
	reversesort(x)
	if len(x) == 0 || x[0] < 1 {
		return []int{}
	}

	z := make([]int, x[0])
	for i := range x {
		for j := 0; j < x[i]; j++ {
			z[j]++
		}
	}

	k := make([]int, len(z))
	for n := 0; n <= len(z); n++ {
		for i := range z {
			k[i] = z[i] + n
		}

		ki := min(n, len(k))
		xi := min(len(x), len(z)-n)
		if slices.Equal(k[ki:], x[:xi]) {
			return append(k[:ki], x...)
		}
	}
	return []int{}
}

func reversesort(x []int) []int {
	sort.Slice(x, func(i, j int) bool {
		return x[i] > x[j]
	})
	return x
}
