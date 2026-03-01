/*

You have an array of numbers 1 through n (where 1 <= n <= 10). The array needs to be formatted correctly for the person reading the countdown of a spaceship launch.

Unfortunately, the person reading the countdown only knows how to read strings. After the array is sorted correctly make sure it's in a format he can understand.

Between each number should be a space and after the final number (n) should be the word 'liftoff!'

Example:

// Given
instructions = [8,1,10,2,7,9,6,3,4,5]
// Should return
"10 9 8 7 6 5 4 3 2 1 liftoff!"

// Given
instructions = [1,2,4,3,5]
// Should return
"5 4 3 2 1 liftoff!"

*/

package main

import (
	"bytes"
	"fmt"
	"sort"
)

func main() {
	assert(liftoff([]int{8, 1, 10, 2, 7, 9, 6, 3, 4, 5}) == "10 9 8 7 6 5 4 3 2 1 liftoff!")
	assert(liftoff([]int{1, 2, 4, 3, 5}) == "5 4 3 2 1 liftoff!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func liftoff(a []int) string {
	sort.Ints(a)
	w := new(bytes.Buffer)
	for i := len(a) - 1; i >= 0; i-- {
		fmt.Fprintf(w, "%d ", a[i])
	}
	fmt.Fprint(w, "liftoff!")
	return w.String()
}
