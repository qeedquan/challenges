/*

Description

The Association of Chess Monsters (ACM) is planning their annual team match up against the rest of the world. The match will be on 30 boards, with 15 players playing white and 15 players playing black. ACM has many players to choose from, and they try to pick the best team they can. The ability of each player for playing white is measured on a scale from 1 to 100 and the same for playing black. During the match a player can play white or black but not both. The value of a team is the total of players' abilities to play white for players designated to play white and players' abilities to play black for players designated to play black. ACM wants to pick up a team with the highest total value.

Input

Input consists of a sequence of lines giving players' abilities. Each line gives the abilities of a single player by two integer numbers separated by a single space. The first number is the player's ability to play white and the second is the player's ability to play black. There will be no less than 30 and no more than 1000 lines on input.

Output

Output a single line containing an integer number giving the value of the best chess team that ACM can assemble.

Sample Input

87 84
66 78
86 94
93 87
72 100
78 63
60 91
77 64
77 91
87 73
69 62
80 68
81 83
74 63
86 68
53 80
59 73
68 70
57 94
93 62
74 80
70 72
88 85
75 99
71 66
77 64
81 92
74 57
71 63
82 97
76 56

Sample Output

2506

Source

The UofA Local 1999.10.16


*/

package main

import "math"

func main() {
	assert(elites([][2]int{
		{87, 84},
		{66, 78},
		{86, 94},
		{93, 87},
		{72, 100},
		{78, 63},
		{60, 91},
		{77, 64},
		{77, 91},
		{87, 73},
		{69, 62},
		{80, 68},
		{81, 83},
		{74, 63},
		{86, 68},
		{53, 80},
		{59, 73},
		{68, 70},
		{57, 94},
		{93, 62},
		{74, 80},
		{70, 72},
		{88, 85},
		{75, 99},
		{71, 66},
		{77, 64},
		{81, 92},
		{74, 57},
		{71, 63},
		{82, 97},
		{76, 56},
	}) == 2506)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func elites(a [][2]int) int {
	m := 16
	n := len(a)
	if n == 0 {
		return 0
	}

	p := make([][][]int, n)
	for i := range p {
		p[i] = make([][]int, m)
		for j := range p[i] {
			p[i][j] = make([]int, m)
		}
	}

	p[0][1][0] = a[0][0]
	p[0][0][1] = a[0][1]
	for i := 1; i < n; i++ {
		for j := 0; j < m; j++ {
			for k := 0; k < m; k++ {
				if j != 0 {
					p[i][j][k] = max(p[i][j][k], p[i-1][j][k], p[i-1][j-1][k]+a[i][0])
				}
				if k != 0 {
					p[i][j][k] = max(p[i][j][k], p[i-1][j][k], p[i-1][j][k-1]+a[i][1])
				}
			}
		}
	}

	return p[n-1][m-1][m-1]
}

func max(x ...int) int {
	r := math.MinInt
	for _, v := range x {
		if r < v {
			r = v
		}
	}
	return r
}
