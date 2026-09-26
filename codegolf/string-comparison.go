/*

You are given two strings a and b consisting of characters from a to z in lowercase. Let n be the length of a. Let m be the length of b. Let a be the string a repeated m times.
Let b be the string b repeated n times. Check whether a is lexicographically less than b.

Test cases:

a b ---> true
ac a ---> false
bekcka kwnfoe ---> true
beztbest bestbe ---> false
mcjaf mc ---> true
akboe uenvi ---> true
Shortest code wins.

Hint: there's a 13-byte JavaScript solution. Beat that!

*/

package main

func main() {
	assert(compare("a", "b") == true)
	assert(compare("ac", "a") == false)
	assert(compare("bekcka", "kwnfoe") == true)
	assert(compare("beztbest", "bestbe") == false)
	assert(compare("mcjaf", "mc") == true)
	assert(compare("akboe", "uenvi") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func compare(a, b string) bool {
	return a+b < b+a
}
