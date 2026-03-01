/*

Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.

*/

package main

import "reflect"

func main() {
	test([]string{"bella", "label", "roller"}, "ell")
	test([]string{"cool", "lock", "cook"}, "co")
	test([]string{"abc", "def"}, "")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(w []string, r string) {
	x := commonchars(w)
	y := newmultiset(r)
	assert(reflect.DeepEqual(x, y))
}

func commonchars(w []string) multiset {
	if len(w) == 0 {
		return multiset{}
	}

	m := newmultiset(w[0])
	for _, s := range w[1:] {
		m = intersect(m, newmultiset(s))
	}
	return m
}

type multiset map[rune]int

func newmultiset(s string) multiset {
	m := make(multiset)
	for _, r := range s {
		m[r]++
	}
	return m
}

func intersect(x, y multiset) multiset {
	z := make(multiset)
	for r := range x {
		if y[r] > 0 {
			z[r] = min(x[r], y[r])
		}
	}
	return z
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
