/*

A recursive function is given as follows:

f(0, 0) = 1
f(n, r) = Sum[i=0, k-1] f(n-1, r-i) when [(n > 0) and (0 <= r < n(k - 1) + 1)]
f(n, r) = 0 otherwise

x = [Sum[i=0, n*(k-1)] f(n, i)] mod m

Calculate the value , where m=10^t.

Input
Each line contains three integers: k (0<k<10^19), n (0<n<10^19), and t (0<t<10). The last line contains three zeros and must not be processed.

Output
For each test case, output the test case number and the value of x on a separate line. The output format is shown in the sample.

Examples

Input #1
1234 1234 4
2323 99999999999 8
4 99999 9
888 888 8
0 0 0

Answer #1
Case #1: 736
Case #2: 39087387
Case #3: 494777344
Case #4: 91255296

*/

package main

func main() {
	assert(solve(1234, 1234, 4) == 736)
	assert(solve(2323, 99999999999, 8) == 39087387)
	assert(solve(4, 99999, 9) == 494777344)
	assert(solve(888, 888, 8) == 91255296)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b, t int64) int64 {
	m := ipow(10, t)
	return modexp(a, b, m)
}

func modexp(a, b, m int64) int64 {
	if m == 0 {
		return 0
	}

	x := a % m
	y := b / 2
	if b == 1 {
		return x
	}
	if b%2 == 0 {
		return modexp((x*x)%m, y, m) % m
	}
	return (x * modexp((x*x)%m, y, m)) % m
}

func ipow(x, p int64) int64 {
	r := int64(1)
	for range p {
		r *= x
	}
	return r
}
