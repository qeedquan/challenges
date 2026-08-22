/*

We've all been told at some point in our lives that dividing by 0 is impossible. And for the most part, that statement is true.
But what if there was a way to perform the forbidden operation? Welcome to my newest creation: b-numbers.

b-numbers are a little bit like imaginary numbers: the main pronumeral involved represents an expression that isn't mathematically impossible (i represents sqrt(-1)).
In this case b will be said to represent the expression 10. From here, it is easy to determine what x0 would equal:

x*0 = x/1 * 1/0 = x*b

The Task
Given an expression involving a division by 0, output the simplified value in terms of b.
Note that input will be in the form of n/0 where n is any rational number or any b-number in decimal form. Leading 0s and trailing 0s wont be included.

Example Input
4/0
1/0
0/0
80/0
-8/0
1.5/0
2.03/0
-1/0
-3.14/0
b/0
3b/0
-b/0
121/0
Example Output
4b
b
0
80b
-8b
1.5b
2.03b
-b
-3.14b
b
3b
-b
121b

Score
This is code golf, so fewest bytes wins. Standard loopholes are forbidden.

*/

package main

import (
	"regexp"
)

func main() {
	assert(div0("4/0") == "4b")
	assert(div0("1/0") == "b")
	assert(div0("0/0") == "0")
	assert(div0("80/0") == "80b")
	assert(div0("-8/0") == "-8b")
	assert(div0("1.5/0") == "1.5b")
	assert(div0("2.03/0") == "2.03b")
	assert(div0("-1/0") == "-b")
	assert(div0("-3.14/0") == "-3.14b")
	assert(div0("b/0") == "b")
	assert(div0("3b/0") == "3b")
	assert(div0("-b/0") == "-b")
	assert(div0("121/0") == "121b")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func div0(s string) string {
	re0 := regexp.MustCompile(`(^1)?b?/0`)
	re1 := regexp.MustCompile(`^0b$`)
	re2 := regexp.MustCompile(`^-1b`)
	s = re0.ReplaceAllString(s, "b")
	s = re1.ReplaceAllString(s, "0")
	s = re2.ReplaceAllString(s, "-b")
	return s
}
