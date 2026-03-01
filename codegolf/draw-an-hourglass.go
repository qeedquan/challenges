/*

Again inspired by a task for Programming 101 here's another challenge.

Input:

A positive integer n >= 3. (has to be odd)
Output:

n lines of asterisks, where the first line has n asterisks and every new line has two asterisks less than the line before. Until hitting 1 asterisk. From there every new line has two asterisks more than the line before until getting back to n asterisks. Spaces or something like spaces have to used to align the asterisks so that it really will look like an hourglass.
General rules:

Trailing newlines are allowed but do not have to be used.
indentation is a must.

This is code-golf, so shortest answer in bytes wins.
Since the course is taught in C++, I'm eager to see solutions in C++.
Test case (n=5):

*****
 ***
  *
 ***
*****

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := 3; i <= 15; i += 2 {
		fmt.Println(hourglass(i))
	}
}

func hourglass(n int) string {
	return recurse(n, 0)
}

func recurse(n, i int) string {
	if n < 1 {
		return ""
	}

	s := strings.Repeat(" ", i) + strings.Repeat("*", n) + "\n"
	if n > 1 {
		s = s + recurse(n-2, i+1) + s
	}
	return s
}
