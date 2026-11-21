/*

Businessman Vasiliy started a new business – shipping honey in barrels.
It is important for his partners to know how many barrels of honey are shipped each day.

Vasiliy's mobile phone only supports translit, so he sends messages in the format "n bochek".
For example, "3 bochki" or "1 bochka".

Write a program that selects the correct word (from "bochka", "bochek", or "bochki") depending on n.

Input
One integer n (0≤n≤1000).

Output
The corresponding phrase in translit.

Examples

Input #1
1

Answer #1
1 bochka

Input #2
15

Answer #2
15 bochek

Input #3
3

Answer #3
3 bochki

*/

package main

import "fmt"

func main() {
	assert(solve(1) == "1 bochka")
	assert(solve(15) == "15 bochek")
	assert(solve(3) == "3 bochki")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) string {
	switch n % 100 {
	case 11, 12, 13, 14:
		return fmt.Sprint(n, " bochek")
	}

	switch n % 10 {
	case 1:
		return fmt.Sprint(n, " bochka")
	case 2, 3, 4:
		return fmt.Sprint(n, " bochki")
	}
	return fmt.Sprint(n, " bochek")
}
