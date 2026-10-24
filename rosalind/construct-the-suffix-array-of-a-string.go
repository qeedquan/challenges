/*

In “Find the Longest Repeat in a String”, we saw that suffix trees can be too memory intensive to apply in practice.

In 1993, Udi Manber and Gene Myers introduced suffix arrays as a memory-efficient alternative to suffix trees. To construct SuffixArray(Text), we first sort all suffixes of Text lexicographically, assuming that "$" comes first in the alphabet. The suffix array is the list of starting positions of these sorted suffixes. For example,

SuffixArray("panamabananas$") = (13, 5, 3, 1, 7, 9, 11, 6, 4, 2, 8, 10, 0, 12).
Suffix Array Construction Problem
Construct the suffix array of a string.

Given: A string Text.

Return: SuffixArray(Text).

Sample Dataset
AACGATAGCGGTAGA$
Sample Output
15, 14, 0, 1, 12, 6, 4, 2, 8, 13, 3, 7, 9, 10, 11, 5

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test("panamabananas$", []int{13, 5, 3, 1, 7, 9, 11, 6, 4, 2, 8, 10, 0, 12})
	test("AACGATAGCGGTAGA$", []int{15, 14, 0, 1, 12, 6, 4, 2, 8, 13, 3, 7, 9, 10, 11, 5})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []int) {
	p := suffixarray(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func suffixarray(s string) []int {
	type seq struct {
		x int
		t string
	}

	p := []seq{}
	for i := range s {
		p = append(p, seq{i, s[i:]})
	}

	sort.Slice(p, func(i, j int) bool {
		return p[i].t < p[j].t
	})

	r := make([]int, len(s))
	for i := range r {
		r[i] = p[i].x
	}
	return r
}
