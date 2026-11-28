/*

Introduction (may be ignored)
Putting all positive numbers in its regular order (1, 2, 3, ...) is a bit boring, isn't it? So here is a series of challenges around permutations (reshuffelings) of all positive numbers. This is the fourth challenge in this series (links to the first, second and third challenge).

In this challenge, we will explore not one permutation of the natural numbers, but an entire world of permutations!

In 2000, Clark Kimberling posed a problem in the 26th issue of Crux Mathematicorum, a scientific journal of mathematics published by the Canadian Mathematical Society. The problem was:

Sequence a:
a[1] = 1
a[n] = floor(a[n-1]/2) if floor(a[n-1]/2) not in {0, a[1], ... a[n-1]}
a[n] = 3*a[n-1] otherwise

Does every positive integer occur exactly once in this sequence?

In 2004, Mateusz Kwasnicki provided positive proof in the same journal and in 2008, he published a more formal and (compared to the original question) a more general proof. He formulated the sequence with parameters  p and q:

a[1] = 1
a[n] = floor(a[n-1]/p) if floor(a[n-1]/p) not in {0, a[1], ..., a[n-1]}
a[n] = p*a[n-1] otherwise

He proved that for any p,q>1 such that  log_p(q) is irrational, the sequence is a permutation of the natural numbers.
Since there are an infinite number of p and q values for which this is true,
this is truly an entire world of permutations of the natural numbers. We will stick with the original (p,q)=(3,2),
and for these paramters, the sequence can be found as A050000 in the OEIS. Its first 20 elements are:

1, 3, 9, 4, 2, 6, 18, 54, 27, 13, 39, 19, 57, 28, 14, 7, 21, 10, 5, 15
Since this is a "pure sequence" challenge, the task is to output a(n) for a given  n as input, where a(n) is A050000.

Task
Given an integer input n , output a(n) in integer format, where:

a[1] = 1
a[n] = floor(a[n-1]/2) if floor(a[n-1]/2) not in {0, a1, ..., a[n-1]}
a[n] = 3*a[n-1] otherwise

Note: 1-based indexing is assumed here; you may use 0-based indexing, so a(0)=1;a(1)=3, etc.
Please mention this in your answer if you choose to use this.

Test cases
Input | Output
---------------
1     |  1
5     |  2
20    |  15
50    |  165
78    |  207
123   |  94
1234  |  3537
3000  |  2245
9999  |  4065
29890 |  149853

Rules
Input and output are integers (your program should at least support input and output in the range of 1 up to 32767)
Invalid input (0, floats, strings, negative values, etc.) may lead to unpredicted output, errors or (un)defined behaviour.
Default I/O rules apply.
Default loopholes are forbidden.
This is code-golf, so the shortest answers in bytes wins

*/

package main

func main() {
	assert(f(1) == 1)
	assert(f(5) == 2)
	assert(f(20) == 15)
	assert(f(50) == 165)
	assert(f(78) == 207)
	assert(f(123) == 94)
	assert(f(1234) == 3537)
	assert(f(3000) == 2245)
	assert(f(9999) == 4065)
	assert(f(29890) == 149853)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A050000
func f(n int) int {
	if n < 1 {
		return 0
	}

	m := map[int]int{0: 2}
	p := 2
	for range n {
		q := p >> 1
		if m[q] != 0 {
			p *= 3
		} else {
			p = q
		}
		m[p] = p
	}
	return p
}
