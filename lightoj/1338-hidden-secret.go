/*

In this problem, you are given two names, you have to find whether one name is hidden into another. The restrictions are:

You can change some uppercase letters to lower case and vice versa.
You can add/remove spaces freely.
You can permute the letters.
And if both the names match exactly, then you can say that one name is hidden into another.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case starts with two lines. Each line contains a name consists of upper/lower case English letters and spaces. You can assume that the length of any name is between 1 and 100(inclusive).

Output
For each case, print the case number and Yes if one name is hidden into another. Otherwise print No.

Sample
Input	Output
3
Tom Marvolo Riddle
I am Lord Voldemort
I am not Harry Potter
Hi Pretty Roar to man
Harry and Voldemort
Tom and Jerry and Harry

Case 1: Yes
Case 2: Yes
Case 3: No

*/

package main

import (
	"maps"
	"strings"
)

func main() {
	assert(solve("Tom Marvolo Riddle", "I am Lord Voldemort") == "Yes")
	assert(solve("I am not Harry Potter", "Hi Pretty Roar to man") == "Yes")
	assert(solve("Harry and Voldemort", "Tom and Jerry and Harry") == "No")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b string) string {
	a = strings.ToLower(a)
	b = strings.ToLower(b)
	a = strings.Replace(a, " ", "", -1)
	b = strings.Replace(b, " ", "", -1)
	if maps.Equal(count(a), count(b)) {
		return "Yes"
	}
	return "No"
}

func count(s string) map[rune]int {
	m := make(map[rune]int)
	for _, r := range s {
		m[r] += 1
	}
	return m
}
