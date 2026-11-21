/*

The bitwise AND of an array nums is the bitwise AND of all integers in nums.

For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
Also, for nums = [7], the bitwise AND is 7.
You are given an array of positive integers candidates. Compute the bitwise AND for all possible combinations of elements in the candidates array.

Return the size of the largest combination of candidates with a bitwise AND greater than 0.

Example 1:

Input: candidates = [16,17,71,62,12,24,14]
Output: 4
Explanation: The combination [16,17,62,24] has a bitwise AND of 16 & 17 & 62 & 24 = 16 > 0.
The size of the combination is 4.
It can be shown that no combination with a size greater than 4 has a bitwise AND greater than 0.
Note that more than one combination may have the largest size.
For example, the combination [62,12,24,14] has a bitwise AND of 62 & 12 & 24 & 14 = 8 > 0.

Example 2:

Input: candidates = [8,8]
Output: 2
Explanation: The largest combination [8,8] has a bitwise AND of 8 & 8 = 8 > 0.
The size of the combination is 2, so we return 2.

Constraints:

1 <= candidates.length <= 10^5
1 <= candidates[i] <= 10^7

Hint 1
For the bitwise AND to be greater than zero, at least one bit should be 1 for every number in the combination.

Hint 2
The candidates are 24 bits long, so for every bit position, we can calculate the size of the largest combination such that the bitwise AND will have a 1 at that bit position.

*/

package main

import "slices"

func main() {
	assert(combo([]int{16, 17, 71, 62, 12, 24, 14}) == 4)
	assert(combo([]int{8, 8}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func combo(a []int) int {
	c := []int{}
	m := slices.Max(a)
	for b := 1; b <= m; b <<= 1 {
		c = append(c, 0)
		for _, x := range a {
			if x&b != 0 {
				c[len(c)-1] += 1
			}
		}
	}
	return slices.Max(c)
}
