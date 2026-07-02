/*

Imagine you have a positive integer number n. Let m be the number obtained by reversing n's digits.
If m is a whole multiple of n, then n is said to be a reverse divisible number. If neither are a palindrome, m is called a palintiple.

For example, 1089⋅9=9801, so 9801 is a palintiple because it is a whole multiple of its reversal, 1089. Another example of a palintiple is 8712, because 2178⋅4=8712.

It's easy to see that all palindrome numbers are reverse divisible, e.g. 171⋅1=171, so we're not interested in those, and we do not call them palintiples.

Input
Your input is an integer x. You may assume x>0.

Output
Your task is to print out the first x palintiple numbers. You can format your output however you like as long as every element is clearly separated.

Test Cases
Input      Output
x = 1      8712
x = 3      8712, 9801, 87912
x = 7      8712, 9801, 87912, 98901, 879912, 989901, 8799912

Rules
This is code-golf, so shortest number of bytes wins.

*/

package main

import (
	"math"
	"slices"
)

func main() {
	tab := []int{8712, 9801, 87912, 98901, 879912, 989901, 8799912, 9899901, 87128712}
	assert(slices.Equal(gen(len(tab)), tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(n int) []int {
	r := []int{}
	for i := 0; len(r) < n && i < math.MaxInt; i++ {
		if palintiples(i) {
			r = append(r, i)
		}
	}
	return r
}

// https://oeis.org/A031877
func palintiples(n int) bool {
	if n < 10 {
		return false
	}

	r := rev(n)
	return n == 4*r || n == 9*r
}

func rev(n int) int {
	r := 0
	for ; n > 0; n /= 10 {
		r = (r * 10) + (n % 10)
	}
	return r
}
