/*

I have a simple challenge for you this time. Given an array of positive integers A (or the equivalent in your language), replace each entry Ai with the sum of the next Ai elements of A, cycling back from the beginning if there are not enough items.

As usual, you can compete in any programming language and can take input and provide output through any standard method and in any reasonable format, while taking note that these loopholes are forbidden by default. You may optionally take the size of A as input too. This is code-golf, so the shortest submission (in bytes) for every language wins.

Examples / Test Cases
Given [1,3,4,5], your code should output [3,10,13,14], because 1 is replaced by 3, 3 is replaced by 4+5+1=10 (notice how it wrapped back from the start), 4 by 5+1+3+4=13 and 5 by 1+3+4+5+1=14.

Given [3,2,1,9], your program should produce [12,10,9,33], because we substitute 3 with 2+1+9=12, 2 with 1+9=10, 1 with 9 and 9 with 3+2+1+9+3+2+1+9+3=33 (notice how we wrapped back from the start more than once).

Some more test cases for you to choose from:

[4,3,2,1]                       -> [10,7,5,4]
[3,2,1,9]                       -> [12,10,9,33]
[1,3,4,5]                       -> [3,10,13,14]
[4,4,3,2,2]                     -> [11,11,8,6,8]
[3,5,3,2,1]                     -> [10,14,6,4,3]
[3,2,4,3,2,1,1]                 -> [9,7,7,4,2,1,3]
[7,8,6,5,4,3,2,1,5]             -> [29,33,20,15,11,8,6,5,30]
[28,2,4,2,3,2,3,4,5,3]          -> [137,6,10,5,9,7,12,38,39,34]
[1,2,3,4,5,4,3,2,1,2,3,4,3,2,1] -> [2,7,13,14,12,8,5,3,2,7,9,7,4,2,1]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{4, 3, 2, 1}, []int{10, 7, 5, 4})
	test([]int{3, 2, 1, 9}, []int{12, 10, 9, 33})
	test([]int{1, 3, 4, 5}, []int{3, 10, 13, 14})
	test([]int{4, 4, 3, 2, 2}, []int{11, 11, 8, 6, 8})
	test([]int{3, 5, 3, 2, 1}, []int{10, 14, 6, 4, 3})
	test([]int{3, 2, 4, 3, 2, 1, 1}, []int{9, 7, 7, 4, 2, 1, 3})
	test([]int{7, 8, 6, 5, 4, 3, 2, 1, 5}, []int{29, 33, 20, 15, 11, 8, 6, 5, 30})
	test([]int{28, 2, 4, 2, 3, 2, 3, 4, 5, 3}, []int{137, 6, 10, 5, 9, 7, 12, 38, 39, 34})
	test([]int{1, 2, 3, 4, 5, 4, 3, 2, 1, 2, 3, 4, 3, 2, 1}, []int{2, 7, 13, 14, 12, 8, 5, 3, 2, 7, 9, 7, 4, 2, 1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(values, expected []int) {
	result := successor(values)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func successor(values []int) []int {
	result := make([]int, len(values))
	for index, value := range values {
		repeats := value + 1
		if repeats <= 0 {
			continue
		}

		start := index + 1
		end := min(start+value, repeats*len(values))
		for position := start; position < end; position++ {
			result[index] += values[position%len(values)]
		}
	}
	return result
}
