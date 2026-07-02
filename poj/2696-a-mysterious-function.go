/*

Description

For any integers p and q with q > 0, define p mod q to be the integer r with 0 <= r <= q −1 such that p−r is divisible by q. For example, we have
109 mod 10 = 9
−7 mod 3 = 2
−56 mod 7 = 0

Let Φ be a function defined recursively as follows.

http://poj.org/images/2696_1.jpg

where a, b, c, d, e, f, g, h are integers with 0 < a, b, c, d, e, f, g, h <= 1000. One can easily see that 0 <= Φ(i) <= 1000 holds for any integer i >= 0. Now for any given integers a, b, c, d, e, f, g, h, i with 0 < a, b, c, d, e, f, g, h, i <= 1000, you are asked to write a program to output

Φ(i). (Hint: a direct recursive implementation of the above recurrence

relation is likely to run forever for large i.)
Input

The first line contains the number n of test cases. Each of the following n lines contains the sequence a, b, c, d, e, f, g, h, i of integers.
Output

For each test case, your program has to output the correct value of Φ(i).
Sample Input

3
1 2 3 4 5 6 7 8 9
11 12 13 14 15 16 17 18 19
321 322 323 324 325 326 327 328 329
Sample Output

4
0
90
Source

Taiwan 2004

*/

package main

func main() {
	assert(phi(1, 2, 3, 4, 5, 6, 7, 8, 9) == 4)
	assert(phi(11, 12, 13, 14, 15, 16, 17, 18, 19) == 0)
	assert(phi(321, 322, 323, 324, 325, 326, 327, 328, 329) == 90)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func phi(a, b, c, d, e, f, g, h, i int) int {
	return recurse(make(map[int]int), a, b, c, d, e, f, g, h, i)
}

func recurse(m map[int]int, a, b, c, d, e, f, g, h, i int) int {
	if i < 0 {
		return 0
	}
	if i == 0 {
		return a
	}
	if i == 1 {
		return b
	}
	if i == 2 {
		return c
	}

	v, exists := m[i]
	if exists {
		return v
	}

	x := recurse(m, a, b, c, d, e, f, g, h, i-1)
	y := recurse(m, a, b, c, d, e, f, g, h, i-2)
	z := recurse(m, a, b, c, d, e, f, g, h, i-3)
	if i&1 != 0 {
		v = mod(d*x+e*y-f*z, g)
	} else {
		v = mod(f*x-d*y+e*z, h)
	}
	m[i] = v

	return v
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}
