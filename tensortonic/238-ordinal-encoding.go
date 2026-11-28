/*

Ordinal encoding maps ordered categories to integer positions. The ordering list defines the rank explicitly, with its first category mapped to 0, its second category mapped to 1, and so on.

Every input value appears in ordering. Return one integer for each value, preserving the original sequence.

Examples
Input: values = ["low", "medium", "high", "medium"], ordering = ["low", "medium", "high"]

Output: [0, 1, 2, 1]

Explanation: The categories occupy positions 0, 1, and 2 in the supplied ordering.

Input: values = ["S", "M", "L", "XL", "S"], ordering = ["S", "M", "L", "XL"]

Output: [0, 1, 2, 3, 0]

Hint 1
Create a dictionary from each ordered category to its index.

Hint 2
Look up each input value in that dictionary.

Requirements
Map each value to its zero-based position in ordering.
Preserve the input value order.
Return a list of integers.
Constraints
ordering contains unique values.
Every input value appears in ordering.
Time limit: 300 ms.

*/

package main

import "fmt"

func main() {
	fmt.Println(encode(
		[]string{"low", "medium", "high", "medium"},
		[]string{"low", "medium", "high"},
	))

	fmt.Println(encode(
		[]string{"S", "M", "L", "XL", "S"},
		[]string{"S", "M", "L", "XL"},
	))
}

func encode(values, ordering []string) []int {
	ids := make(map[string]int)
	for index, value := range ordering {
		ids[value] = index
	}

	result := []int{}
	for _, value := range values {
		result = append(result, ids[value])
	}
	return result
}
