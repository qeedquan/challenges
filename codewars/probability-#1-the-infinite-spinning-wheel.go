/*

Story
You want to play a spinning wheel with your friend. Unfortunately, you have used all of your money to buy things that are more useful than a spinning wheel. So you have to create the rule and the spinning wheel yourself.

Task
Your spinning wheel consists of sections which could be either "Win" or "Not Win". If you get "Win", you win right away. But If you get "Not Win", it's now your friend's turn to spin the wheel. This goes on forever until someone wins. You will be given a string which each character represent a section of the wheel. (Imagine getting that string up into the real world, and wrap it around a spinning wheel. The first character of the string is connected with the last character.) the "Win" section is transform to 'W' and the "Not Win" section is transform to 'N'. Find the probability of you winning the game if you go first in percentage, rounding down.

Example
Ex.1
Given a string "WWWWWW", all of the section is "Win". If you go first, you will always win. So in this example, you have to return 100 for 100% winning probability.

Ex.2
Given a string "NNN", all of the section is "Not Win". In this scenario, no one will ever win. So your probability of winning is 0%. So you have to return 0.

Ex.3
If you calculate the probability and get 31.6%, you have to return 31 because .6% gets round down.

Extra
>The probability can never be more than 100% or less than 0%.
>The string will only consists of 'W' or 'N'.
Note about rounding
For any valid input string there exists one and only one correct integer answer. Hint: it is possible to solve this problem without floating-point arithmetic.

*/

package main

import (
	"fmt"
	"math"
	"math/rand"
)

func main() {
	test("WWWWW", 100)
	test("NNN", 0)
	test("NWN", 60)
	test("WWN", 75)
	test("WWWWWWWWWN", 90)
	test("NNNWNNNNNW", 55)
	test("NNNNNNNNNNNWWW", 56)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r float64) {
	p := solve(s)
	fmt.Println(s, p)
	assert(math.Abs(p-r) < 1)
}

/*

The probability of winning one game is:

P = Number of Ws in the string / String length

The probability of not winning on one game is:
Q = 1 - P

We want to calculate the probability over an infinite play time so we have the following infinite sum:

Use the probability rule of OR
Pr(wining on any one game) = Pr(win on game one) + Pr(win on two game) + Pr(win on game three) + ...

Since the game takes turns between players, the probability of winning is 0 on even games such as two/four/six/etc since player 1 is not playing.

So we just need to calculate the probability of winning on odd games:

Probability of winning three game is (using probability rule of AND):
Pr(not win on game one) * Pr(other player not win on game two) * Pr(win on game three) = Q*Q * P

The pattern continues for more games and this leads to the following infinite sum:

Sum[i=0, oo] P * Q^(2*i)

Since we are rounding, we can cut off the sum after 2^i gets too big.

*/

func solve(s string) float64 {
	r := 0.0
	p := prob(s)
	for i := range 60 {
		r += p * math.Pow(1-p, 2*float64(i))
	}
	return r * 100
}

func solvesim(s string) float64 {
	const N = 50_000_000

	p := prob(s)
	if p == 0 {
		return 0
	}
	if p == 1 {
		return 100
	}

	w := 0.0
	for range N {
		if play(p) == 0 {
			w += 1
		}
	}
	return w / N * 100
}

func prob(s string) float64 {
	c := 0.0
	for _, r := range s {
		if r == 'W' {
			c++
		}
	}

	if len(s) == 0 {
		return 0
	}
	return c / float64(len(s))
}

func play(p float64) int {
	for i := 0; ; i ^= 1 {
		if rand.Float64() <= p {
			return i
		}
	}
}
