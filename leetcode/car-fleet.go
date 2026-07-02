/*

There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

You are given two integer arrays position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

A car fleet is a single car or a group of cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.



Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

Output: 3

Explanation:

    The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at target.
    The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
    The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.

Example 2:

Input: target = 10, position = [3], speed = [3]

Output: 1

Explanation:
There is only one car, hence there is only one fleet.

Example 3:

Input: target = 100, position = [0,2,4], speed = [4,2,1]

Output: 1

Explanation:

    The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The car starting at 4 (speed 1) travels to 5.
    Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.



Constraints:

    n == position.length == speed.length
    1 <= n <= 10^5
    0 < target <= 10^6
    0 <= position[i] < target
    All the values of position are unique.
    0 < speed[i] <= 10^6

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	test(
		12, []int{10, 8, 0, 5, 3}, []int{2, 4, 1, 1, 3},
		3,
	)

	test(
		10, []int{3}, []int{3},
		1,
	)

	test(
		100, []int{0, 2, 4}, []int{4, 2, 1},
		1,
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(target int, position, speed []int, expected int) {
	result := carfleet(target, position, speed)
	fmt.Println(result)
	assert(result == expected)
}

func carfleet(target int, position, speed []int) int {
	var cars [][2]float64
	for i := range position {
		cars = append(cars, [2]float64{
			float64(position[i]),
			float64(target-position[i]) / float64(speed[i]),
		})
	}

	sort.Slice(cars, func(i, j int) bool {
		if cars[i][0] == cars[j][0] {
			return cars[i][1] < cars[j][1]
		}
		return cars[i][0] < cars[j][0]
	})

	result := 0
	current := 0.0
	for i := len(position) - 1; i >= 0; i-- {
		if cars[i][1] > current {
			current = cars[i][1]
			result += 1
		}
	}

	return result
}
