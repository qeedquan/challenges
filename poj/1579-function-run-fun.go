/*

Description

We all love recursion! Don't we?

Consider a three-parameter recursive function w(a, b, c):

if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

This is an easy function to implement. The problem is, if implemented directly, for moderate values of a, b and c (for example, a = 15, b = 15, c = 15), the program takes hours to run because of the massive recursion.
Input

The input for your program will be a series of integer triples, one per line, until the end-of-file flag of -1 -1 -1. Using the above technique, you are to calculate w(a, b, c) efficiently and print the result.
Output

Print the value for w(a,b,c) for each triple.
Sample Input

1 1 1
2 2 2
10 4 6
50 50 50
-1 7 18
-1 -1 -1
Sample Output

w(1, 1, 1) = 2
w(2, 2, 2) = 4
w(10, 4, 6) = 523
w(50, 50, 50) = 1048576
w(-1, 7, 18) = 1

Source

Pacific Northwest 1999

*/

package main

func main() {
	assert(w(1, 1, 1) == 2)
	assert(w(2, 2, 2) == 4)
	assert(w(10, 4, 6) == 523)
	assert(w(50, 50, 50) == 1048576)
	assert(w(-1, 7, 18) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var cache = make(map[[3]int]int)

func w(a, b, c int) int {
	if a <= 0 || b <= 0 || c <= 0 {
		return 1
	}

	if a > 20 || b > 20 || c > 20 {
		a, b, c = 20, 20, 20
	}

	k := [3]int{a, b, c}
	r, f := cache[k]
	if f {
		return r
	}

	if a < b && b < c {
		r = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
	} else {
		r = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
	}
	cache[k] = r

	return r
}
