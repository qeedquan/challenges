/*

In this Kata, you will be given an array of numbers in which two numbers occur once and the rest occur only twice. Your task will be to return the sum of the numbers that occur only once.

For example, repeats([4,5,7,5,4,8]) = 15 because only the numbers 7 and 8 occur once, and their sum is 15. Every other number occurs twice.

More examples in the test cases.

Good luck!

*/

package main

func main() {
	assert(repeats([]int{4, 5, 7, 5, 4, 8}) == 15)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func repeats(a []int) int {
	m := make(map[int]int)
	for _, v := range a {
		m[v]++
	}

	r := 0
	for k, v := range m {
		if v == 1 {
			r += k
		}
	}
	return r
}
