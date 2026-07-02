/*

The national teams of Ukraine and Potokolandia played two football matches against each other. One match took place in Ukraine, and the other in Potokolandia.

In the match held in Ukraine, Ukraine scored a goals, while Potokolandia scored b goals. In the match held in Potokolandia, Potokolandia scored c goals, and Ukraine scored d goals.

The winner of the matches is determined by the following criteria:

The team with the higher total number of goals across both matches wins.

If both teams have the same total number of goals, the team with more "away" goals, i.e., goals scored in the opponent's country, wins.

If neither team can be declared the winner based on the above criteria, the result is a draw.

Please determine which team wins.

Input
The first line contains two integers a and b (0≤a,b≤100) — the number of goals scored by Ukraine and Potokolandia, respectively, in the match played in Ukraine.

The second line contains two integers c and d (0≤c,d≤100) — the number of goals scored by Potokolandia and Ukraine, respectively, in the match played in Potokolandia.

Output
Output «U» if Ukraine wins, «P» if Potokolandia wins, or «T» if the result is a draw.

Examples

Input #1
3 2
2 4

Answer #1
U

Input #2
2 1
1 0

Answer #2
P

Input #3
2 0
2 0

Answer #3
T

Note
In the first example, Ukraine scored a total of 7 goals, while Potokolandia scored 4, so Ukraine wins.
In the second example, both teams scored a total of 2 goals, but Potokolandia scored one "away" goal, thus they win.

*/

package main

func main() {
	assert(solve(3, 2, 2, 4) == 'U')
	assert(solve(2, 1, 1, 0) == 'P')
	assert(solve(2, 0, 2, 0) == 'T')
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b, c, d int) rune {
	if a+d != b+c {
		if a+d > b+c {
			return 'U'
		}
		return 'P'
	}
	if b != d {
		if d > b {
			return 'U'
		}
		return 'P'
	}
	return 'T'
}
