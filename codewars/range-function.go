/*

Create range generator function that will take up to 3 parameters - start value, step and stop value. This function should return an iterable object with numbers. For simplicity, assume all parameters to be positive numbers.

Examples:

range(5) --> 1,2,3,4,5
range(3, 7) --> 3,4,5,6,7
range(2, 3, 15) --> 2,5,8,11,14

*/

package main

import (
	"fmt"
	"iter"
)

func main() {
	for i := range ranges(1, 1, 5) {
		fmt.Println(i)
	}
	fmt.Println()

	for i := range ranges(3, 1, 7) {
		fmt.Println(i)
	}
	fmt.Println()

	for i := range ranges(2, 3, 15) {
		fmt.Println(i)
	}
	fmt.Println()
}

func ranges(start, step, stop int) iter.Seq[int] {
	return func(yield func(int) bool) {
		if start > stop {
			return
		}

		for {
			if !yield(start) {
				return
			}

			if stop-step < start {
				return
			}

			if start += step; start > stop {
				return
			}
		}
	}
}
