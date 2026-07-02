/*

This challenge initially appeared in this challenge as a an extra brain teaser. I am posting it with permission from the original author so that we can have a formal competition.

Your task here will be to implement a function1 that forms a permutation on the positive integers. This means that each positive integer should be the output of calling the function with exactly one positive integer.

In the earlier challenge we calculated the odd probability for such sequences. We defined it as so:

If we have a function f the probability of a number being odd will be defined as the limit of ratio odd members of the set to the size of the set f{1…n} as n tends towards infinity.

lim[n->oo] |{ x: x in {1 ... n}, odd(f(x)) }| / n

Your task is to write a function with no defined odd probability. That is a function f for which the above limit does not converge.

This is code-golf so answers will be scored in bytes with less bytes being better.

1: Here function will mean program or function. It is just a piece of code that takes input and produces output.

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	for i := 0; i <= 1000; i++ {
		fmt.Printf("%d ", f(i))
	}
	fmt.Println()
}

/*

@Mitchell Spector

This takes the input number and moves the 2nd digit (from the left) to the end of the number (the one's place).

The numbers from 1 to 10^n are just rearranged, so the proportion of odd numbers for inputs up to 10n is 0.5.

All the numbers from 10^n+1 to 10^n+10^n-1-1 map to even numbers, so the proportion of odd numbers for inputs up to 10^n+10^n-1 is

(10^n/2 + 1) / (10^n + 10^(n-1)) = (5 + 10^-(n-1))/11

which approaches 5/11 as n approaches infinity.

*/

func f(n int) int {
	s := fmt.Sprint(n)
	t := fmt.Sprintf("%c%s", s[0], rev(s[1:]))
	x, _ := strconv.Atoi(t)
	return x
}

func rev(s string) string {
	r := ""
	for _, c := range s {
		r = string(c) + r
	}
	return r
}
