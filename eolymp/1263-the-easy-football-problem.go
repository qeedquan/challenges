/*

The World Cup is almost finished, and the main candidates for the best football player of the championship still cannot decide who deserves the title.

Now, they have decided to determine the winner once and for all, even refusing the help of programmer Vasya.
Everything depends on the number of goals scored over the last 3 seasons.

However, the players are proud and do not want to reveal their number of goals directly. Instead, each provides three magical numbers A, B, and C:

A is the number of goals scored in seasons 1 and 2,

B is the number of goals scored in seasons 2 and 3,

C is the number of goals scored in seasons 1 and 3.

You need to determine the winner—the player who scored more goals in the last three seasons.

Input
The first line contains three numbers: Messi_A, Messi_B, Messi_C — Lionel's magical numbers.
The second line contains three numbers: Ronaldo_A, Ronaldo_B, Ronaldo_C — Cristiano's magical numbers.
It is known that 0≤Messi_A,Messi_B,Messi_C,Ronaldo_A,Ronaldo_B,Ronaldo_C≤100.

Output
If Messi scored more goals than Ronaldo in the last three seasons, print Messi Wins.
If they scored the same number of goals, print Draw.... If Ronaldo scored more, print Ronaldo Wins.
If at least one player made a mistake, print Drogba Wins.

Examples
Input #1
3 4 5
2 5 5

Answer #1
Draw...

*/

package main

func main() {
	assert(solve(3, 4, 5, 2, 5, 5) == "Draw...")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a1, b1, c1, a2, b2, c2 int) string {
	s1 := a1 + b1 + c1
	s2 := a2 + b2 + c2
	if s1%2 == 1 || s2%2 == 1 || a1+b1-c1 < 0 || a1+c1-b1 < 0 || b1+c1-a1 < 0 || a2+b2-c2 < 0 || a2+c2-b2 < 0 || b2+c2-a2 < 0 {
		return "Drogba Wins"
	}
	if s1 == s2 {
		return "Draw..."
	}
	if s1 > s2 {
		return "Messi Wins"
	}
	return "Ronaldo Wins"
}
