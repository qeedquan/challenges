/*

The length of the Capital City Ring Road is 109 kilometers.
The motorcyclist Vasya starts from the zero kilometer of the Capital City Ring Road and travels at a constant speed v kilometers per hour.
At what kilometer of the Capital City Ring Road will he stop in t hours?

Input
The speed v and time t are given in separate lines.
If v>0, Vasya is moving in the positive direction along the road; if v<0, he is moving in the negative direction.

Output
Print the kilometer number (integer value from 0 to 108) where Vasya will stop.

Examples

Input #1
60
2

Answer #1
11

Input #2
-1
1

Answer #2
108

*/

package main

func main() {
	assert(solve(60, 2) == 11)
	assert(solve(-1, 1) == 108)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b int) int {
	n := a < 0
	b %= 109
	a = abs(a) % 109
	if !n {
		return (a * b) % 109
	}
	return (109 - (a*b)%109) % 109
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
