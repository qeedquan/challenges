/*

Background
Yes, bitstring physics is a real thing. The idea is to construct a new theory of physics using only strings of bits that evolve under a probabilistic rule... or something.
Despite reading a couple of papers about it, I'm still pretty confused. However, the bitstring universe makes for a nice little code golf.

Program Universe
Bitstring physics takes place in a so-called program universe.
At each step of the evolution of the universe, there is a finite list L of bitstrings of some length k, starting with the two-element list [10,11] where k = 2.
One timestep is processed as follows (in Python-like pseudocode).

A := random element of L
B := random element of L
if A == B:
    for each C in L:
        append a random bit to C
else:
    append the bitwise XOR of A and B to L
All random choices are uniformly random and independent of each other.

Example
An example evolution of 4 steps might look like the following. Start with the initial list L:

10
11
We randomly choose A := 10 and B := 10, which are the same row, which means we need to extend each string in L with a random bit:

101
110
Next, we choose A := 101 and B := 110, and since they are not equal, we add their XOR to L:

101
110
011
Then, we choose A := 011 and B := 110, and again append their XOR:

101
110
011
101
Finally, we choose A := 101 (last row) and B := 101 (first row), which are equal, so we extend with random bits:

1010
1100
0111
1010

The Task
Your task is to take a nonnegative integer t as input, simulate the program universe for t timesteps, and return or print the resulting list L. Note that t = 0 results in the initial list [10,11]. You can output L as a list of lists of integers, list of lists of boolean values or a list of strings; if output goes to STDOUT, you may also print the bitstrings one per line in some reasonable format. The order of the bitstrings is significant; in particular, the initial list cannot be [11,10], [01,11] or anything like that. Both functions and full programs are acceptable, standard loopholes are disallowed, and the lowest byte count wins.

*/

package main

import (
	"bytes"
	"fmt"
	"math/rand"
)

func main() {
	sim(20)
}

func sim(t int) []string {
	L := []string{"10", "11"}
	for range t {
		n := len(L)
		A := L[rand.Intn(n)]
		B := L[rand.Intn(n)]
		if A == B {
			for i := range L {
				L[i] = L[i] + fmt.Sprint(rand.Intn(2))
			}
		} else {
			L = append(L, xor(A, B))
		}
		fmt.Println(L)
	}
	return L
}

func xor(a, b string) string {
	w := new(bytes.Buffer)
	for i := range a {
		if (a[i] == '1' || b[i] == '1') && a[i] != b[i] {
			w.WriteByte('1')
		} else {
			w.WriteByte('0')
		}
	}
	return w.String()
}
