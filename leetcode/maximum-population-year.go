/*

You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

Return the earliest year with the maximum population.

Example 1:

Input: logs = [[1993,1999],[2000,2010]]
Output: 1993
Explanation: The maximum population is 1, and 1993 is the earliest year with this population.
Example 2:

Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
Output: 1960
Explanation:
The maximum population is 2, and it had happened in years 1960 and 1970.
The earlier year between them is 1960.


Constraints:

1 <= logs.length <= 100
1950 <= birthi < deathi <= 2050

Hint:
For each year find the number of people whose birth_i ≤ year and death_i > year.
Find the maximum value between all years.

*/

package main

import "sort"

func main() {
	assert(maxpopulation([][2]int{{1993, 1999}, {2000, 2010}}) == 1993)
	assert(maxpopulation([][2]int{{1950, 1961}, {1960, 1971}, {1970, 1981}}) == 1960)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxpopulation(logs [][2]int) int {
	count := make(map[int]int)
	for _, log := range logs {
		start := log[0]
		end := log[1]

		count[start]++
		count[end]--
	}

	var entries [][2]int
	for year, amount := range count {
		entries = append(entries, [2]int{year, amount})
	}
	sort.Slice(entries, func(i, j int) bool {
		return entries[i][0] < entries[j][0]
	})

	if len(entries) == 0 {
		return 0
	}

	year := entries[0][0]
	maxamount := entries[0][1]
	for i := 1; i < len(entries); i++ {
		entries[i][1] += entries[i-1][1]
		if entries[i][1] > maxamount {
			year = entries[i][0]
			maxamount = entries[i][1]
		}
	}
	return year
}
