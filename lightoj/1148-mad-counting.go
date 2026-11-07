/*

Mob was hijacked by the mayor of the Town "TruthTown". Mayor wants Mob to count the total population of the town. Now the naive approach to this problem will be counting people one by one. But as we all know Mob is a bit lazy, so he is finding some other approach so that the time will be minimized. Suddenly he found a poll result of that town where N people were asked "How many people in this town other than yourself support the same team as you in the FIFA world CUP 2010?" Now Mob wants to know if he can find the minimum possible population of the town from this statistics. Note that no people were asked the question more than once.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case starts with an integer N (1 ≤ N ≤ 50). The next line will contain N integers denoting the replies (0 to 10^6) of the people.

Output
For each case, print the case number and the minimum possible population of the town.

Sample
Input	Output
2
4
1 1 2 2
1
0

Case 1: 5
Case 2: 1

*/

package main

func main() {
	assert(solve([]int{1, 1, 2, 2}) == 5)
	assert(solve([]int{0}) == 1)
	assert(solve([]int{2, 2, 2, 2}) == 6)
	assert(solve([]int{1, 2, 3, 4, 5, 6, 7, 8}) == 44)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a []int) int {
	m := make(map[int]int)
	for _, x := range a {
		m[x] += 1
	}

	r := 0
	for k, v := range m {
		x := v / (k + 1)
		y := 0
		if v%(k+1) != 0 {
			y = 1
		}
		r += (x + y) * (k + 1)
	}
	return r
}
