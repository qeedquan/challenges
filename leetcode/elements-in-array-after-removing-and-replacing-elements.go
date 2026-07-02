/*

You have a 0-indexed integer array nums that undergoes a cyclic transformation process starting at minute 0:

Phase 1 - Removal Phase: Every minute, the leftmost element is removed from nums until the array becomes empty. This takes n minutes (where n is the length of the original array).

Phase 2 - Restoration Phase: Every minute, one element is appended back to the end of nums in the same order they were removed, until the original array is restored. This also takes n minutes.

This entire cycle of 2n minutes repeats indefinitely.

For example, with nums = [0,1,2]:

Minute 0: [0,1,2] (original)
Minute 1: [1,2] (removed 0)
Minute 2: [2] (removed 1)
Minute 3: [] (removed 2)
Minute 4: [0] (added back 0)
Minute 5: [0,1] (added back 1)
Minute 6: [0,1,2] (added back 2, cycle complete)
Minute 7: [1,2] (cycle repeats...)

You're given a 2D array queries where each queries[j] = [time_j, index_j] asks: "What is the value at position index_j in the array at minute time_j?"

For each query, return:

The value nums[index_j] if index_j is a valid index at minute time_j
-1 if index_j is out of bounds at minute time_j

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		[]int{3, 5, 7},
		[][2]int{{2, 0}, {4, 1}, {5, 2}},
		[]int{7, -1, -1},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(numbers []int, queries [][2]int, expected []int) {
	result := elements(numbers, queries)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func elements(numbers []int, queries [][2]int) []int {
	result := make([]int, len(queries))
	for i := range result {
		result[i] = -1
	}

	for i, query := range queries {
		time := query[0]
		index := query[1]
		time %= 2 * len(numbers)
		if time < len(numbers) && index < len(numbers)-time {
			result[i] = numbers[index+time]
		} else if time > len(numbers) && index < time-len(numbers) {
			result[i] = numbers[index]
		}
	}
	return result
}
