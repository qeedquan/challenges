/*

Sweet Country consists of several Candy States. You are given the list of the roads existing between these states and now you want to improve logistics to deliver candies faster!

Your task is for any pair of statest to find the route with minimal number of roads and tell this number. For example if Carnival is connected to Maycorn and this is connected to Bawnty, then route from Carnival to Bawnty consists of 2 roads.

You may want to build a transitive closure over the states map. For example with Floyd-Warshall algorithm.

Input data will contain:

the number of direct roads between states in the first line;
the list of these roads, described by pairs of states (in separate line each);
the number of routes to find (in separate line);
the list of routes, described by pairs of states.
Answer should have lengths of routes, separated by spaces, or value 10000000 if no route exists between the given states.

Example:

input data:
11
Cowsome - Honepy
Bawnty - Cowsome
Lacry - Bawnty
Honepy - Maycorn
Maycorn - Bawnty
Mikliday - Cowsome
Mausse - Lednec
Maycorn - Mausse
Bawnty - Mausse
Mikliday - Maycorn
Lednec - Maycorn
6
Cowsome - Mausse
Lacry - Honepy
Bawnty - Honepy
Mikliday - Mausse
Honepy - Lednec
Mikliday - Lacry

answer:
2 3 2 2 2 3

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve([][2]string{
		{"Cowsome", "Honepy"},
		{"Bawnty", "Cowsome"},
		{"Lacry", "Bawnty"},
		{"Honepy", "Maycorn"},
		{"Maycorn", "Bawnty"},
		{"Mikliday", "Cowsome"},
		{"Mausse", "Lednec"},
		{"Maycorn", "Mausse"},
		{"Bawnty", "Mausse"},
		{"Mikliday", "Maycorn"},
		{"Lednec", "Maycorn"},
	}, [][2]string{
		{"Cowsome", "Mausse"},
		{"Lacry", "Honepy"},
		{"Bawnty", "Honepy"},
		{"Mikliday", "Mausse"},
		{"Honepy", "Lednec"},
		{"Mikliday", "Lacry"},
	}))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(p, q [][2]string) []int {
	const invalid = 10000000

	m := makeids(p)
	n := len(m)
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g {
			g[i][j] = math.MaxInt
		}
	}

	for _, p := range p {
		a := m[p[0]]
		b := m[p[1]]
		g[a][b] = 1
		g[b][a] = 1
	}

	floydwarshall(g, n)

	r := []int{}
	for _, q := range q {
		a, fa := m[q[0]]
		b, fb := m[q[1]]
		if !fa || !fb {
			r = append(r, invalid)
		} else {
			r = append(r, min(g[a][b], invalid))
		}
	}
	return r
}

func makeids(p [][2]string) map[string]int {
	m := make(map[string]int)
	n := 0
	for _, p := range p {
		for i := range p {
			if _, f := m[p[i]]; !f {
				m[p[i]], n = n, n+1
			}
		}
	}
	return m
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
