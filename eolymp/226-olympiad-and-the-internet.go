/*

At the All-Ukrainian Olympiad, there are N participants in one of the dormitory sections, each with their own laptop.
In the corridor, there is only one working power socket, but the participants have K power strips, and each power strip can accommodate Ai additional devices.

Determine the minimal number of participants who cannot maintain a constant network connection.

https://static.e-olymp.com/content/f8/f8857d28a6a494ce910f4f7c733bbdd9c2b6130a.jpg

Input
The first line contains N and K — the number of Olympiad participants and the number of available power strips, respectively.

The second line contains K non-negative integers A1,A2,…,AK, where Ai is the number of additional devices each power strip can accommodate.
All input values do not exceed 1000.

Output
Output a single integer — the minimal number of participants who cannot maintain a constant network connection.

Examples

Input #1
5 1
3

Answer #1
2

*/

package main

func main() {
	assert(solve(5, []int{3}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int, x []int) int {
	r := 1
	for i := range x {
		r = r - 1 + x[i]
	}
	return max(n-r, 0)
}
