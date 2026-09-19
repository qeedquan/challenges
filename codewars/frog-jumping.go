/*

Help the frog to find a way to freedom
You have an array of integers and have a frog at the first position

[Frog, int, int, int, ..., int]

The integer itself may tell you the length and the direction of the jump

For instance:
 2 = jump two indices to the right
-3 = jump three indices to the left
 0 = stay at the same position
Your objective is to find how many jumps are needed to jump out of the array.

Return -1 if Frog can't jump out of the array

Example:
array = [1, 2, 1, 5];
jumps = 3  (1 -> 2 -> 5 -> <jump out>)
All tests for this Kata are randomly generated.

*/

package main

func main() {
	assert(solution([]int{1, 2, 2, -1}) == 4)
	assert(solution([]int{1, 1, 1, 1}) == 4)
	assert(solution([]int{1, 2, 1, 5}) == 3)
	assert(solution([]int{1, 2, 1, 5}) == 3)
	assert(solution([]int{1, -1}) == -1)
	assert(solution([]int{-3}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solution(moves []int) int {
	seen := make(map[int]bool)
	position := 0
	count := 0
	for !seen[position] {
		seen[position] = true
		if position < 0 || position >= len(moves) {
			return count
		}
		count += 1
		position += moves[position]
	}
	return -1
}
