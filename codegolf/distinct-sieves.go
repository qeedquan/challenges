/*

Given a list of integers, create a boolean mask such that the true indices can be used to filter the distinct values from the list. Which index is selected as the true one does not matter as long as only one of them is selected for each set of indices corresponding to identical values.

The input will be a non-empty list of non-negative integers in a format suitable for your language and the output will be a list of boolean values following the specification above. You are allowed to use your own definitions of truthy and falsy values in the output list.

In my examples below, I define 1 to be truthy and 0 to be falsy.

[5, 4, 7, 1]  Input
[1, 1, 1, 1]  Output
              Select only the values with with true indicies in the sieve
[5  4  7  1]  Contains zero duplicate values

[5, 9, 7, 5, 6, 0, 5]
[0, 1, 1, 1, 1, 1, 0]
[   9, 7, 5, 6, 0   ]
Test Cases
When there is an or, it means that there are multiple valid outputs. If there is a trailing ellipsis ... after the or, it means that not all of the possible outputs were listed.

[0] = [1]

[55] = [1]

[32, 44] = [1, 1]

[0, 0] = [1, 0] or [0, 1]

[9001, 9001, 9001] = [1, 0 , 0] or [0, 1, 0] or [0, 0, 1]

[5, 4, 7, 1] = [1, 1, 1, 1]

[1, 2, 3, 4, 3, 5] = [1, 1, 1, 1, 0, 1] or
                     [1, 1, 0, 1, 1, 1]

[5, 9, 7, 5, 6, 0, 5] = [1, 1, 1, 0, 1, 1, 0] or
                        [0, 1, 1, 1, 1, 1, 0] or
                        [0, 1, 1, 0, 1, 1, 1]

[0, 8, 6, 6, 3, 8, 7, 2] = [1, 1, 1, 0, 1, 0, 1, 1] or
                           [1, 0, 0, 1, 1, 1, 1, 1] or
                           [1, 0, 1, 0, 1, 1, 1, 1] or
                           [1, 1, 0, 1, 1, 0, 1, 1]

[45, 47, 47, 45, 24, 24, 24, 8, 47, 41, 47, 88]
= [1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1] or ...

[154, 993, 420, 154, 154, 689, 172, 417, 790, 175, 790, 790, 154, 172, 175, 175, 420, 417, 154, 175, 172, 175, 172, 993, 689, 993, 993, 790]
= [1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] or ...
Rules
This is code-golf so the shortest solution wins.
Builtins are allowed!
You are allowed to use your own definitions of truthy and falsy values in the output list. If you choose to do so, please state your definitions.
The input will be a non-empty list of non-negative integers.
You are free to choose between outputting only one of the sieves or multiple or even all of them. As long as each sieve is valid, it will be accepted.

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	test([]int{0}, []int{1})
	test([]int{55}, []int{1})
	test([]int{32, 44}, []int{1, 1})
	test([]int{0, 0}, []int{0, 1})
	test([]int{9001, 9001, 9001}, []int{0, 0, 1})
	test([]int{5, 4, 7, 1}, []int{1, 1, 1, 1})
	test([]int{1, 2, 3, 4, 3, 5}, []int{1, 1, 0, 1, 1, 1})
	test([]int{5, 9, 7, 5, 6, 0, 5}, []int{0, 1, 1, 0, 1, 1, 1})
	test([]int{0, 8, 6, 6, 3, 8, 7, 2}, []int{1, 0, 0, 1, 1, 1, 1, 1})
	test([]int{45, 47, 47, 45, 24, 24, 24, 8, 47, 41, 47, 88}, []int{0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1})
	test([]int{154, 993, 420, 154, 154, 689, 172, 417, 790, 175, 790, 790, 154, 172, 175, 175, 420, 417, 154, 175, 172, 175, 172, 993, 689, 993, 993, 790}, []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(items, expected []int) {
	result := filter(items)
	fmt.Println(result)
	assert(slices.Equal(result, expected))
}

func filter(items []int) []int {
	result := []int{}
	for ; len(items) > 0; items = items[1:] {
		item := items[0]
		if slices.Index(items[1:], item) >= 0 {
			result = append(result, 0)
		} else {
			result = append(result, 1)
		}
	}
	return result
}
