/*

Introduction
A common puzzle involves a triangular board with 15 holes for tees/pegs as shown in the image below:

https://i.sstatic.net/xiTFW.jpg

Starting with all the pegs in the board except for a hole at the top, the point of the puzzle is to jump pegs over one another like checkers in such a way to leave exactly one peg left. The only valid move is to jump one peg over an adjacent peg in any direction into an empty hole. The peg that was jumped is then removed from the board. Play finishes when there remain no valid moves.

Spec
Your job is to write a program that can find a complete solution to the peg puzzle, i.e., one that leaves exactly one peg left. There are multiple possible solutions, so your program just needs to print one.

Your program will receive no input. You are not allowed to read data from any outside source.
Print out the list of 13 moves that gives a result of 1 peg remaining using this format:
Peg 1 jumps Peg 3 to Hole 6.

The holes/pegs are numbered from top to bottom, left to right, so that the top peg/hole is 1, numbering until the bottom-right is 15.
Your program must find the solution at runtime. Printing out a solution directly by any means other than solving it in the program is an automatic disqualification.
Bonus: receive 10 bonus points if you can output multiple unique solutions (can just print separated by blank lines).
Bonus: receive 5 bonus points if the number 15 appears nowhere in your source code.

Scoring
This is code-golf, so the shortest solution (by byte count) that prints out a correct answer will be the winner.
Bonus points are subtracted from your total byte count.
Please provide a sample output of running your program as well as a link to ideone or some similar site if possible demonstrating the execution of your program.

*/

package main

import "fmt"

func main() {
	fmt.Printf("\n%d solutions found\n", solve())
}

/*

ported from @breadbox solution

Prints out all 29760 solutions
f, o, and t are the list of legal jumps initialized in the first loop. r and i form the history that the program uses to backtrack and explore all possible games.

*/

func solve() int {
	const sym1 = "AABBCCDDDEEFFGHKLM"
	const sym2 = "DFGIHJKMFLNMOIJMNO"

	var (
		f [37]int
		o [36]int
		t [36]int
		r [14]int
		i [14]int
		c = 0
		s = -3
	)

	for j := range 18 {
		f[j] = int(sym1[j]) - 64
		t[j] = int(sym2[j]) - 64
		o[j] = (f[j] + t[j]) >> 1

		t[18+j] = f[j]
		f[18+j] = t[j]
		o[18+j] = o[j]
	}

	for m, j := 1, 0; m != 0; j++ {
		if f[j] == 0 {
			m -= 1
			s = r[m]
			j = i[m]
		} else if (s>>f[j])&(s>>o[j])&(^s>>t[j])&1 != 0 {
			r[m] = s
			i[m] = j
			s ^= (1 << f[j]) | (1 << o[j]) | (1 << t[j])
			j = -1
			if m++; m > 13 {
				c += 1
				fmt.Printf("\n")
				for m = 1; m < 14; m++ {
					fmt.Printf("Peg %d jumps Peg %d to Hole %d.\n", f[i[m]], o[i[m]], t[i[m]])
				}
			}
		}
	}
	return c
}
