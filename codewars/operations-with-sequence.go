/*

Steps

Square the numbers that are greater than zero.
Multiply by 3 every third number.
Multiply by -1 every fifth number.
Return the sum of the sequence.
Example
{ -2, -1, 0, 1, 2 } returns -6

1. { -2, -1, 0, 1 * 1, 2 * 2 }
2. { -2, -1, 0 * 3, 1, 4 }
3. { -2, -1, 0, 1, -1 * 4 }
4. -6
P.S.: The sequence consists only of integers. And try not to use "for", "while" or "loop" statements.

*/

package main

func main() {
	assert(calc([]int{-2, -1, 0, 1, 2}) == -6)
	assert(calc([]int{0, 2, 1, -6, -3, 3}) == 31)
	assert(calc([]int{0}) == 0)
	assert(calc([]int{1, 1, 1, 1, 1}) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func calc(a []int) int {
	r := 0
	for i := range a {
		v := a[i]
		if v > 0 {
			v *= v
		}
		if i%3 == 2 {
			v *= 3
		}
		if i%5 == 4 {
			v = -v
		}
		r += v
	}
	return r
}
