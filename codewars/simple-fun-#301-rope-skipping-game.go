/*

Task
Some children are playing rope skipping game. Children skip the rope at roughly the same speed: once per second. If the child fails during the jump, he needs to tidy up the rope and continue. This will take 3 seconds.

You are given an array sorted in ascending order, where each element is a jump count after which the child failed. This is a running total, meaning that each count includes the jumps before it.

For example [12, 23, 45] means that the child failed 3 times while playing: after the 12th jump, after the 23rd jump, and after the 45th jump.

Your task is to calculate how many times the child jumped in 60 seconds.

Note: The children keep going until they have made at least 60 jumps, even if it takes them longer than 60 seconds.

Input/Output
[input] integer array failedCount

0 ≤ failedCount.length ≤ 60

1 ≤ failedCount[i] ≤ 60

[output] an integer

how many times the child jumped in 60 seconds.

Example
For failedCount = [], the output should be 60.

There is no mistake in the game process. So the child jumped 60 times in 60 seconds.

For failedCount = [12, 23, 45], the output should be 51.

The 1st mistake occurred when he jumped 12 times. --> 12 seconds past.
Tidy up the rope and continue.                    --> 15 seconds past.
The 2nd mistake occurred when he jumped 23 times. --> 26 seconds past.
Tidy up the rope and continue.                    --> 29 seconds past.
The 3rd mistake occurred when he jumped 45 times. --> 51 seconds past.
Tidy up the rope and continue.                    --> 54 seconds past.
When he jumped 51 times                           --> 60 seconds past.

*/

package main

func main() {
	assert(tiaosheng([]int{}) == 60)
	assert(tiaosheng([]int{12, 23, 45}) == 51)
	assert(tiaosheng([]int{17}) == 57)
	assert(tiaosheng([]int{10, 20, 30, 40}) == 48)
	assert(tiaosheng([]int{10, 20, 30, 40, 58}) == 48)
	assert(tiaosheng([]int{10, 20, 30, 40, 47, 60}) == 47)
	assert(tiaosheng([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) == 30)
	assert(tiaosheng([]int{58}) == 58)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tiaosheng(fails []int) int {
	jumps := 60
	time := 0
	for index, value := range fails {
		time = value + 3*index
		switch {
		case time < 57:
			jumps = value - 3*(index+1)
		case time >= 57 && time <= 60:
			return value
		default:
			return 60 - 3*index
		}
	}
	if time < 57 {
		return 60 - 3*len(fails)
	}
	return jumps
}
