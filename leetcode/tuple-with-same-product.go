/*

Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d
where a, b, c, and d are elements of nums, and a != b != c != d.

Example 1:

Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
Example 2:

Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 10^4
All elements in nums are distinct.

Hint 1
Note that all of the integers are distinct. This means that each time a product is formed it must be formed by two unique integers.

Hint 2
Count the frequency of each product of 2 distinct numbers. Then calculate the permutations formed.

*/

package main

func main() {
	assert(tsp([]int{2, 3, 4, 6}) == 8)
	assert(tsp([]int{1, 2, 4, 5, 10}) == 16)
	assert(tsp([]int{2, 3, 4, 6, 8, 12}) == 40)
	assert(tsp([]int{2, 3, 5, 7}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tsp(a []int) int {
	m := make(map[int]int)
	n := len(a)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			m[a[i]*a[j]]++
		}
	}

	r := 0
	for _, c := range m {
		if c > 1 {
			r += 4 * c * (c - 1)
		}
	}
	return r
}
