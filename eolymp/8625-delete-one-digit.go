/*

Three-digit number is given. Delete in it one digit to get the maximum possible number. The order of the digits should not be changed.

Input
One three-digit number.

Output
Print the maximum possible number after deleting one digit.

Examples

Input #1
432

Answer #1
43

Input #2
659

Answer #2
69

*/

package main

func main() {
	assert(solve(432) == 43)
	assert(solve(659) == 69)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	a := n / 10
	b := (n/100)*10 + n%10
	c := n % 100

	r := 9
	if a > 9 {
		r = max(r, a)
	}
	if b > 9 {
		r = max(r, b)
	}
	if c > 9 {
		r = max(r, c)
	}
	return r
}
