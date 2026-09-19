/*

Create 10x10 array and randomly fill each cell with 'A', 'B', 'C' or 'D' and ensure that each row contain at least one occurance of each letter. Example: [ ['A', 'A', 'B', 'C', 'B', 'D', 'A', 'C', 'C', 'D'], ['A', 'B', 'B', 'C', 'B', 'D', 'A', 'A', 'C', 'D'], ['A', 'A', 'A', 'C', 'B', 'D', 'A', 'C', 'C', 'D'], ['C', 'A', 'B', 'C', 'B', 'C', 'D', 'B', 'C', 'A'], ['A', 'A', 'B', 'D', 'B', 'B', 'A', 'C', 'B', 'A'], ['B', 'A', 'B', 'C', 'B', 'D', 'A', 'B', 'C', 'B'], ['A', 'A', 'D', 'C', 'A', 'D', 'B', 'C', 'C', 'C'], ['B', 'A', 'B', 'C', 'B', 'D', 'B', 'C', 'C', 'D'], ['D', 'A', 'B', 'C', 'B', 'D', 'A', 'C', 'C', 'D'], ['A', 'A', 'B', 'C', 'B', 'D', 'A', 'C', 'C', 'D'], ]

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	dump(gen())
}

func dump(m [10][10]byte) {
	for i := range m {
		for j := range m[i] {
			fmt.Printf("%c", m[i][j])
		}
		fmt.Println()
	}
}

func gen() [10][10]byte {
	p := []byte("ABCDABCDABCD")
	m := [10][10]byte{}
	for i := range m {
		for {
			rand.Shuffle(len(p), func(i, j int) {
				p[i], p[j] = p[j], p[i]
			})

			f := 0
			for j := range m[i] {
				f |= 1 << (p[j] - 'A')
			}
			if f == 0xf {
				break
			}
		}
		copy(m[i][:], p)
	}
	return m
}
