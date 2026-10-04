/*

Description

Given two strings a and b we define a*b to be their concatenation. For example, if a = "abc" and b = "def" then a*b = "abcdef". If we think of concatenation as multiplication, exponentiation by a non-negative integer is defined in the normal way: a^0 = "" (the empty string) and a^(n+1) = a*(a^n).

Input

Each test case is a line of input representing s, a string of printable characters. The length of s will be at least 1 and will not exceed 1 million characters. A line containing a period follows the last test case.

Output

For each s you should print the largest n such that s = a^n for some string a.

Sample Input

abcd
aaaa
ababab
.

Sample Output

1
4
3

Hint

This problem has huge input, use scanf instead of cin to avoid time limit exceed.

Source

Waterloo local 2002.07.01

*/

package main

func main() {
	assert(strlog("abcd") == 1)
	assert(strlog("aaaa") == 4)
	assert(strlog("ababab") == 3)
	assert(strlog("") == 0)
	assert(strlog("abcde") == 1)
	assert(strlog("c") == 1)
	assert(strlog("java") == 1)
	assert(strlog("c++c++c++") == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func strlog(s string) int {
	n := len(s)
	i := 0
	j := -1
	p := make([]int, n+1)
	p[0] = -1
	for i < n {
		if j == -1 || s[i] == s[j] {
			i++
			j++
			p[i] = j
		} else {
			j = p[j]
		}
	}
	if n != p[n] && n%(n-p[n]) == 0 {
		return n / (n - p[n])
	}
	return 1
}
