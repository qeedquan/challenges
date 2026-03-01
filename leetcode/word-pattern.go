/*

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false


Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.

*/

package main

import (
	"reflect"
	"strings"
)

func main() {
	assert(wordpattern("abba", "dog cat cat dog") == true)
	assert(wordpattern("abba", "dog cat cat fish") == false)
	assert(wordpattern("aaaa", "dog cat cat dog") == false)
	assert(wordpattern("aaaa", "dog dog dog dog") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func wordpattern(p, s string) bool {
	a := []rune(p)
	b := strings.Split(s, " ")
	return reflect.DeepEqual(count(a), count(b))
}

func count[T rune | string](a []T) map[int]int {
	h := make(map[int]int)
	m := make(map[T]int)
	i := 0
	for _, v := range a {
		if _, ok := m[v]; !ok {
			m[v], i = i, i+1
		}
		h[m[v]]++
	}
	return h
}
