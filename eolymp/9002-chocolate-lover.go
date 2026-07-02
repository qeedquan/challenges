/*

Aziz is very fond of eating chocolate.
But since chocolate is very bad for teeth, his father won't let him eat a lot of chocolate.
This time he managed to convince his father and get permission to eat one chocolate every day.
Aziz loves two types of chocolate. One weighs a grams, the other b grams.
Aziz's father allowed him to eat one chocolate every day for n days, but with condition that he should not eat the same chocolate for two days in a row.
Now Aziz is worried about only one question. How to make sure that within n days he could eat the maximum amount (in grams) of chocolate.

Help him with this.

Input
One line contains three integers n,a and b (1≤n,a,b≤10^9).

Output
Print the maximum amount of chocolate (in grams) that Aziz can consume during n days.

Examples

Input #1
1 10 8

Answer #1
10

Input #2
3 1 2

Answer #2
5

*/

package main

func main() {
	assert(solve(1, 10, 8) == 10)
	assert(solve(3, 1, 2) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, a, b int) int {
	return a*(n/2) + b*(n/2) + max(a, b)*(n%2)
}
