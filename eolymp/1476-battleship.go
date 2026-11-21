/*

Parallel to the coastline, an enemy fleet is stationed at sea.
The area where the fleet is located is divided into n squares.
On the main ship of our fleet, there is a secret weapon that can strike k consecutive squares simultaneously.
All enemy ships within these targeted squares will be destroyed.
Unfortunately, the secret weapon can only be used once, so it is crucial to maximize the damage inflicted on the enemy with this single shot.

Write a program to determine the maximum number of ships that can be destroyed with one shot.

Input
The first line contains two integers n and k (1≤k≤n≤10^5).
The second line contains n integers ai (0≤ai≤10000), where each integer represents the number of ships in the corresponding square of the strip.

Output
Output the maximum number of ships that can be destroyed.

Examples

Input #1
7 3
3 2 1 2 3 2 1

Answer #1
7

*/

package main

func main() {
	assert(solve([]int{3, 2, 1, 2, 3, 2, 1}, 3) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a []int, k int) int {
	n := len(a)
	p := make([]int, n)
	for i := 1; i < n; i++ {
		p[i] = p[i-1] + a[i]
	}

	r := 0
	for i := k; i < n; i++ {
		r = max(r, p[i]-p[i-k])
	}
	return r
}
