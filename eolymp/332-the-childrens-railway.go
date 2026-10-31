/*

Vitek does not stop playing with cubes. His father has given him a toy railway.
Vitek places some cubes, one per wagon, and before finishing the game,
wants to rearrange the train so that the obtained word is the lexicographically smallest possible among all options.
However, since he has already played enough, he can only once detach any number of cubes from the front and, with the locomotive, move them to the end of the train.

What word will Vitek obtain?

Input
The first and only line contains the given word. The cubes have only uppercase Latin letters, and their number does not exceed 500000.

Output
The word formed by Vitek.

Examples

Input #1
CBABC

Answer #1
ABCCB

*/

package main

func main() {
	assert(solve("CBABC") == "ABCCB")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) string {
	n := len(s)
	p := make([]byte, n*2)
	copy(p, s[:])

	for i := n; i < n*2; i++ {
		p[i] = p[i-n]
	}
	n *= 2

	r := 0
	for i := 0; i < n/2; {
		r = i
		j := i + 1
		k := i
		for ; j < n && p[k] <= p[j]; j++ {
			if p[k] < p[j] {
				k = i
			} else {
				k += 1
			}
		}
		for i <= k {
			i += j - k
		}
	}
	return string(p[r : r+n/2])
}
