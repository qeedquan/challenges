/*

Task
You are given a sequence of positive ints where every element appears three times, except one that appears only once (let's call it x) and one that appears only twice (let's call it y).

Your task is to find x * x * y.

Example
For arr=[1, 1, 1, 2, 2, 3], the result should be 18

3 x 3 x 2 = 18

For arr=[6, 5, 4, 100, 6, 5, 4, 100, 6, 5, 4, 200], the result should be 4000000

200 x 200 x 100 = 4000000

Input/Output
[input] integer array arr
an array contains positive integers.

[output] an integer

The value of x * x * y

*/

package main

func main() {
	assert(solve([]int{1, 1, 1, 2, 2, 3}) == 18)
	assert(solve([]int{6, 5, 4, 100, 6, 5, 4, 100, 6, 5, 4, 200}) == 4000000)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a []int) int {
	m := make(map[int]int)
	for _, v := range a {
		m[v] += 1
	}

	r, f := 1, 0
	for v, c := range m {
		switch c {
		case 1:
			r *= v * v
		case 2:
			r *= v
		default:
			if c%3 != 0 {
				return -1
			}
			continue
		}
		if f&(1<<v) != 0 {
			return -1
		}
		f |= (1 << v)
	}
	return r
}
