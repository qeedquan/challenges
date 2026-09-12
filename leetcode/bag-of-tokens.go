/*

You have an initial power of power, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).

Your goal is to maximize your total score by potentially playing each token in one of two ways:

If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
Each token may be played at most once and in any order. You do not have to play all the tokens.

Return the largest possible score you can achieve after playing any number of tokens.

Example 1:

Input: tokens = [100], power = 50
Output: 0
Explanation: Playing the only token in the bag is impossible because you either have too little power or too little score.

Example 2:

Input: tokens = [100,200], power = 150
Output: 1
Explanation: Play the 0th token (100) face up, your power becomes 50 and score becomes 1.
There is no need to play the 1st token since you cannot play it face up to add to your score.

Example 3:

Input: tokens = [100,200,300,400], power = 200
Output: 2
Explanation: Play the tokens in this order to get a score of 2:
1. Play the 0th token (100) face up, your power becomes 100 and score becomes 1.
2. Play the 3rd token (400) face down, your power becomes 500 and score becomes 0.
3. Play the 1st token (200) face up, your power becomes 300 and score becomes 1.
4. Play the 2nd token (300) face up, your power becomes 0 and score becomes 2.


Constraints:

0 <= tokens.length <= 1000
0 <= tokens[i], power < 10^4

*/

package main

import (
	"sort"
)

func main() {
	assert(score([]int{100}, 50) == 0)
	assert(score([]int{100, 200}, 150) == 1)
	assert(score([]int{100, 200, 300, 400}, 200) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func score(t []int, p int) int {
	sort.Ints(t)
	r, s, i, j := 0, 0, 0, len(t)-1
	for i <= j && (p >= t[i] || s != 0) {
		for i <= j && p >= t[i] {
			p, i, s = p-t[i], i+1, s+1
		}
		r = max(r, s)
		if i <= j && s != 0 {
			p, j, s = p+t[j], j-1, s-1
		}
	}
	return r
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
