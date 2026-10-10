/*

You are given a positive integer n. Simulate a countdown timer from n to 0 seconds as shown in the example.

Input
The input contains a single positive integer n.

Output
Print all integers from n down to 0 inclusive, each followed by the text "sek", with each pair on a separate line.

Examples
Input #1
2

Answer #1
2 sek
1 sek
0 sek

*/

package main

import "fmt"

func main() {
	solve(2)
}

func solve(n int) {
	for i := n; i >= 0; i-- {
		fmt.Println(i, "sek")
	}
}
