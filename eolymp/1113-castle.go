/*

https://static.e-olymp.com/content/13/1378ecd769df3cb35f7d3b123be2c70e3a406424.jpg

The castle consists of K levels.
Each level is a regular N-gon, with its angles aligned with the previous level (the structure of the castle for example input is shown in the figure).
On each side of the first level, there are two rooms, and on each side of every next level, there is one more room than the previous level.
Find the total number of rooms in the castle.

Input
The only line of input contains two integers N and K (3≤N≤10^6, 1≤K≤10^6).

Output
Output a single number, the total number of rooms in the castle.

Examples

Input #1
6 3

Answer #1
28

*/

package main

func main() {
	assert(solve(6, 3) == 28)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, k int) int {
	return (2*n+1*n*(k-1))*k/2 - (2*3+2*(k-2))*(k-1)/2
}
