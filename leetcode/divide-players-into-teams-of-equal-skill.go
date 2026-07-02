/*

You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player.
Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

Example 1:

Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation:
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.

Example 2:

Input: skill = [3,4]
Output: 12
Explanation:
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.

Example 3:

Input: skill = [1,1,2,3]
Output: -1
Explanation:
There is no way to divide the players into teams such that the total skill of each team is equal.

Constraints:

2 <= skill.length <= 10^5
skill.length is even.
1 <= skill[i] <= 1000

Hint 1
Try sorting the skill array.

Hint 2
It is always optimal to pair the weakest available player with the strongest available player.

*/

package main

func main() {
	assert(divide([]int{3, 2, 5, 1, 3, 4}) == 22)
	assert(divide([]int{3, 4}) == 12)
	assert(divide([]int{1, 1, 2, 3}) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func divide(skills []int) int {
	count := make(map[int]int)
	target := 0
	for _, skill := range skills {
		target += skill
		count[skill] += 1
	}
	target = (2 * target) / len(skills)

	result := 0
	for key, value := range count {
		_, found := count[target-key]
		if !found || count[target-key] != count[key] {
			return -1
		}
		result += key * (target - key) * value
	}
	return result / 2
}
