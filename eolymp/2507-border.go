/*

In international politics, an important concept is the border between states.
Uncertainty in determining where the border lies can lead to international conflicts and even wars.

In this problem, the situation is simpler, since both states know exactly which territory belongs to each of them.

The area occupied by the two states forms a rectangle of size h×w kilometers, divided into squares with a side of 1 kilometer.
Each square fully belongs to one of the states.

Find the length of the border between the two states.
A side of a square is considered part of the border if one of its sides belongs to one state and the other side belongs to the other state.

Input
The first line contains two integers w and h (1≤w,h≤100) — the width and height of the rectangle in kilometers.
The following h lines describe the territory. Each line contains w characters: if a character is A, the corresponding unit square belongs to the first state;
if B, it belongs to the second state. It is guaranteed that each state has at least one square.

The territory of each state forms a connected area.

Output
Print one number — the length of the border between the states in kilometers.

https://eolympusercontent.com/images/h57fb54aet22vad0clfoud8bp8

Examples

Input #1
5 6
AAABB
ABBBB
AAABB
AAAAB
AAAAB
AABBB

Answer #1
13

*/

package main

func main() {
	assert(solve([][]byte{
		[]byte("AAABB"),
		[]byte("ABBBB"),
		[]byte("AAABB"),
		[]byte("AAAAB"),
		[]byte("AAAAB"),
		[]byte("AABBB"),
	}) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(p [][]byte) int {
	r := 0
	for i := range p {
		for j := range p[i] {
			if p[i][j] == 'A' {
				r += contact(p, i, j)
			}
		}
	}
	return r
}

func contact(p [][]byte, a, b int) int {
	dirx := [4]int{0, 1, 0, -1}
	diry := [4]int{1, 0, -1, 0}

	r := 0
	for i := range 4 {
		x := a + dirx[i]
		y := b + diry[i]
		if 0 <= x && x < len(p) && 0 <= y && y < len(p[x]) && p[x][y] == 'B' {
			r++
		}
	}
	return r
}
