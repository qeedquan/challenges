/*

Pythagoras had his leg blown up in the war. It had to be amputated, and though he nearly died, he pulled through and made a full recovery. Now, after a year of walking with crutches, he gets the privilege of getting a prosthetic leg! Thing is, though, there are several that fit, but which ones?

The Task
Given a positive integer as input that is the length of one leg of a Pythagorean triple, output all possibilities for the other leg. For example, the smallest Pythagorean triple is (3,4,5), which forms a triangle with two legs of length 3 and 4, and a hypotenuse of length 5.

Examples
Leg:5
12

Leg:28
21
45
96
195

Leg:101
5100

Leg:1001
168
468
660
2880
3432
4080
5460
6468
10200
38532
45540
71568
501000
The Rules
Input will be a single positive integer n.
Output may be in any order, with any delimiter, in any base (though this base must be consistent), and with optional opening and closing braces, and optional trailing whitespace. That is, 1 2 3, [1,2,3], and 1,11,111 all fit this output specification.
You may assume that n will never be larger than one fourth of the fourth root of your language's limit (without using libraries). In practice, you may assume the input will be less than either this or 10,000, whichever is less.
Pythagoras is waiting on you, so better write your code quick and short!

*/

package main

import (
	"fmt"
	"math"
	"reflect"
)

func main() {
	test(5, []int{12})
	test(28, []int{21, 45, 96, 195})
	test(101, []int{5100})
	test(1001, []int{168, 468, 660, 2880, 3432, 4080, 5460, 6468, 10200, 38532, 45540, 71568, 501000})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a int, r []int) {
	p := pol(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

/*

@Dennis

Idea
If (a, b, c) is a Pythagorean triple, there are strictly positive integers k, m, n such that the set equality {a, b} = {km^2 - kn^2, 2kmn} holds.

In particular, this means that a < b^2 and b < a^2, so for input a we can simply check if a^2 + b^2 is a perfect square for each b in {1, … a^2}.

*/
func pol(a int) []int {
	r := []int{}
	for b := 1; b <= a*a; b++ {
		c := a*a + b*b
		s := int(math.Sqrt(float64(c)))
		if c == s*s {
			r = append(r, b)
		}
	}
	return r
}
