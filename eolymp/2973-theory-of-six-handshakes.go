/*

The theory of six degrees of separation was proposed in 1969 by American psychologists Stanley Milgram and Jeffrey Travers.
Their hypothesis states that any two people on Earth are connected through a short chain of mutual acquaintances.
On average, this chain consists of five intermediaries.
Thus, if these two people decided to shake hands through mutual acquaintances, it would take, on average, six handshakes.

For example, if person A knows person G through the sequence of people B, C, D, E, F, then the handshake chain is as follows: A↔B↔C↔D↔E↔F↔G.
In this case, there are exactly six handshakes, and the chain of mutual acquaintances consists of exactly 5 people (B, C, D, E, F).

In this problem, of course, we will not check the hypothesis for all inhabitants of the Earth.
You are given a description of a group of people.
You must determine whether, between any two members of the given group, there is a chain of mutual acquaintances that includes no more than 5 people.

Input
The input file describes a group of N people.

The first line contains two natural numbers N (2≤N≤100) and M (0≤M≤N⋅(N−1)/2) —
the number of people in the group and the number of pairs of mutual acquaintances among them.

The following M lines each contain two natural numbers A and B (1≤A,B≤N) separated by a space — the indices of two members of the group who are mutual acquaintances.
All members of the group are numbered from 1 to N.

Output
Output YES if, between any two members of the given group, there is a chain of mutual acquaintances that includes no more than 5 people.

If there exist at least two people between whom no such chain exists, output NO.

Examples
Input #1
7 6
1 2
2 3
3 4
4 5
5 6
6 7

Answer #1
YES

*/

package main

import "math"

func main() {
	assert(solve(7, [][2]int{
		{1, 2},
		{2, 3},
		{3, 4},
		{4, 5},
		{5, 6},
		{6, 7},
	}) == "YES")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int, v [][2]int) string {
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g {
			g[i][j] = math.MaxInt
		}
	}

	for _, v := range v {
		a, b := v[0]-1, v[1]-1
		g[a][b] = 1
		g[b][a] = 1
	}

	floydwarshall(g, n)

	r := -1
	for i := range g {
		for j := range g[i] {
			r = max(r, g[i][j])
		}
	}
	if r <= 6 && r != -1 {
		return "YES"
	}
	return "NO"
}

func floydwarshall(g [][]int, n int) {
	for k := range n {
		for i := range n {
			for j := range n {
				if g[i][k] < math.MaxInt && g[k][j] < math.MaxInt {
					g[i][j] = min(g[i][j], g[i][k]+g[k][j])
				}
			}
		}
	}
}
