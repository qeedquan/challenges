/*

As is well known, when asked about the number of his disciples, the ancient Greek scholar Pythagoras replied as follows:
Half of my disciples study mathematics, a quarter study nature, a seventh devote themselves to silent contemplation, and the remainder are 3 maidens.

When asked, "How many participants are registered for the informatics olympiad?", the olympiad secretary answers in Pythagorean style:
The k-th part of the participants started the first problem, the m-th part started the second,
the n-th part started the third, and another d participants are busy with the "Where to begin?" problem.
Your task is to determine the number of olympiad participants s, or output -1 if the secretary made a mistake.

Input
A single line contains four integers k, m, n, d (1≤k,m,n,d≤1000), separated by spaces.

Output
Output the number of olympiad participants s, or -1 if the secretary made a mistake.

Examples

Input #1
2 4 7 3

Answer #1
28

*/

package main

func main() {
	assert(solve(2, 4, 7, 3) == 28)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(k, n, m, d int) int {
	x := d * k * n * m
	y := k*n*m - m*n - n*k - m*k
	if y == 0 || x%y != 0 {
		return -1
	}
	return x / y
}
