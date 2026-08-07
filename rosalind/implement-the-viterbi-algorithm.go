/*

Decoding Problem
Given: A string x, followed by the alphabet Σ from which x was constructed, followed by the states States, transition matrix Transition, and emission matrix Emission of an HMM (Σ, States, Transition, Emission).

Return: A path that maximizes the (unconditional) probability Pr(x, π) over all possible paths π.

Sample Dataset
xyxzzxyxyy
--------
x   y   z
--------
A   B
--------
    A   B
A   0.641   0.359
B   0.729   0.271
--------
    x   y   z
A   0.117   0.691   0.192
B   0.097   0.42    0.483
Sample Output
AAABBAAAAA

*/

package main

import (
	"bytes"
	"math"
)

func main() {
	assert(decode(
		"xyxzzxyxyy",
		map[byte]int{'x': 0, 'y': 1, 'z': 2},
		map[byte]int{'A': 0, 'B': 1},
		[][]float64{{0.641, 0.359}, {0.729, 0.271}},
		[][]float64{{0.117, 0.691, 0.192}, {0.097, 0.42, 0.483}},
	) == "AAABBAAAAA")

	assert(decode(
		"zxxxxyzzxyxyxyzxzzxzzzyzzxxxzxxyyyzxyxzyxyxyzyyyyzzyyyyzzxzxzyzzzzyxzxxxyxxxxyyzyyzyyyxzzzzyzxyzzyyy",
		map[byte]int{'x': 0, 'y': 1, 'z': 2},
		map[byte]int{'A': 0, 'B': 1},
		[][]float64{{0.634, 0.366}, {0.387, 0.613}},
		[][]float64{{0.532, 0.226, 0.241}, {0.457, 0.192, 0.351}},
	) == "AAAAAAAAAAAAAABBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBAAA")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func decode(X string, Z, S map[byte]int, A, E [][]float64) string {
	V := alloc[float64](len(S), len(X))
	B := alloc[int](len(S), len(X))
	for k := range len(S) {
		V[k][0] = E[k][Z[X[0]]] / float64(len(S))
	}

	for i := range len(X) - 1 {
		for k := range len(S) {
			M := 0.0
			for l := range len(S) {
				N := V[l][i] * A[l][k]
				if N > M {
					B[k][i+1], M = l, N
				}
			}
			V[k][i+1] = E[k][Z[X[i+1]]] * M
		}
	}
	return backtrack(V, B, invmap(S))
}

func backtrack(V [][]float64, B [][]int, I map[int]byte) string {
	p := 0
	m := -math.MaxFloat64
	for i := range len(I) {
		if x := V[i][len(V[i])-1]; x > m {
			p, m = i, x
		}
	}

	w := new(bytes.Buffer)
	for i := len(V[0]) - 1; i >= 0; i-- {
		w.WriteByte(I[p])
		p = B[p][i]
	}

	s := w.String()
	s = rev(s)
	return s
}

func alloc[T any](w, h int) [][]T {
	m := make([][]T, w)
	for i := range m {
		m[i] = make([]T, h)
	}
	return m
}

func rev(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func invmap[K comparable, V comparable](m map[K]V) map[V]K {
	i := make(map[V]K)
	for k, v := range m {
		i[v] = k
	}
	return i
}
