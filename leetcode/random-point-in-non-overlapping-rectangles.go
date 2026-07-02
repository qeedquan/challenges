/*

You are given an array of non-overlapping axis-aligned rectangles rects where rects[i] = [ai, bi, xi, yi] indicates that (ai, bi)
is the bottom-left corner point of the ith rectangle and (xi, yi) is the top-right corner point of the ith rectangle.
Design an algorithm to pick a random integer point inside the space covered by one of the given rectangles.
A point on the perimeter of a rectangle is included in the space covered by the rectangle.

Any integer point inside the space covered by one of the given rectangles should be equally likely to be returned.

Note that an integer point is a point that has integer coordinates.

Implement the Solution class:

Solution(int[][] rects) Initializes the object with the given rectangles rects.
int[] pick() Returns a random integer point [u, v] inside the space covered by one of the given rectangles.


Example 1:
https://assets.leetcode.com/uploads/2021/07/24/lc-pickrandomrec.jpg
Input
["Solution", "pick", "pick", "pick", "pick", "pick"]
[[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
Output
[null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]

Explanation
Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
solution.pick(); // return [1, -2]
solution.pick(); // return [1, -1]
solution.pick(); // return [-1, -2]
solution.pick(); // return [-2, -2]
solution.pick(); // return [0, 0]

Constraints:

1 <= rects.length <= 100
rects[i].length == 4
-10^9 <= ai < xi <= 10^9
-10^9 <= bi < yi <= 10^9
xi - ai <= 2000
yi - bi <= 2000
All the rectangles do not overlap.
At most 10^4 calls will be made to pick.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	p := NewPicker([][4]int{{-2, -2, 1, 1}, {2, 2, 4, 6}})
	for range 100 {
		fmt.Println(p.Pick())
	}
}

type Picker struct {
	s []int
	r [][4]int
}

func NewPicker(r [][4]int) Picker {
	n := len(r)
	s := make([]int, n+1)
	for i, v := range r {
		s[i+1] = s[i] + (v[2]-v[0]+1)*(v[3]-v[1]+1)
	}
	return Picker{s, r}
}

func (p *Picker) Pick() [2]int {
	if len(p.r) == 0 || len(p.s) == 0 {
		return [2]int{}
	}

	v := 1 + rand.Intn(p.s[len(p.s)-1])
	l := 0
	r := len(p.r)
	for l < r {
		m := l + (r-l)/2
		if p.s[m] >= v {
			r = m
		} else {
			l = m + 1
		}
	}
	z := p.r[l-1]
	x := z[0] + rand.Intn(z[2]-z[0]+1)
	y := z[1] + rand.Intn(z[3]-z[1]+1)
	return [2]int{x, y}
}
