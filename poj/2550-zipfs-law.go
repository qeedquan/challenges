/*

Description

Harvard linguistics professor George Kingsley Zipf (1902-1950) observed that the frequency of the kth most common word in a text is roughly proportional to 1/k. He justified his observations in a book titled Human behavior and the principle of least effort published in 1949. While Zipf's rationale has largely been discredited, the principle still holds, and others have afforded it a more sound mathematical basis.
You are to find all the words occurring n times in an English text. A word is a sequence of letters. Words are separated by non-letters. Capitalization should be ignored. A word can be of any length that an English word can be.

http://poj.org/images/2550_1.jpg

Input

Input consists of several test cases. The first line of each case contains a single positive integer n. Several lines of text follow which will contain no more than 10000 words. The text for each case is terminated by a single line containing EndOfText. EndOfText does not appear elsewhere in the input and is not considered a word.

Output

For each test case, output the words which occur n times in the input text, one word per line, lower case, in alphabetical order. If there are no such words in input, output the following line:
There is no such word.

Leave a blank line between cases.

Sample Input

2

In practice, the difference between theory and practice is always
greater than the difference between theory and practice in theory.
	- Anonymous

Man will occasionally stumble over the truth, but most of the
time he will pick himself up and continue on.
        - W. S. L. Churchill
EndOfText

Sample Output

between
difference
in
will
Source

Waterloo local 2001.06.02

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
	"strings"
	"unicode"
)

func main() {
	test(2, `In practice, the difference between theory and practice is always
greater than the difference between theory and practice in theory.
	- Anonymous

Man will occasionally stumble over the truth, but most of the
time he will pick himself up and continue on.
        - W. S. L. Churchill`, []string{"between", "difference", "in", "will"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, s string, r []string) {
	w := count(n, s)
	fmt.Println(w)
	assert(reflect.DeepEqual(w, r))
}

func count(n int, s string) []string {
	m := make(map[string]int)
	s = strings.Replace(s, "\n", " ", -1)
	t := strings.Split(s, " ")
	for _, t := range t {
		t = strings.TrimRight(t, ",")
		t = strings.TrimRight(t, ".")
		t = strings.ToLower(t)
		if isword(t) {
			m[t]++
		}
	}

	w := []string{}
	for k, v := range m {
		if v == n {
			w = append(w, k)
		}
	}
	sort.Strings(w)

	return w
}

func isword(s string) bool {
	for _, r := range s {
		if !unicode.IsLetter(r) {
			return false
		}
	}
	return true
}
