/*

Description

In the game show "The Price is Right", a number of players (typically 4) compete to get on stage by guessing the price of an item. The winner is the person whose guess is the closest one not exceeding the actual price. Because of the popularity of the one-person game show "Who Wants to be a Millionaire",the American Contest Management (ACM) would like to introduce a one-person version of the "The Price is Right". In this version, each contestant is allowed G (1 <= G <= 30) guesses and L (0 <= L <= 30)lifelines. The contestant makes a number of guesses for the actual price. After each guess, the contestant is told whether it is correct, too low, or too high. If the guess is correct, the contestant wins. Otherwise,he uses up a guess. Additionally, if his guess is too high, a lifeline is also lost. The contestant loses when all his guesses are used up or if his guess is too high and he has no lifelines left. All prices are positive integers.
It turns out that for a particular pair of values for G and L, it is possible to obtain a guessing strategy such that if the price is between 1 and N (inclusive) for some N, then the player can guarantee a win.The ACM does not want every contestant to win, so it must ensure that the actual price exceeds N.At the same time, it does not want the game to be too diffcult or there will not be enough winners to attract audience. Thus, it wishes to adjust the values of G and L depending on the actual price. To help them decide the correct values of G and L, the ACM has asked you to solve the following problem.Given G and L, what is the largest value of N such that there is a strategy to win as long as the price is between 1 and N (inclusive)?

Input

The input consists of a number of cases. Each case is specified by one line containing two integers G and L, separated by one space. The end of input is specified by a line in which G = L = 0.

Output

For each case, print a line of the form:
Case c: N
where c is the case number (starting from 1) and N is the number computed.

Sample Input

3 0
3 1
10 5
7 7
0 0

Sample Output

Case 1: 3
Case 2: 6
Case 3: 847
Case 4: 127

Source

East Central North America 2002

*/

package main

func main() {
	assert(value(3, 0) == 3)
	assert(value(3, 1) == 6)
	assert(value(10, 5) == 847)
	assert(value(7, 7) == 127)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func value(G, L int) int {
	n := max(G, L)
	p := alloc(n + 1)
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			p[i][0] = i
		}
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			p[i][j] = p[i-1][j-1] + p[i-1][j] + 1
		}
	}
	return p[G][L]
}

func alloc(n int) [][]int {
	p := make([][]int, n)
	t := make([]int, n*n)
	for i := range p {
		p[i] = t[i*n : (i+1)*n]
	}
	return p
}
