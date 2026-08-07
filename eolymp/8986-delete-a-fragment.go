/*

Given a string of Latin letters and spaces. Delete in it all characters with indices from n to m inclusive. Indexation starts from 0.

Input
The first line contains text of no more than 1000 Latin letters and spaces. Second line contains two integers n and m (n≤m).

Output
Print the updated string.

Examples

Input #1
abrakadabra
3 6

Answer #1
abrabra

Input #2
This is my lovely beautiful house
7 16

Answer #2
This is beautiful house

*/

package main

func main() {
	assert(solve("abrakadabra", 3, 6) == "abrabra")
	assert(solve("This is my lovely beautiful house", 7, 16) == "This is beautiful house")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string, n, m int) string {
	return s[:n] + s[m+1:]
}
