/*

You are given a 2D integer array items where items[i] = [pricei, weighti] denotes the price and weight of the ith item, respectively.

You are also given a positive integer capacity.

Each item can be divided into two items with ratios part1 and part2, where part1 + part2 == 1.

The weight of the first item is weighti * part1 and the price of the first item is pricei * part1.
Similarly, the weight of the second item is weighti * part2 and the price of the second item is pricei * part2.
Return the maximum total price to fill a bag of capacity capacity with given items.
If it is impossible to fill a bag return -1. Answers within 10-5 of the actual answer will be considered accepted.

Example 1:

Input: items = [[50,1],[10,8]], capacity = 5
Output: 55.00000
Explanation:
We divide the 2nd item into two parts with part1 = 0.5 and part2 = 0.5.
The price and weight of the 1st item are 5, 4. And similarly, the price and the weight of the 2nd item are 5, 4.
The array items after operation becomes [[50,1],[5,4],[5,4]].
To fill a bag with capacity 5 we take the 1st element with a price of 50 and the 2nd element with a price of 5.
It can be proved that 55.0 is the maximum total price that we can achieve.

Example 2:

Input: items = [[100,30]], capacity = 50
Output: -1.00000
Explanation: It is impossible to fill a bag with the given item.

Constraints:

1 <= items.length <= 10^5
items[i].length == 2
1 <= pricei, weighti <= 10^4
1 <= capacity <= 10^9

*/

package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	test([][2]int{{50, 1}, {10, 8}}, 5, 55)
	test([][2]int{{100, 30}}, 50, -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(items [][2]int, capacity int, expected float64) {
	result := maxprice(items, capacity)
	fmt.Println(result)
	assert(math.Abs(result-expected) < 1e-12)
}

func maxprice(items [][2]int, capacity int) float64 {
	sort.Slice(items, func(i, j int) bool {
		return items[i][0]*items[j][1] > items[i][1]*items[j][0]
	})

	result := 0.0
	for _, item := range items {
		value := min(item[1], capacity)
		capacity -= value
		ratio := float64(item[0]) / float64(item[1])
		result += ratio * float64(value)
	}

	if capacity != 0 {
		return -1
	}
	return result
}
