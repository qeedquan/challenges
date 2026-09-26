/*

Given a list of positive integers determine if there is an element that is either greater than its two neighbors or less than its two neighbors (a "bump"). To be clear a bump can never be the first or last item of the list because they only have one neighbor.

Your program should output one of two consistent values each corresponding to either a list with no bumps or a list with bumps. What the values are is unimportant you may choose them yourself.

This is code-golf so answers will be scored in bytes with fewer bytes being better.
Test cases

[] -> False
[1] -> False
[1,2] -> False
[1,2,1] -> True
[1,2,2] -> False
[1,2,3] -> False
[1,2,2,1] -> False
[1,2,2,3] -> False
[1,2,1,2] -> True
[1,3,2] -> True
[3,1,2] -> True
[2,2,2] -> False

*/

package main

func main() {
	assert(bumpy([]int{}) == false)
	assert(bumpy([]int{1}) == false)
	assert(bumpy([]int{1, 2}) == false)
	assert(bumpy([]int{1, 2, 1}) == true)
	assert(bumpy([]int{1, 2, 2}) == false)
	assert(bumpy([]int{1, 2, 3}) == false)
	assert(bumpy([]int{1, 2, 2, 1}) == false)
	assert(bumpy([]int{1, 2, 2, 3}) == false)
	assert(bumpy([]int{1, 2, 1, 2}) == true)
	assert(bumpy([]int{1, 3, 2}) == true)
	assert(bumpy([]int{3, 1, 2}) == true)
	assert(bumpy([]int{2, 2, 2}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bumpy(a []int) bool {
	for i := 1; i < len(a)-1; i++ {
		switch {
		case a[i] > a[i-1] && a[i] > a[i+1]:
			fallthrough
		case a[i] < a[i-1] && a[i] < a[i+1]:
			return true
		}
	}
	return false
}
