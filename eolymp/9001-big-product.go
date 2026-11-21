/*

The jury decided to give you a difficult task. Given numbers a and b, find the following product of numbers a*(a+1)*...*b.

Thinking further that the task would be too boring, instead of the value of the product, the jury decided to ask you for the sign of the product.
So, you need to find whether this product is positive, negative or zero.

Input
Two integers a and b (-10^9≤a≤b≤10^9).

Output
Print the sign of the product a*(a+1)*...*b - one of the next numbers -1, 0, 1 correspondingly.

Examples

Input #1
3 5

Answer #1
1

Input #2
-6 5

Answer #2
0

Input #3
4 9

Answer #3
1

Input #4
-7 -1

Answer #4
-1

*/

package main

func main() {
	assert(solve(3, 5) == 1)
	assert(solve(-6, 5) == 0)
	assert(solve(4, 9) == 1)
	assert(solve(-7, -1) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b int) int {
	if a == 0 || b == 0 || a < 0 && b > 0 {
		return 0
	}
	if a > 0 {
		return 1
	}
	if b < 0 {
		if d := b - a - 1; d%2 == 0 {
			return 1
		}
		return -1
	}
	return 0
}
