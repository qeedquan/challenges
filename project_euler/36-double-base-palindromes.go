/*

The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(1e6))
}

func solve(n int) int {
	r := 0
	for i := 1; i < n; i++ {
		d := fmt.Sprintf("%d", i)
		b := fmt.Sprintf("%b", i)
		if palindrome(d) && palindrome(b) {
			r += i
		}
	}
	return r
}

func palindrome(s string) bool {
	n := len(s)
	for i := 0; i < n/2; i++ {
		if s[i] != s[n-i-1] {
			return false
		}
	}
	return true
}
