/*

n participants of “crazy tea party” sit around the table. Each minute one pair of neighbors can change
their places. Find the minimum time (in minutes) required for all participants to sit in reverse order
(so that left neighbors would become right, and right — left).

Input
The first line is the amount of tests. Each next line contains one integer n (1 ≤ n ≤ 32767) — the
amount of crazy tea participants.

Output
For each number n of participants to crazy tea party print on the standard output, on a separate line,
the minimum time required for all participants to sit in reverse order.

Sample Input
3
4
5
6

Sample Output
2
4
6

*/

package main

func main() {
	tab := []int{
		0, 0, 1, 2, 4, 6, 9, 12, 16, 20, 25, 30, 36, 42, 49, 56, 64, 72, 81,
		90, 100, 110, 121, 132, 144, 156, 169, 182, 196, 210, 225, 240, 256,
		272, 289, 306, 324, 342, 361, 380, 400, 420, 441, 462, 484, 506, 529,
		552, 576, 600, 625, 650, 676, 702, 729, 756, 784, 812,
	}

	assert(count(4) == 2)
	assert(count(5) == 4)
	assert(count(6) == 6)
	for i := range tab {
		assert(count(i+1) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A002620
func count(n int) int {
	a := n / 2
	b := n - n/2
	return a*(a-1)/2 + b*(b-1)/2
}
