/*

Definitions
Let m and n be positive integers. We say that m is a divisor twist of n if there exists integers 1 < a ≤ b such that n = a*b and m = (a - 1)*(b + 1) + 1.
If m can be obtained from n by applying zero or more divisor twists to it, then m is a descendant of n. Note that every number is its own descendant.

For example, consider n = 16. We can choose a = 2 and b = 8, since 2*8 = 16. Then

(a - 1)*(b + 1) + 1 = 1*9 + 1 = 10
which shows that 10 is a divisor twist of 16. With a = 2 and b = 5, we then see that 7 is a divisor twist of 10. Thus 7 is a descendant of 16.

The task
Given a positive integer n, compute the descendants of n, listed in increasing order, without duplicates.

Rules
You are not allowed to use built-in operations that compute the divisors of a number.

Both full programs and functions are accepted, and returning a collection datatype (like a set of some kind) is allowed, as long as it is sorted and duplicate-free.
The lowest byte count wins, and standard loopholes are disallowed.

Test Cases
1 ->  [1]
2 ->  [2] (any prime number returns just itself)
4 ->  [4]
16 -> [7, 10, 16]
28 -> [7, 10, 16, 25, 28]
51 -> [37, 51]
60 -> [7, 10, 11, 13, 15, 16, 17, 18, 23, 25, 28, 29, 30, 32, 43, 46, 49, 53, 55, 56, 60]

*/

package main

import (
	"fmt"
	"slices"
	"sort"
)

func main() {
	test(1, []int{1})
	test(2, []int{2})
	test(4, []int{4})
	test(16, []int{7, 10, 16})
	test(28, []int{7, 10, 16, 25, 28})
	test(51, []int{37, 51})
	test(60, []int{7, 10, 11, 13, 15, 16, 17, 18, 23, 25, 28, 29, 30, 32, 43, 46, 49, 53, 55, 56, 60})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r []int) {
	p := twist(n)
	fmt.Println(p)
	assert(slices.Equal(p, r))
}

func twist(n int) []int {
	m := make(map[int]bool)
	recurse(n, m)

	r := []int{}
	for k, _ := range m {
		r = append(r, k)
	}
	sort.Ints(r)

	return r
}

func recurse(n int, m map[int]bool) {
	m[n] = true
	for i := 2; i*i < n; i++ {
		if n%i == 0 {
			recurse(n+i-n/i, m)
		}
	}
}
