/*

The Easter Bunnies invite you to a game of Easter egg throwing. There are N=777777 bunnies, and each one throws a single egg. The egg lands somewhere in an array with cells numbered from 1 to N. The throwing abilities of the bunnies appear quite random to you; the egg for the i-th bunny lands somewhere in a cell from the interval [first(i), last(i)]. What’s the highest number of eggs you could potentially find in a single cell after all the throws?

Input: A single integer X0 that is used as the seed for the Linear Congruential Generator introduced in the problem 25 - use A=445, C=700001 and M=2097152. Generate 2*N random values, transform them via value % N + 1 to the range 1 to N, split them into N pairs, and use the i-th pair (a(i), b(i)) to establish the i-th throwing interval as [min(a(i),b(i)), max(a(i),b(i))].

Output: The highest number of eggs you could find in a single cell after all bunnies have thrown their eggs (for X0=0, the answer is 389650).

*/

package main

func main() {
	assert(solve(0) == 389650)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(X0 int) int {
	const (
		N = 777777
		A = 445
		C = 700001
		M = 2097152
	)

	diff := make([]int, N+2)
	X := X0
	for range N {
		X = (A*X + C) % M
		a := (X % N) + 1

		X = (A*X + C) % M
		b := (X % N) + 1

		if a > b {
			a, b = b, a
		}

		diff[a] += 1
		diff[b+1] -= 1
	}

	max_eggs := 0
	current_eggs := 0
	for i := 1; i <= N; i++ {
		current_eggs += diff[i]
		max_eggs = max(max_eggs, current_eggs)
	}
	return max_eggs
}
