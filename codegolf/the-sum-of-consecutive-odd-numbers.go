/*

Although related challenges have been asked, this one is different to warrant its own question.
https://codegolf.stackexchange.com/questions/2958/check-if-number-is-a-sum-of-consecutive-numbers-or-not
https://codegolf.stackexchange.com/questions/66193/sums-of-consecutive-integers

Challenge
Given a positive integer, return the longest sequence of consecutive positive odd integers whose sum is the given integer. If no such sequence exists, you may report an error in whatever way makes sense for your language, including returning a falsy value or throwing an exception.

Test Cases
  1 -> [1]
  2 -> []
  3 -> [3]
  4 -> [1, 3]
  5 -> [5]
  6 -> []
  9 -> [1, 3, 5] (note that [9] is not a valid answer)
 15 -> [3, 5, 7]
104 -> [23, 25, 27, 29] (note that [51, 53] is not a valid answer)

Scoring
This is code-golf, so the shortest answer in each language wins.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	tab := []int{1, 2, 3, 4, 5, 6, 9, 15, 99, 100, 104, 124}
	for _, i := range tab {
		fmt.Println(i, gen(i))
	}
}

/*

@H.PWiz

I check if the number can be expressed as the difference of two squares: m^2-n^2.
I can then construct the list of consecutive odd numbers: [2n+1,2n+3...2m-1].
Note that because the minimum n is chosen, the longest list will be output

*/

func gen(n int) []int {
	r := []int{}
	if n < 1 {
		return r
	}

	x, y := find(n)
	if x < 0 {
		return r
	}

	for i := x + 1; i <= y; i++ {
		r = append(r, 2*i-1)
	}
	return r
}

func find(n int) (int, int) {
	for x := 0; x <= n; x++ {
		z := n + x*x
		y := int(math.Sqrt(float64(z)))
		if y*y == z {
			return x, y
		}
	}
	return -1, -1
}
