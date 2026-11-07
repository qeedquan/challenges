/*

Given two numbers, a and b, your task is to compute the value of x=(36×a + ⌊b/16⌋) mod 32 using only bitwise operations, addition, and subtraction.

Input
The input consists of two integers separated by a space, where 0≤a,b≤10^6.

Output
The output should be a single integer representing the value of x = (36×a + ⌊b/16⌋) mod 32.

Examples

Input #1
265205 9806425

Answer #1
25

*/

package main

func main() {
	assert(solve(265205, 9806425) == 25)
	for a := range uint(10000) {
		for b := range uint(10000) {
			assert(solve(a, b) == solvebf(a, b))
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b uint) uint {
	return (a<<5 + a<<2 + b>>4) & 0x1f
}

func solvebf(a, b uint) uint {
	return (36*a + b/16) % 32
}
