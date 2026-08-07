/*

Given an integer N (1≤N≤12), representing the number of a month in a year.
For the given value N, output the name of the quarter to which this month belongs.

Input
The only number — the number of the month in the year.

Output
Output a single line with the name of the corresponding quarter.
Print First for the first quarter, Second for the second, Third for the third, and Fourth for the fourth quarter.

Examples

Input #1
5

Answer #1
Second

*/

package main

import "fmt"

func main() {
	assert(solve(5) == "Second")

	for i := 1; i <= 12; i++ {
		fmt.Println(i, solve(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) string {
	tab := map[int]string{
		1: "First",
		2: "Second",
		3: "Third",
		4: "Fourth",
	}

	i := n / 3
	if n%3 != 0 {
		i += 1
	}
	return tab[i]
}
