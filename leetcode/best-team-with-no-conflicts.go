/*

You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.

Example 1:

Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.

Example 2:

Input: scores = [4,5,6,5], ages = [2,1,2,1]
Output: 16
Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.

Example 3:

Input: scores = [1,2,3,5], ages = [8,9,10,1]
Output: 6
Explanation: It is best to choose the first 3 players.

Constraints:

1 <= scores.length, ages.length <= 1000
scores.length == ages.length
1 <= scores[i] <= 10^6
1 <= ages[i] <= 1000

Hint 1
First, sort players by age and break ties by their score. You can now consider the players from left to right.

Hint 2
If you choose to include a player, you must only choose players with at least that score later on.

*/

package main

import (
	"slices"
	"sort"
)

func main() {
	assert(score([]int{1, 3, 5, 10, 15}, []int{1, 2, 3, 4, 5}) == 34)
	assert(score([]int{4, 5, 6, 5}, []int{2, 1, 2, 1}) == 16)
	assert(score([]int{1, 2, 3, 5}, []int{8, 9, 10, 1}) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func score(s, a []int) int {
	n := len(a)
	p := make([][2]int, n)
	for i := range a {
		p[i] = [2]int{s[i], a[i]}
	}

	sort.Slice(p, func(i, j int) bool {
		return p[i][0] < p[j][0] || p[i][0] == p[j][0] && p[i][1] < p[j][1]
	})

	f := make([]int, n)
	for i := range p {
		for j := 0; j < i; j++ {
			if p[i][1] >= p[j][1] {
				f[i] = max(f[i], f[j])
			}
		}
		f[i] += p[i][0]
	}
	return slices.Max(f)
}
