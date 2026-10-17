/*

2011 was a crazy year. Many people all over the world proposed on 11-11-11, married on 11-11-11, some even went through surgery only to have 11-11-11 as their child's birth date. How crazy people can be! Don't they see there is a "20" hidden? Then what to do? A very elegant solution came from ARR, a very famous and funny character - why do we need to follow Christian (or some calls it Gregorian) calendar? Why don't we start our own calendar on the day of marriage? And those who like to celebrate their marriage ceremony too frequent, why don't they declare only 1 day per year. In that fashion they can celebrate their anniversary every day. And may be one minute a year or a second or ... Uh.. getting complex.

Let's back to the title. From now, we start to have a new calendar system, "Kisu Pari Na". And wehope to update this calendar on every national contest.The purpose of this calendar is - we all will try our best to learn something new in every year. For this first year let's learn some combinatory. It reminds me of my first year in college. I faced this problem but could not solve this then. But see how easy it is:

Say you start from upper left cell and want to go to lower right cell. The only restriction is you can only move downward or rightward. How many ways are there? How to solve it? Not that difficult. You have to go two times Down and three times Right (whichever way you try) to reach the goal from the starting cell, right? So the answer is number of ways you can arrange two D (represents Down) and three R (represent Right). 2 same characters and 3 same characters, total 5 characters. So it is:

5!/(2!3!) or (D + R)!/(D!R!) = binomial(D+R, R)

Easy isn't it? Ok enough with the learning. Now back to problem, given a grid and at each cell there are some coins. Inky and Pinky are playing a game getting inspiration from the above problem. At each turn, a player chooses a non empty cell and then removes one or more coins from that cell and put them to the cell exactly right of it or exactly beneath it. A player can't divide the coins and put one part to right and others to down. Note that, for the cells at the right column the player can't move it to more right, and same for the bottom-most row. So a player can't move coins from the lower right cell. The game will finish when no moves are available and the player who moved last will win. Now inky being very modest asked Pinky to move first. Can you say if Pinky will win if both play perfectly?

Input
Input starts with an integer T (≤ 100),denoting the number of test cases.

Each case starts with a line containing two integers R C(1 ≤ R * C ≤ 50000), where R denotes the number of rows and C denotes the number of columns of the grid respectively. Each ofthe next R lines contains C space separated integers denoting the grid. These integers lie in the range [0, 10^9].

Output
For every test case, output case number followed by win if Pinky can win or lose.

Sample
Input	Output
1
2 2
1 1
1 1

Case 1: lose

Notes
Dataset is huge, use faster I/O methods.

*/

package main

func main() {
	assert(solve([][]int{
		{1, 1},
		{1, 1},
	}) == "lose")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://codeforces.com/blog/entry/44651
// https://math.stackexchange.com/questions/2216448/useless-steps-in-staircase-nim
func solve(m [][]int) string {
	r := 0
	for i := range m {
		for j := range m[i] {
			d := len(m) - i + len(m[i]) - j
			if d&1 != 0 {
				r ^= m[i][j]
			}
		}
	}
	if r != 0 {
		return "win"
	}
	return "lose"
}
