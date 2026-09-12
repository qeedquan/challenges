/*

Watson and Rybka decided to play the following game. The players have N registers, each of which can store a non-negative integer. On each move, a player must select one of the registers and subtract 2 or 3 from its value. The number in the register must remain non-negative. The player who cannot make a move loses the game. Players make moves alternately.

Watson and Rybka are both very smart programs and always make moves optimally. You need to determine the winner. Rybka makes the first move.

Input
The first line contains one integer N (0≤N≤10^6). The following N lines contain Ai (0≤Ai<10^9) — the initial values in the registers.

Output
You need to print the winner's name — Watson or Rybka (without quotes).

Examples

Input #1
3
2
3
4

Answer #1
Rybka

Input #2
4
2
3
4
9

Answer #2
Watson

*/

package main

func main() {
	assert(solve([]int{2, 3, 4}) == "Rybka")
	assert(solve([]int{2, 3, 4, 9}) == "Watson")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a []int) string {
	r := 0
	for _, v := range a {
		var f int
		switch v % 5 {
		case 0, 1:
			f = 0
		case 2, 3:
			f = 1
		case 4:
			f = 2
		}
		r ^= f
	}
	if r == 0 {
		return "Watson"
	}
	return "Rybka"
}
