/*

Given two arrays of strings a1 and a2 return a sorted array r in lexicographical order of the strings of a1 which are substrings of strings of a2.

Example 1:
a1 = ["arp", "live", "strong"]

a2 = ["lively", "alive", "harp", "sharp", "armstrong"]

returns ["arp", "live", "strong"]

Example 2:
a1 = ["tarp", "mice", "bull"]

a2 = ["lively", "alive", "harp", "sharp", "armstrong"]

returns []

Notes:
Arrays are written in "general" notation. See "Your Test Cases" for examples in your language.
In Shell bash a1 and a2 are strings. The return is a string where words are separated by commas.
Beware: r must be without duplicates.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
	"strings"
)

func main() {
	test([]string{"arp", "live", "strong"}, []string{"lively", "alive", "harp", "sharp", "armstrong"}, []string{"arp", "live", "strong"})
	test([]string{"tarp", "mice", "bull"}, []string{"lively", "alive", "harp", "sharp", "armstrong"}, []string{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, t, r []string) {
	p := inarray(s, t)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func inarray(s, t []string) []string {
	r := []string{}
	for i := range s {
		for j := range t {
			if strings.Index(t[j], s[i]) >= 0 {
				r = append(r, s[i])
				break
			}
		}
	}
	sort.Strings(r)
	return r
}
