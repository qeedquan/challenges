/*

Background
Suppose that there are 2*n people to be married, and suppose further that each person is attracted to exactly n other people under the constraints that:

Attraction is symmetric; i.e. if person A is attracted to person B, then person B is attracted to person A.
Attraction is antitransitive; i.e. if person A and person B are each attracted to person C, then person A and person B are not attracted to each other.
Thus the network of attractions forms the (undirected) complete bipartite graph Kn,n. We also assume that each person has ranked the people they are attracted to. These may be represented as edge weights in the graph.

A marriage is a pairing (A,B) where A and B are attracted to each other. The marriage is unstable if there is another marriage where one person from each marriage could divorce their partner and marry each other and both end up with someone they ranked higher than their former partner.

Goal
Your task is to write a complete program or function which takes each person's preferences as input and outputs a marriage for each person such that each marriage is stable.

Input
Input may be in any convenient format; e.g., weighted graph, ordered list of preferences, dictionary/assocation, etc. You may optionally take the total number of people as input, but no other input is allowed.

Output
Output can also be in any convenient format; e.g. list of tuples, minimal edge cover, a function which associates to each person their partner, etc. Note that the only constraint is that each marriage is stable, there are no other optimality requirements.

Notes
You can find more information and an O(n^2) algorithm to solve this problem on Wikipedia or this Numberphile video. You are free to use any algorithm, however.
Standard loopholes are forbidden.
This is code-golf. Shortest answer (in bytes) wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(solve([][]int{
		{3, 4, 5}, {4, 3, 5},
		{3, 5, 4}, {1, 0, 2},
		{2, 1, 0}, {0, 1, 2},
	}))

	fmt.Println(solve([][]int{
		{7, 5, 6, 4}, {5, 4, 6, 7},
		{4, 5, 6, 7}, {4, 5, 6, 7},
		{0, 1, 2, 3}, {0, 1, 2, 3},
		{0, 1, 2, 3}, {0, 1, 2, 3},
	}))
}

/*

https://en.wikipedia.org/wiki/Stable_matching_problem
https://www.geeksforgeeks.org/stable-marriage-problem/

Gale–Shapley Algorithm - O(n^2) Time and Space

*/

func solve(P [][]int) (M, W []int) {
	if len(P) == 0 || len(P[0]) == 0 {
		return
	}
	n := len(P[0])
	M = make([]int, n)
	W = make([]int, n)
	for i := range n {
		M[i] = -1
		W[i] = i + n
	}

	f := make([]bool, n)
	for c := n; c > 0; {
		m1 := 0
		for m1 = range f {
			if !f[m1] {
				break
			}
		}

		for i := 0; i < n && !f[m1]; i++ {
			w := P[m1][i]
			if M[w-n] == -1 {
				M[w-n], f[m1], c = m1, true, c-1
			} else if m2 := M[w-n]; !cmp(P, w, m1, m2) {
				M[w-n], f[m1], f[m2] = m1, true, false
			}
		}
	}
	return
}

func cmp(P [][]int, w, m1, m2 int) bool {
	for i := range P[0] {
		if P[w][i] == m2 {
			return true
		}
		if P[w][i] == m1 {
			return false
		}
	}
	return false
}
