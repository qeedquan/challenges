/*

In 1988, the International Mathematical Olympiad (IMO) featured this as its final question, Question Six:

Let a and b be positive integers such that  ab+1 divides a^2+b^2.
Show that (a^2+b^2) / (ab+1) is the square of an integer.

https://www.imo-official.org/problems/

This can be proven using a technique called Vieta jumping.
The proof is by contradiction - if a pair did exist with an integer, non-square N=(a^2+b^2)/(ab+1)
then there would always be a pair with a smaller a+b with both a and b positive integers,
but such an infinite descent is not possible using only positive integers.

The "jumping" in this proof is between the two branches of the hyperbola x^2+y^2-Sxy-S=0 defined by S (our square).
These are symmetrical around x=y and the implication is that if (A,B) is a solution where A≥B then (B,SB−A) is either
(sqrt(S),0) or it is another solution (with a smaller  A+B). Similarly if B≥A then the jump is "down" to (SA−B,A).

Challenge
Given a non-negative integer, n, determine whether a pair of positive integers (a,b) with  n=|a−b| exists such that  ab+1 divides  a^2+b^2.

This is code-golf, so try to write the shortest code in bytes that your chosen language allows.

Your output just needs to differentiate between "valid" n and "invalid" n,
some possible ways include the below, feel free to ask if unsure:

Two distinct, consistent values
Truthy vs Falsey using your language's definition (either way around)
A solution if valid vs something consistent and distinguishable if not
Return code (if using this be sure that errors are not due to resource limits being hit - your program would still need to produce the expected error given infinite time/memory/precision/etc)

Valid inputs
Here are the  n<10000 which should be identified as being possible differences |a−b|:

0 6 22 24 60 82 120 210 213 306 336 504 720 956 990 1142 1320 1716 1893 2184 2730 2995 3360 4080 4262 4896 5814 6840 7554 7980 9240
For example 22 is valid because 30×8+1 divides 30^2+8^2 and |30−8|=22

...that is (30,8) and (8,30) are solutions to Question Six.
The first jumps "down" to (8,2) then (2,0) while the second jumps "down" to (2,8) then (0,2).

Note:
One implementation approach would be to ascend (jump the other way) from each of  (x,0)|x∃[1,n] until
the difference is greater than n (move to next x) or equal (found that n is valid).
Maybe there are other, superior methods though?

*/

package main

import (
	"math"
	"slices"
)

func main() {
	tab := []int{
		0, 6, 22, 24, 60, 82, 120, 210, 213, 306, 336, 504,
		720, 956, 990, 1142, 1320, 1716, 1893, 2184,
		2730, 2995, 3360, 4080, 4262, 4896, 5814,
		6840, 7554, 7980, 9240,
	}

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
		if f(i) {
			r = append(r, i)
		}
	}
	return r
}

/*

@xnor

Checks whether

(n^2 - 2) / (a*(a+n) + 1)

is ever an integer for any a with  1≤a≤n+1.
This upper bound suffices because for  a≥n>1,
the denominator is larger than the numerator,
and for n=0 we just need to get a positive on a=1.

*/

func f(n int) bool {
	if n < 0 {
		return false
	}
	for i := 1; i <= n+1; i++ {
		x := n*n - 2
		y := i*(i+n) + 1
		if x%y == 0 {
			return true
		}
	}
	return false
}
