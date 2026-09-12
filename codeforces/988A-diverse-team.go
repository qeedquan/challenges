/*

There are n students in a school class, the rating of the i-th student on Codehorses is ai. You have to form a team consisting of k students (1≤k≤n) such that the ratings of all team members are distinct.

If it is impossible to form a suitable team, print "NO" (without quotes). Otherwise print "YES", and then print k distinct numbers which should be the indices of students in the team you form. If there are multiple answers, print any of them.

Input
The first line contains two integers n and k (1≤k≤n≤100) — the number of students and the size of the team you have to form.

The second line contains n integers a1,a2,…,an (1≤ai≤100), where ai is the rating of i-th student.

Output
If it is impossible to form a suitable team, print "NO" (without quotes). Otherwise print "YES", and then print k distinct integers from 1 to n which should be the indices of students in the team you form. All the ratings of the students in the team should be distinct. You may print the indices in any order. If there are multiple answers, print any of them.

Assume that the students are numbered from 1 to n.

Examples

input
5 3
15 13 15 15 12
output
YES
1 2 5

input
5 4
15 13 15 15 12
output
NO

input
4 4
20 10 40 30
output
YES
1 2 3 4

Note
All possible answers for the first example:

{1 2 5}
{2 3 5}
{2 4 5}
Note that the order does not matter.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{15, 13, 15, 15, 12}, 3, []int{1, 2, 5})
	test([]int{15, 13, 15, 15, 12}, 4, []int{})
	test([]int{20, 10, 40, 30}, 4, []int{1, 2, 3, 4})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, k int, r []int) {
	p := suitable(a, k)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func suitable(a []int, k int) []int {
	m := make(map[int]bool)
	r := []int{}
	for i, v := range a {
		if !m[v] {
			r, m[v] = append(r, i+1), true
		}
	}

	if len(r) < k {
		return []int{}
	}
	return r
}
