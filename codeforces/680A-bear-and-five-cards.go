/*

A little bear Limak plays a game. He has five cards. There is one number written on each card. Each number is a positive integer.

Limak can discard (throw out) some cards. His goal is to minimize the sum of numbers written on remaining (not discarded) cards.

He is allowed to at most once discard two or three cards with the same number. Of course, he won't discard cards if it's impossible to choose two or three cards with the same number.

Given five numbers written on cards, cay you find the minimum sum of numbers on remaining cards?

Input
The only line of the input contains five integers t1, t2, t3, t4 and t5 (1 ≤ ti ≤ 100) — numbers written on cards.

Output
Print the minimum possible sum of numbers written on remaining cards.

Examples

input
7 3 7 3 20
output
26

input
7 9 3 1 8
output
28

input
10 10 10 10 10
output
20

Note
In the first sample, Limak has cards with numbers 7, 3, 7, 3 and 20. Limak can do one of the following.

Do nothing and the sum would be 7 + 3 + 7 + 3 + 20 = 40.
Remove two cards with a number 7. The remaining sum would be 3 + 3 + 20 = 26.
Remove two cards with a number 3. The remaining sum would be 7 + 7 + 20 = 34.
You are asked to minimize the sum so the answer is 26.

In the second sample, it's impossible to find two or three cards with the same number. Hence, Limak does nothing and the sum is 7 + 9 + 1 + 3 + 8 = 28.

In the third sample, all cards have the same number. It's optimal to discard any three cards. The sum of two remaining numbers is 10 + 10 = 20.

*/

package main

func main() {
	assert(cardsum([5]int{7, 3, 7, 3, 20}) == 26)
	assert(cardsum([5]int{7, 9, 3, 1, 8}) == 28)
	assert(cardsum([5]int{10, 10, 10, 10, 10}) == 20)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cardsum(a [5]int) int {
	m := make(map[int]int)
	x := 0
	for _, v := range a {
		x, m[v] = x+v, m[v]+1
	}

	r := x
	for k, v := range m {
		if v > 2 {
			r = min(r, x-3*k)
		}
		if v > 1 {
			r = min(r, x-2*k)
		}
	}
	return r
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
