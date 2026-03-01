/*

Description

Rock, Paper, Scissors is a classic hand game for two people. Each participant holds out either a fist (rock), open hand (paper), or two-finger V (scissors). If both players show the same gesture, they try again. They continue until there are two different gestures. The winner is then determined according to the table below:

Rock	beats	Scissors
Paper	beats	Rock
Scissors	beats	Paper


Your task is to take a list of symbols representing the gestures of two players and determine how many games each player wins.
In the following example:

Turn     : 1 2 3 4 5

Player 1 : R R S R S

Player 2 : S R S P S


Player 1 wins at Turn 1 (Rock beats Scissors), Player 2 wins at Turn 4 (Paper beats Rock), and all the other turns are ties.
Input

The input contains between 1 and 20 pairs of lines, the first for Player 1 and the second for Player 2. Both player lines contain the same number of symbols from the set {'R', 'P', 'S'}. The number of symbols per line is between 1 and 75, inclusive. A pair of lines each containing the single character 'E' signifies the end of the input.
Output

For each pair of input lines, output a pair of output lines as shown in the sample output, indicating the number of games won by each player.
Sample Input

RRSRS
SRSPS
PPP
SSS
SPPSRR
PSPSRS
E
E
Sample Output

P1: 1
P2: 1
P1: 0
P2: 3
P1: 2
P2: 1
Source

Mid-Central USA 2009

*/

package main

import "fmt"

func main() {
	test("RRSRS", "SRSPS", 1, 1)
	test("PPP", "SSS", 0, 3)
	test("SPPSRR", "PSPSRS", 2, 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, t string, r1, r2 int) {
	c1, c2 := tally(s, t)
	fmt.Println(c1, c2)
	assert(c1 == r1)
	assert(c2 == r2)
}

func tally(s, t string) (int, int) {
	p := [3]int{}
	for i := 0; i < len(s) && i < len(t); i++ {
		c := score(s[i], t[i])
		p[c]++
	}
	return p[1], p[2]
}

func score(a, b byte) int {
	tab := [3][3]int{
		{0, 2, 1},
		{1, 0, 2},
		{2, 1, 0},
	}

	x := rps(a)
	y := rps(b)
	if x < 0 || y < 0 {
		return 0
	}
	return tab[x][y]
}

func rps(c byte) int {
	switch c {
	case 'R':
		return 0
	case 'P':
		return 1
	case 'S':
		return 2
	}
	return -1
}
