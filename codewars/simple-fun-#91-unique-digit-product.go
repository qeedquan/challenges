/*

Task

Let's call product(x) the product of x's digits. Given an array of integers a, calculate product(x) for each x in a, and return the number of distinct results you get.

Example

For a = [2, 8, 121, 42, 222, 23], the output should be 3.

Here are the products of the array's elements:

2: product(2) = 2; 8: product(8) = 8; 121: product(121) = 1 * 2 * 1 = 2; 42: product(42) = 4 * 2 = 8; 222: product(222) = 2 * 2 * 2 = 8; 23: product(23) = 2 * 3 = 6. As you can see, there are only 3 different products: 2, 6 and 8.

Input/Output

[input] integer array a

Constraints:

1 ≤ a.length ≤ 10000,

1 ≤ a[i] ≤ 1000000000.

[output] an integer

The number of different digit products in a.

*/

package main

func main() {
	assert(udp([]int{2, 8, 121, 42, 222, 23}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func udp(a []int) int {
	m := make(map[int]bool)
	for _, v := range a {
		v = digprod(v)
		m[v] = true
	}
	return len(m)
}

func digprod(n int) int {
	if n < 1 {
		return 0
	}

	r := 1
	for ; n > 0; n /= 10 {
		r *= n % 10
	}
	return r
}
