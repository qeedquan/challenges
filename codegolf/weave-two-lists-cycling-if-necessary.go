/*

Consider two lists, A and B. To weave them together, we take the first element of A, then the first element of B, then the next element of A, the next element of B, and so on, ending with the last element of A.

A = [1,2,3,4,5]
B = [6,7,8,9]
A weave B = [1,6,2,7,3,8,4,9,5]
This process works as described if A is exactly one element longer than B. If B is too short, we pad it to the required length by repeating its values cyclically:

A = [1,2,3,4,5]
B = [7,8]
A weave B = [1,7,2,8,3,7,4,8,5]
Similarly, if A is too short, we repeat its values cyclically:

A = [1,2]
B = [6,7,8,9]
A weave B = [1,6,2,7,1,8,2,9,1]
Note: the output must always begin and end with an element of A. If A and B are the same length, A is too short and must be cycled:

A = [1,2,3]
B = [7,8,9]
A weave B = [1,7,2,8,3,9,1]
I'm using the term "weave" for this operation instead of the more common "interleave," because the cycling and the requirement to end with the first list make it different from normal interleaving. This challenge was inspired by Emulate Jelly's tie-scan, which conceptually amounts to weaving a list of integers with a list of functions.

Challenge
Given two nonempty lists of positive integers, weave them together and output/return the result.

You may take the second list first if you prefer. If you do, please say so in your solution.

This is code-golf; the goal is to minimize the size of your code, measured in bytes.

Test cases
[1] [2] -> [1,2,1]
[1,1] [2] -> [1,2,1]
[1,2,3] [6] -> [1,6,2,6,3]
[6] [1,2,3] -> [6,1,6,2,6,3,6]
[10,10] [42,42] -> [10,42,10,42,10]
[5,5] [5,5,5] -> [5,5,5,5,5,5,5]
[1,2,3,4,5] [6,7,8,9] -> [1,6,2,7,3,8,4,9,5]
[1,2,3,4,5] [7,8] -> [1,7,2,8,3,7,4,8,5]
[1,2] [6,7,8,9] -> [1,6,2,7,1,8,2,9,1]
[1,2,3] [7,8,9] -> [1,7,2,8,3,9,1]

Here's a reference implementation in Python.

from itertools import cycle

def weave(a, b):
  if len(b) < len(a):
   z = zip(a, cycle(b))
  else:
   z = zip(cycle(a), b + [0])
  return list(sum(z, ())[:-1])

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1}, []int{2}, []int{1, 2, 1})
	test([]int{1, 1}, []int{2}, []int{1, 2, 1})
	test([]int{1, 2, 3}, []int{6}, []int{1, 6, 2, 6, 3})
	test([]int{6}, []int{1, 2, 3}, []int{6, 1, 6, 2, 6, 3, 6})
	test([]int{10, 10}, []int{42, 42}, []int{10, 42, 10, 42, 10})
	test([]int{5, 5}, []int{5, 5, 5}, []int{5, 5, 5, 5, 5, 5, 5})
	test([]int{1, 2, 3, 4, 5}, []int{6, 7, 8, 9}, []int{1, 6, 2, 7, 3, 8, 4, 9, 5})
	test([]int{1, 2, 3, 4, 5}, []int{7, 8}, []int{1, 7, 2, 8, 3, 7, 4, 8, 5})
	test([]int{1, 2}, []int{6, 7, 8, 9}, []int{1, 6, 2, 7, 1, 8, 2, 9, 1})
	test([]int{1, 2, 3}, []int{7, 8, 9}, []int{1, 7, 2, 8, 3, 9, 1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, r []int) {
	p := weave(a, b)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func weave(a, b []int) []int {
	if len(a) == 0 {
		return b
	}

	if len(b) == 0 {
		return a
	}

	r := []int{}
	n := 2*max(len(a), len(b)) + truths(len(a) <= len(b))
	for i, j, m := 0, 0, 0; m < n; m++ {
		switch m & 1 {
		case 0:
			r = append(r, a[i])
			i = (i + 1) % len(a)
		case 1:
			r = append(r, b[j])
			j = (j + 1) % len(b)
		}
	}

	return r
}

func truths(x bool) int {
	if x {
		return 1
	}
	return -1
}
