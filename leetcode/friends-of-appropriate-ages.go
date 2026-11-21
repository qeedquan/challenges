/*

There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.

A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:

    age[y] <= 0.5 * age[x] + 7
    age[y] > age[x]
    age[y] > 100 && age[x] < 100

Otherwise, x will send a friend request to y.

Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.

Return the total number of friend requests made.

Example 1:

Input: ages = [16,16]
Output: 2
Explanation: 2 people friend request each other.

Example 2:

Input: ages = [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.

Example 3:

Input: ages = [20,30,100,110,120]
Output: 3
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.

Constraints:

    n == ages.length
    1 <= n <= 2 * 10^4
    1 <= ages[i] <= 120

*/

package main

func main() {
	assert(friends([]int{16, 16}) == 2)
	assert(friends([]int{16, 17, 18}) == 2)
	assert(friends([]int{20, 30, 100, 110, 120}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func friends(ages []int) int {
	count := make(map[int]int)
	for _, age := range ages {
		count[age] += 1
	}

	result := 0
	for age1, count1 := range count {
		for age2, count2 := range count {
			if request(age1, age2) {
				result += count1 * (count2 - truth(age1 == age2))
			}
		}
	}
	return result
}

func request(age1, age2 int) bool {
	return 0.5*float64(age1)+7 < float64(age2) && age2 <= age1
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
