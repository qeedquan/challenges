/*

Introduction

As a programmer, one must be familiar with the usage of iterative statements in coding implementations! Depending on the chosen programming language, iterative statements can come in the form of for, while, do-while etc.

Below is an example of a nested C-style for-loop:

for(int i = 0; i < A; i++){
  // some statements
  for(int j = 0; j < B; j++){
    // some statements
    for(int k = 0; k < C; k++){
      // some statements
    }
  }
}
Where A, B and C are natural numbers.

Task

Given an array of length N, where N denotes the number of iterative statements. Each item-pair in the array represents two elements, with the 1st value (V) indicating the upper boundary for the iteration to take place (can be inclusive or exclusive depending on the 2nd value) and the 2nd value (Boolean data type -> true / false depending on your chosen language) indicating whether the upper boundary (V) is inclusive or not.

You must write a function that outputs an array in which each element represents the number of times each for-loop condition is evaluated. Below is an example for better understanding:

Example

arr = [[7, true], [5, false]]

for(int i = 0; i <= 7; i++){   // This statement is executed 9 times before termination -> 0, 1, 2, 3, 4, 5, 6, 7, 8 (since 8 > 7 is the breaking condition)
  for(int j = 0; j < 5; j++){  // In one cycle of outermost loop, this statement is executed 6 times before termination -> 0, 1, 2, 3, 4, 5 (since 5 >= 5 is the breaking condition)
    // some statements
  }
}

Note

The array can be empty, with a range of 0 <= N <= 20
The starting counter of the C-style for-loop is always 0
The iteration expression or operation to be performed is always incremental
The range of upper boundary is as follows: 1 <= V <= 20

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][2]int{{4, 1}, {5, 0}, {3, 1}}, []int{6, 30, 125})
	test(
		[][2]int{{16, 0}, {11, 0}, {1, 1}, {3, 0}, {8, 1}, {10, 1}, {9, 0}, {11, 1}, {20, 1}, {3, 0}, {7, 0}},
		[]int{17, 192, 528, 1408, 10560, 114048, 1045440, 12231648, 248396544, 948423168, 5690539008},
	)
	test([][2]int{}, []int{})
	test([][2]int{{20, 0}}, []int{21})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(array [][2]int, expected []int) {
	result := iterations(array)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func iterations(array [][2]int) []int {
	result := []int{}
	multiplier := 1
	for _, value := range array {
		count := value[0] + 1
		if value[1] != 0 {
			count += 1
		}
		result = append(result, multiplier*count)
		multiplier *= count - 1
	}
	return result
}
