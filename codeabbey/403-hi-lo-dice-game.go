/*

Sandor and Juliska prefer to play games of chance. Note that "S" in both of their names is read as "SH" in English!

Today Juliska proposed modification to basic game with single die:

first player is called "banker" and throws a single die
second player bets whether the next throw will be higher or lower than the first
first player makes second throw and grabs stake or pays out money depending on whether guess was correct
Juliska argued that out of pure politeness she insists Sandor should play as a banker. And states that anyway there are two equal chances "either I guess right or not, so it is 50%".

Sandor agrees either due to his love for Juliska or due to his lack of love for the mathematical science. We surely know better and easily predict that some time later he loses most of his pocket money. Let's consider single round of the game:

Sandor casts 2 (on a normal six-sided die)
Juliska says the next number should be "higher"
if Sandor then casts 3, 4, 5 or 6 - Juliska wins (and loses if he casts 1 or 2)
Problem Statement
Supppose that N-sided die is used and K rounds of game are played, every of them with fixed stake of 1 Forint. What is expected amount of Forints to be lost by Sandor to Juliska as a result?

If you would like to know how arbitrary N-sided die may look like, consider that for 2 sides it is just like a coin while 3-sided is like a thin unsharpened pencil, triangular in cross-section and so on.

Input data contain total number of games G in the first line.
Next lines contain two values N and K each.

Answer should for each game contain "mathematical expectation" of the amount Juliska is going to win (and Sandor to lose), separate them with spaces as usual. Precision of 1e-7 should be enough.

Example

input data:
3
2 10
3 5
6 3

answer:
0.0 0.5555556 1.0

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(2, 10))
	fmt.Println(solve(3, 5))
	fmt.Println(solve(6, 3))
}

func solve(N, K int) float64 {
	sum := 0.0
	for x := 1; x <= N; x++ {
		hi := float64(N-2*x) / float64(N)
		lo := float64(2*x-N-2) / float64(N)
		sum += max(hi, lo)
	}
	return (sum * float64(K)) / float64(N)
}
