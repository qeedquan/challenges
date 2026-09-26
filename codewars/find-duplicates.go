/*

Given an array, find the duplicates in that array, and return a new array of those duplicates. The elements of the returned array should appear in the order when they first appeared as duplicates.

Note: numbers and their corresponding string representations should not be treated as duplicates (i.e., "1" != 1).

Examples
[1, 2, 4, 4, 3, 3, 1, 5, 3, "5"]  ==>  [4, 3, 1]
[0, 1, 2, 3, 4, 5]                ==>  []

*/

package main

import "fmt"

func main() {
	fmt.Println(duplicates([]any{1, 2, 4, 4, 3, 3, 1, 5, 3, "5"}))
	fmt.Println(duplicates([]any{0, 1, 2, 3, 4, 5}))
}

func duplicates(array []any) []any {
	result := []any{}
	seen := make(map[any]int)
	for _, value := range array {
		if seen[value] == 1 {
			result = append(result, value)
		}
		seen[value] += 1
	}
	return result
}
