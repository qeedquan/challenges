/*

Let's define the recursive function F(n):

F(n) = n % 10   n % 10 > 0
       0        n = 0
	   F(n/10)  otherwise

Let's define the function S(p,q) as follows:

S(p, q)= Sum[i=p, q] F(i)
Given values p and q, calculate S(p, q).

Input
The input consists of several test cases. Each line contains two non-negative integers p and q (p≤q). p and q are 32-bit signed integers.
The last line contains two negative integers and should not be processed.

Output
For each pair p and q, output the value of S(p,q) on a single line.

Examples

Input #1
1 10
10 20
30 40
-1 -1

Answer #1
46
48
52

*/

package main

func main() {
	assert(solve(1, 10) == 46)
	assert(solve(10, 20) == 48)
	assert(solve(30, 40) == 52)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b int) int {
	return seq(b) - seq(a-1)
}

func seq(n int) int {
	if n <= 0 {
		return 0
	}

	r := 0
	for ; n != 0; n /= 10 {
		r += 45 * (n / 10)
		for i := ((n / 10) * 10) + 1; i <= n; i++ {
			r += i % 10
		}
	}
	return r
}
