/*

An apartment building has N apartments, divided among P entrances and Q floors.
Each floor of every entrance contains the same number of apartments.
The apartments are numbered from 1 to N.
Given an apartment numbered K, determine the entrance and the floor where it is located.

Input
The only line of input contains four integers N, P, Q, and K. The constraints are: 1≤K≤N≤1000, PQ≤N.

Output
Output two integers: the entrance number and the floor number where apartment K is located.

Examples
Input #1
30 2 5 27

Answer #1
2 4

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(30, 2, 5, 27))
}

func solve(n, p, q, k int) (int, int) {
	r0 := 1
	r1 := 1
	t := n / (p * q)
	for ; k > t*q; r0++ {
		k -= t * q
	}
	for ; k > t; r1++ {
		k -= t
	}
	return r0, r1
}
