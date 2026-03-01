/*

You are given the task to design a lighting system for a huge conference hall. After doing a lot of
calculation and sketching, you have figured out the requirements for an energy-efficient design that
can properly illuminate the entire hall. According to your design, you need lamps of n different power
ratings. For some strange current regulation method, all the lamps need to be fed with the same
amount of current. So, each category of lamp has a corresponding voltage rating. Now, you know the
number of lamps and cost of every single unit of lamp for each category. But the problem is, you are
to buy equivalent voltage sources for all the lamp categories. You can buy a single voltage source for
each category (Each source is capable of supplying to infinite number of lamps of its voltage rating.)
and complete the design. But the accounts section of your company soon figures out that they might
be able to reduce the total system cost by eliminating some of the voltage sources and replacing the
lamps of that category with higher rating lamps. Certainly you can never replace a lamp by a lower
rating lamp as some portion of the hall might not be illuminated then. You are more concerned about
money-saving than energy-saving. Find the minimum possible cost to design the system.

Input
Each case in the input begins with n (1 ≤ n ≤ 1000), denoting the number of categories. Each of the
following n lines describes a category. A category is described by 4 integers - V (1 ≤ V ≤ 132000), the
voltage rating, K (1 ≤ K ≤ 1000), the cost of a voltage source of this rating, C (1 ≤ C ≤ 10), the cost
of a lamp of this rating and L (1 ≤ L ≤ 100), the number of lamps required in this category. The input
terminates with a test case where n = 0. This case should not be processed.

Output
For each test case, print the minimum possible cost to design the system.

Sample Input
3
100 500 10 20
120 600 8 16
220 400 7 18
0

Sample Output
778

*/

package main

import (
	"math"
	"sort"
)

func main() {
	assert(cost([]Category{
		{100, 500, 10, 20},
		{120, 600, 8, 16},
		{220, 400, 7, 18},
	}) == 778)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cost(a []Category) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i].v < a[j].v
	})

	s := make([]int, n+1)
	p := make([]int, n+1)
	for i := 1; i <= n; i++ {
		s[i] += s[i-1] + a[i-1].l
	}

	p[1] = a[0].k + a[0].c*a[0].l
	for i := 2; i <= n; i++ {
		p[i] = math.MaxInt
		for j := 0; j < i; j++ {
			p[i] = min(p[i], p[j]+(s[i]-s[j])*a[i-1].c+a[i-1].k)
		}
	}
	return p[n]
}

type Category struct {
	v, k, c, l int
}
