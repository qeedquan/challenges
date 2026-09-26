/*

Given an integer n > 9, for each possible insertion between digits in that integer, insert an addition + and evaluate. Then, take the original number modulo those results. Output the sum total of these operations.

An example with n = 47852:

47852 % (4785+2) = 4769
47852 % (478+52) =  152
47852 % (47+852) =  205
47852 % (4+7852) =  716
                  -----
                   5842
Input
A single positive integer in any convenient format, n > 9.

Output
The single integer output following the above construction technique.

Rules
You don't need to worry about input larger than your language's default type.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

Examples
47852 -> 5842
13 -> 1
111 -> 6
12345 -> 2097
54321 -> 8331
3729105472 -> 505598476

*/

package main

func main() {
	assert(f(47852) == 5842)
	assert(f(13) == 1)
	assert(f(111) == 6)
	assert(f(12345) == 2097)
	assert(f(54321) == 8331)
	assert(f(3729105472) == 505598476)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func f(n int64) int64 {
	r := int64(0)
	p := int64(10)
	for i := n; i >= 10; i /= 10 {
		if m := n/p + n%p; m != 0 {
			r += n % m
		}
		p *= 10
	}
	return r
}
