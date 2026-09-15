/*

Task
If possible, divide the integers 1,2,…,n into two sets of equal sum.

Input
A positive integer n <= 1,000,000.

Output
If it's not possible, return [ ] (Python, Javascript, Swift, Ruby) or ( ) (Python) or [ [],[] ] (Java, C#, C++, Kotlin) or None (Scala).
If it's possible, return two disjoint sets. Each integer from 1 to n must be in one of them. The integers in the first set must sum up to the same value as the integers in the second set. The sets can be returned in a tuple, list, or array, depending on language.

Examples:
For n = 8, valid answers include:
[1, 3, 6, 8], [2, 4, 5, 7] (or [[1, 3, 6, 8], [2, 4, 5, 7]])
[8, 1, 3, 2, 4], [5, 7, 6]
[7, 8, 3], [6, 1, 5, 4, 2], and others.

For n = 9 it is not possible. For example, try [6, 8, 9] and [1, 2, 3, 4, 5, 7], but the first sums to 23 and the second to 22. No other sets work either.

Source: CSES ( https://cses.fi/problemset/task/1092 )

*/

package main

import "fmt"

func main() {
	for i := range 32 {
		s1, s2 := twosets(i)
		fmt.Println(i, s1, s2)
	}
}

func twosets(n int) (s1, s2 []int) {
	t := triangular(n)
	if t%2 != 0 {
		return
	}

	t /= 2
	for c, i := 0, n; i > 0; i-- {
		if c+i <= t {
			s1 = append(s1, i)
			c += i
		} else {
			s2 = append(s2, i)
		}
	}
	return
}

func triangular(n int) int {
	return n * (n + 1) / 2
}
