/*

Your program must take integers S≥0 and n≥1 as input and output a list of n integers  (ai)[i=1, i=n] such that
−1≤a1≤a2≤⋯≤an and  S=Sum[i=1, n] binomial(a[i]+i, a[i]).
By convention, the binomial coefficient binomial(m, −1) = 0 for all m.

Standard loopholes are forbidden. As this is code-golf, shortest program wins.

Testcases
n = 1; S = 0 -> [-1]
n = 1; S = 100 -> [99]
n = 2; S = 10 -> [-1, 3]
n = 3; S = 0 -> [-1, -1, -1]
n = 3; S = 1 -> [-1, -1, 0]
n = 5; S = 5 -> [0, 0, 0, 0, 0]
n = 7; S = 10000 -> [-1, 3, 3, 4, 6, 8, 8]

Notes
This challenge is inspired the PS1 game vib-ribbon, which shows the player's score using n=7 symbols in Pascal-ary (using shapes instead of numbers).

I chose the name "Pascal-ary" since the value in the sum for a number in each position in the list can
be found by reading a diagonal of Pascal's triangle (named after the same mathematician as the language Pascal).

As a bonus challenge, you can prove that there is only one valid output for any input.

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	test(1, 0, []int{-1})
	test(1, 100, []int{99})
	test(2, 10, []int{-1, 3})
	test(3, 0, []int{-1, -1, -1})
	test(3, 1, []int{-1, -1, 0})
	test(5, 5, []int{0, 0, 0, 0, 0})
	test(7, 10000, []int{-1, 3, 3, 4, 6, 8, 8})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(terms, sum int, expected []int) {
	result := generate(terms, sum)
	fmt.Println(result)
	assert(slices.Equal(result, expected))
}

/*

@tsh

A simple greedy solution. I have no idea why greedy algorithm works, but whatever, it passas all testcases.

@TBW
Yes, this is the fact that I did not reveal in the problem,
but I guess it makes sense that it would be one of the first things someone would guess.

*/

func generate(terms, sum int) []int {
	result := []int{}
	remaining := sum
	for index := 1; index <= terms; index++ {
		diagonal := 1
		previous := 0
		answer := 1
		for diagonal <= remaining {
			previous = diagonal
			diagonal = diagonal * (terms + 1 - index + answer) / answer
			answer += 1
		}
		result = append(result, answer-2)
		remaining -= previous
	}
	slices.Reverse(result)
	return result
}
