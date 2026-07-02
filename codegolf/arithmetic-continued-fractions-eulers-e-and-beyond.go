/*

Given a, d, and n, compute the n-th convergent of an arithmetic continued fraction and transform it.

Continued fraction structure
The n-th convergent of an arithmetic continued fraction with parameters a, d:

[0;a,a+d,a+2d,…,a+(n-1)d]

For example, with a=6, d=4, n=3:

[0;6,10,14] = 1/(6 + 1/(10 + 1/14)) = 141/860

The transform
From the n-th convergent p/q, compute:

result = (3q + p) / (q + p)

For a=6, d=4, this converges to Euler's number e.

Input
Three integers a, d, n where a ≥ 1, d ≥ 0, n ≥ 1. Input may be taken in any convenient format (three arguments, list, etc.).

Output
Numerator and denominator as two integers (in that order). Format: tuple, list, two lines, space-separated, or native fraction type. Reduced form not required.

Test cases (a=6, d=4 → e)
n	numerator	denominator	correct digits of e
1	19	7	2
2	193	71	4
3	2721	1001	6
5	1084483	398959	12
6	28245729	10391023	15
Test cases (other a, d)
a	d	n	numerator	denominator
2	0	5	239	99
1	2	4	284	133
Scoring
code-golf — shortest code in bytes wins.

Background
Euler (1737) discovered that (e−1)/2 = [0; 1, 6, 10, 14, ...]. Our form [0; 6, 10, 14, ...] drops the leading 1, giving a pure arithmetic progression that yields e directly via the transform.

References
OEIS A016825 — the sequence 2, 6, 10, 14, ... (CF for coth(1/2) = [2; 6, 10, 14, ...])
OEIS A002119 — p + q = (-1)^(n+1) * y(n+1, -2), Bessel polynomial
Wikipedia: List of representations of e
MathWorld: e Continued Fraction

*/

package main

func main() {
	assert(f(6, 4, 1) == [2]int{19, 7})
	assert(f(6, 4, 2) == [2]int{193, 71})
	assert(f(6, 4, 3) == [2]int{2721, 1001})
	assert(f(6, 4, 5) == [2]int{1084483, 398959})
	assert(f(6, 4, 6) == [2]int{28245729, 10391023})

	assert(f(2, 0, 5) == [2]int{239, 99})
	assert(f(1, 2, 4) == [2]int{284, 133})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Arnauld

Method
Starting with p=0 and q=1, we repeatedly apply:

p'/q' = 1 / (a + nd + p/q) = q / ((a + nd)*q + p)

with n decremented at each iteration

*/

func f(a, d, n int) [2]int {
	p, q := 0, 1
	for n--; n >= 0; n-- {
		p, q = q, q*(a+n*d)+p
	}
	x := 3*q + p
	y := q + p
	z := gcd(x, y)
	return [2]int{x / z, y / z}
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
