/*

There are m tunnels and n intersections in the dungeon.
Each tunnel connects two intersections.
The Rat King decided to install a traffic light in each tunnel before each intersection.

Write a program that determines how many traffic lights need to be installed at each intersection. The intersections are numbered from 1 to n.

Input
The first line contains two integers n and m (0<n≤100,0≤m≤n*(n−1)/2).
Each of the next m lines contains two integers i and j (1≤i,j≤n), indicating that intersections i and j are connected by a tunnel.

Output
Print n integers: the k-th integer is the number of traffic lights that need to be installed at the k-th intersection.

It is guaranteed that there is at most one tunnel between any two intersections, and there are no tunnels connecting an intersection to itself.

https://static.e-olymp.com/content/d4/d43f8773c2ad8f4f83b1aaf11768128672743612.gif

Examples

Input #1
7 10
5 1
3 2
7 1
5 2
7 4
6 5
6 4
7 5
2 1
5 3

Answer #1
3 3 2 2 5 2 3

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(7, [][2]int{
		{5, 1},
		{3, 2},
		{7, 1},
		{5, 2},
		{7, 4},
		{6, 5},
		{6, 4},
		{7, 5},
		{2, 1},
		{5, 3},
	}))
}

func solve(n int, a [][2]int) []int {
	m := make(map[[2]int]bool)
	for _, v := range a {
		k0 := [2]int{v[0], v[1]}
		k1 := [2]int{v[1], v[0]}
		m[k0], m[k1] = true, true
	}

	r := []int{}
	for i := 1; i <= n; i++ {
		c := 0
		for j := 1; j <= n; j++ {
			k := [2]int{i, j}
			if m[k] {
				c += 1
			}
		}
		r = append(r, c)
	}
	return r
}
