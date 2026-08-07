/*

There are n 1-indexed robots, each having a position on a line, health, and movement direction.

You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.

All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.

Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final health of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.

Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

Note: The positions may be unsorted.

Example 1:
https://assets.leetcode.com/uploads/2023/05/15/image-20230516011718-12.png

Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
Output: [2,17,9,15,10]
Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].

Example 2:
https://assets.leetcode.com/uploads/2023/05/15/image-20230516004433-7.png
Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
Output: [14]
Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide, and since both have the same health, they will be removed from the line. Next, robot 3 and robot 4 will collide and since robot 4's health is smaller, it gets removed, and robot 3's health becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].

Example 3:
https://assets.leetcode.com/uploads/2023/05/15/image-20230516005114-9.png
Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
Output: []
Explanation: Robot 1 and robot 2 will collide and since both have the same health, they are both removed. Robot 3 and 4 will collide and since both have the same health, they are both removed. So, we return an empty array, [].

Constraints:

1 <= positions.length == healths.length == directions.length == n <= 10^5
1 <= positions[i], healths[i] <= 10^9
directions[i] == 'L' or directions[i] == 'R'
All values in positions are distinct

Hint 1
Process the robots in the order of their positions to ensure that we process the collisions correctly.

Hint 2
To optimize the solution, use a stack to keep track of the surviving robots as we iterate through the positions.

Hint 3
Instead of simulating each collision, check the current robot against the top of the stack (if it exists) to determine if a collision occurs.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{5, 4, 3, 2, 1}, []int{2, 17, 9, 15, 10}, "RRRRR", []int{2, 17, 9, 15, 10})
	test([]int{3, 5, 2, 6}, []int{10, 10, 15, 12}, "RLRL", []int{14})
	test([]int{1, 2, 5, 6}, []int{10, 10, 11, 11}, "RLRL", []int{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(positions, healths []int, directions string, expected []int) {
	result := survivors(positions, healths, directions)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func survivors(positions, healths []int, directions string) []int {
	indices := make([]int, len(positions))
	for i := range indices {
		indices[i] = i
	}

	sort.Slice(indices, func(i, j int) bool {
		return positions[indices[i]] < positions[indices[j]]
	})

	stack := []int{}
	for _, i := range indices {
		if directions[i] == 'R' {
			stack = append(stack, i)
			continue
		}

	loop:
		for len(stack) > 0 && healths[i] > 0 {
			j := stack[len(stack)-1]
			switch {
			case healths[j] > healths[i]:
				healths[j]--
				healths[i] = 0
			case healths[j] < healths[i]:
				healths[i]--
				healths[j] = 0
				stack = stack[:len(stack)-1]
			default:
				healths[i], healths[j] = 0, 0
				stack = stack[:len(stack)-1]
				break loop
			}
		}
	}

	result := []int{}
	for _, health := range healths {
		if health > 0 {
			result = append(result, health)
		}
	}
	return result
}
