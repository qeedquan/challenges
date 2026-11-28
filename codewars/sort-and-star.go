/*

You will be given a list of strings. You must sort it alphabetically (case-sensitive, and based on the ASCII values of the chars) and then return the first value.

The returned value must be a string, and have "***" between each of its letters.

You should not remove or add elements from/to the array.

*/

package main

import (
	"sort"
	"strings"
)

func main() {
	assert(twosort([]string{"turns", "out", "random", "test", "cases", "are", "easier", "than", "writing", "out", "basic", "ones"}) == "a***r***e")
	assert(twosort([]string{"bitcoin", "take", "over", "the", "world", "maybe", "who", "knows", "perhaps"}) == "b***i***t***c***o***i***n")
	assert(twosort([]string{"i", "want", "to", "travel", "the", "world", "writing", "code", "one", "day"}) == "c***o***d***e")
	assert(twosort([]string{"Lets", "all", "go", "on", "holiday", "somewhere", "very", "cold"}) == "L***e***t***s")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func twosort(s []string) string {
	if len(s) == 0 {
		return ""
	}

	sort.Strings(s)
	r := strings.Replace(s[0], "", "***", -1)
	r = strings.TrimPrefix(r, "***")
	r = strings.TrimSuffix(r, "***")
	return r
}
