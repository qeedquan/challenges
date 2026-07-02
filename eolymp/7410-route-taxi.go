/*

During rush hour, three minibuses on the same route arrived at a stop simultaneously, and passengers quickly filled them.
The drivers noticed that each minibus had a different number of passengers and decided to redistribute them so that each minibus would have an equal number of passengers.
Your task is to determine the minimum number of passengers that need to be moved to achieve this balance.

Input
You will be given three natural numbers, each not exceeding 100.
These numbers represent the number of passengers in the first, second, and third minibuses, respectively.

Output
Output a single number representing the minimum number of passengers that need to be transferred.
If equal distribution is not possible, output the word IMPOSSIBLE in uppercase letters.

Examples

Input #1
1 2 3

Answer #1
1

*/

package main

func main() {
	assert(solve(1, 2, 3) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b, c int) any {
	if (a+b+c)%3 != 0 {
		return "IMPOSSIBLE"
	}

	k := (a + b + c) / 3
	return max(a-k, 0) + max(b-k, 0) + max(c-k, 0)
}
