/*

Description

One of the famous proofs of modern mathematics is Georg Cantor's demonstration that the set of rational numbers is enumerable. The proof works by using an explicit enumeration of rational numbers as shown in the diagram below.
1/1 1/2 1/3 1/4 1/5 ...

2/1 2/2 2/3 2/4

3/1 3/2 3/3

4/1 4/2

5/1


In the above diagram, the first term is 1/1, the second term is 1/2, the third term is 2/1, the fourth term is 3/1, the fifth term is 2/2, and so on.

Input

The input list contains a single number per line and will be terminated by endof-file.

Output

You are to write a program that will read a list of numbers in the range from 1 to 10^7 and will print for each number the corresponding term in Cantor's enumeration as given below.

Sample Input

3
14
7

Sample Output

TERM 3 IS 2/1
TERM 14 IS 2/4
TERM 7 IS 1/4

Source

Southeastern Europe 2004

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	test(1, 1, 1)
	test(2, 1, 2)
	test(3, 2, 1)
	test(4, 3, 1)
	test(5, 2, 2)
	test(6, 1, 3)
	test(7, 1, 4)
	test(14, 2, 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, rx, ry int) {
	x, y := term(n)
	fmt.Printf("%v %v/%v\n", n, x, y)
	assert(x == rx)
	assert(y == ry)
}

// https://oeis.org/A320040
func term(n int) (int, int) {
	f := func(i int) bool { return triangular(i) >= n }
	d := sort.Search(n, f)
	c := d - 1

	var x, y int
	if d&1 != 0 {
		x = d - (n - (1+c)*c/2) + 1
		y = n - (1+c)*c/2
	} else {
		x = n - (1+c)*c/2
		y = d - (n - (1+c)*c/2) + 1
	}
	return x, y
}

func triangular(n int) int {
	return n * (n + 1) / 2
}
