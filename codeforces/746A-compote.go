/*

Nikolay has a lemons, b apples and c pears. He decided to cook a compote. According to the recipe the fruits should be in the ratio 1: 2: 4. It means that for each lemon in the compote should be exactly 2 apples and exactly 4 pears. You can't crumble up, break up or cut these fruits into pieces. These fruits — lemons, apples and pears — should be put in the compote as whole fruits.

Your task is to determine the maximum total number of lemons, apples and pears from which Nikolay can cook the compote. It is possible that Nikolay can't use any fruits, in this case print 0.

Input
The first line contains the positive integer a (1 ≤ a ≤ 1000) — the number of lemons Nikolay has.

The second line contains the positive integer b (1 ≤ b ≤ 1000) — the number of apples Nikolay has.

The third line contains the positive integer c (1 ≤ c ≤ 1000) — the number of pears Nikolay has.

Output
Print the maximum total number of lemons, apples and pears from which Nikolay can cook the compote.

Examples
input
2
5
7
output
7

input
4
7
13
output
21

input
2
3
2
output
0

Note
In the first example Nikolay can use 1 lemon, 2 apples and 4 pears, so the answer is 1 + 2 + 4 = 7.

In the second example Nikolay can use 3 lemons, 6 apples and 12 pears, so the answer is 3 + 6 + 12 = 21.

In the third example Nikolay don't have enough pears to cook any compote, so the answer is 0.

*/

package main

func main() {
	assert(compote(2, 5, 7) == 7)
	assert(compote(4, 7, 13) == 21)
	assert(compote(2, 3, 2) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func compote(a, b, c int) int {
	for ; a > 0; a-- {
		if a*2 <= b && a*4 <= c {
			return a + a*2 + a*4
		}
	}
	return 0
}
