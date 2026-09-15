/*

You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj].
Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval.
For example, the intersection of [1, 3] and [2, 4] is [2, 3].

Example 1:
Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

Example 2:
Input: firstList = [[1,3],[5,9]], secondList = []
Output: []

Constraints:

0 <= firstList.length, secondList.length <= 1000
firstList.length + secondList.length >= 1
0 <= start[i] < end[i] <= 10^9
endi < start[i+1]
0 <= start[j] < end[j] <= 10^9
end[j] < start[j+1]

*/

package main

import (
	"fmt"
	"reflect"
)

type Interval struct {
	start int
	end   int
}

func main() {
	test(
		[]Interval{{0, 2}, {5, 10}, {13, 23}, {24, 25}},
		[]Interval{{1, 5}, {8, 12}, {15, 24}, {25, 26}},
		[]Interval{{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}},
	)

	test(
		[]Interval{{1, 3}, {5, 9}},
		[]Interval{},
		[]Interval{},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, r []Interval) {
	p := intersect(a, b)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func intersect(a, b []Interval) []Interval {
	n := len(a)
	m := len(b)
	r := []Interval{}
	if n == 0 || m == 0 {
		return r
	}

	for i, j := 0, 0; i < n && j < m; {
		if overlap(a[i], b[j]) {
			r = append(r, merge(a[i], b[j]))
			k := i
			if j == m-1 || !overlap(a[i], b[j+1]) {
				k = i + 1
			}
			if i == n-1 || !overlap(a[i+1], b[j]) {
				j += 1
			}
			i = k
		} else {
			if compare(a[i], b[j]) {
				i += 1
			} else {
				j += 1
			}
		}
	}
	return r
}

func merge(a, b Interval) Interval {
	return Interval{
		max(a.start, b.start),
		min(a.end, b.end),
	}
}

func overlap(a, b Interval) bool {
	if a.start < b.start {
		return a.end >= b.start
	}
	return b.end >= a.start
}

func compare(a, b Interval) bool {
	return a.start < b.start
}
