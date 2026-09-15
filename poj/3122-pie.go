/*

Description

My birthday is coming up and traditionally I'm serving pie. Not just one pie, no, I have a number N of them, of various tastes and of various sizes. F of my friends are coming to my party and each of them gets a piece of pie. This should be one piece of one pie, not several small pieces since that looks messy. This piece can be one whole pie though.

My friends are very annoying and if one of them gets a bigger piece than the others, they start complaining. Therefore all of them should get equally sized (but not necessarily equally shaped) pieces, even if this leads to some pie getting spoiled (which is better than spoiling the party). Of course, I want a piece of pie for myself too, and that piece should also be of the same size.

What is the largest possible piece size all of us can get? All the pies are cylindrical in shape and they all have the same height 1, but the radii of the pies can be different.

Input

One line with a positive integer: the number of test cases. Then for each test case:
One line with two integers N and F with 1 ≤ N, F ≤ 10 000: the number of pies and the number of friends.
One line with N integers ri with 1 ≤ ri ≤ 10 000: the radii of the pies.

Output

For each test case, output one line with the largest possible volume V such that me and my friends can all get a pie piece of size V. The answer should be given as a floating point number with an absolute error of at most 10−3.

Sample Input

3
3 3
4 3 3
1 24
5
10 5
1 4 2 3 4 5 6 5 4 2

Sample Output

25.1327
3.1416
50.2655

Source

Northwestern Europe 2006

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]int{4, 3, 3}, 3, 25.1327)
	test([]int{5}, 24, 3.1416)
	test([]int{1, 4, 2, 3, 4, 5, 6, 5, 4, 2}, 5, 50.2655)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, f int, r float64) {
	v := volume(a, f)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-4)
}

func volume(a []int, f int) float64 {
	const eps = 1e-4

	var (
		p    []float64
		l, u float64
	)
	for _, r := range a {
		d := float64(r*r) * math.Pi
		p = append(p, d)
		u = max(u, d)
	}

	for u-l > eps {
		m := (u + l) / 2
		v := 0
		for i := range p {
			v += int(p[i] / m)
		}

		if v >= f+1 {
			l = m
		} else {
			u = m
		}
	}
	return l
}
