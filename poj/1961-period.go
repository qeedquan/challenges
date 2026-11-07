/*

Description

For each prefix of a given string S with N characters (each character has an ASCII code between 97 and 126, inclusive), we want to know whether the prefix is a periodic string. That is, for each i (2 <= i <= N) we want to know the largest K > 1 (if there is one) such that the prefix of S with length i can be written as AK ,that is A concatenated K times, for some string A. Of course, we also want to know the period K.

Input

The input consists of several test cases. Each test case consists of two lines. The first one contains N (2 <= N <= 1 000 000) – the size of the string S.The second line contains the string S. The input file ends with a line, having the
number zero on it.

Output

For each test case, output "Test case #" and the consecutive test case number on a single line; then, for each prefix with length i that has a period K > 1, output the prefix size i and the period K separated by a single space; the prefix sizes must be in increasing order. Print a blank line after each test case.

Sample Input

3
aaa
12
aabaabaabaab
0

Sample Output

Test case #1
2 2
3 3

Test case #2
2 2
6 2
9 3
12 4

Source

Southeastern Europe 2004

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test("aaa", [][2]int{
		{2, 2},
		{3, 3},
	})

	test("aabaabaabaab", [][2]int{
		{2, 2},
		{6, 2},
		{9, 3},
		{12, 4},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r [][2]int) {
	p := prefixsize(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func prefixsize(s string) [][2]int {
	r := [][2]int{}
	p := kmp(s)
	for i := 1; i <= len(s); i++ {
		if i != p[i] && p[i] != 0 && i%(i-p[i]) == 0 {
			r = append(r, [2]int{i, i / (i - p[i])})
		}
	}
	return r
}

// https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
func kmp(s string) []int {
	n := len(s)
	r := make([]int, n+1)
	r[0] = -1
	for i, j := 0, -1; i < n; r[i] = j {
		for j >= 0 && s[i] != s[j] {
			j = r[j]
		}
		i, j = i+1, j+1
	}
	return r
}
