/*

Description

A racing bicycle is driven by a chain connecting two sprockets. Sprockets are grouped into two clusters: the front cluster (typically consisting of 2 or 3 sprockets) and the rear cluster (typically consisting of between 5 and 10 sprockets). At any time the chain connects one of the front sprockets to one of the rear sprockets. The drive ratio -- the ratio of the angular velocity of the pedals to that of the wheels -- is n : m where n is the number of teeth on the rear sprocket and m is the number of teeth on the front sprocket. Two drive ratios d1 < d2 are adjacent if there is no other drive ratio d1 < d3 < d2. The spread between a pair of drive ratios d1 < d2 is their quotient: d2 ⁄ d1. You are to compute the maximum spread between two adjacent drive ratios achieved by a particular pair of front and rear clusters.

Input

Input consists of several test cases, followed by a line containing 0. Each test case is specified by the following input:

f: the number of sprockets in the front cluster;
r: the number of sprockets in the rear cluster;
f integers, each giving the number of teeth on one of the gears in the front cluster;
r integers, each giving the number of teeth on one of the gears in the rear cluster.
You may assume that no cluster has more than 10 sprockets and that no gear has fewer than 10 or more than 100 teeth.

Output

For each test case, output the maximum spread rounded to two decimal places.

Sample Input

2 4
40 50
12 14 16 19
0

Sample Output

1.19

Source

Waterloo Local Contest, 2007.7.14

*/

package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	test([]int{40, 50}, []int{12, 14, 16, 19}, 1.19)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(f, r []int, e float64) {
	v := spread(f, r)
	fmt.Println(v)
	assert(math.Abs(v-e) < 1e-2)
}

func spread(f, r []int) float64 {
	var s []float64
	for i := range f {
		for j := range r {
			s = append(s, float64(r[j])/float64(f[i]))
		}
	}

	sort.Float64s(s)

	v := 0.0
	for i := 1; i < len(s); i++ {
		v = max(v, s[i]/s[i-1])
	}
	return v
}
