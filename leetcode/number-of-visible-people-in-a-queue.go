/*

There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order.
You are given an array heights of distinct integers where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in between is shorter than both of them.
More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.

Example 1:
https://assets.leetcode.com/uploads/2021/05/29/queue-plane.jpg
Input: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.

Example 2:

Input: heights = [5,1,2,3,10]
Output: [4,1,1,1,0]

Constraints:

n == heights.length
1 <= n <= 10^5
1 <= heights[i] <= 10^5
All the values of heights are unique.

Hint 1
How to solve this problem in quadratic complexity ?

Hint 2
For every subarray start at index i, keep finding new maximum values until a value larger than arr[i] is found.

Hint 3
Since the limits are high, you need a linear solution.

Hint 4
Use a stack to keep the values of the array sorted as you iterate the array from the end to the start.

Hint 5
Keep popping from the stack the elements in sorted order until a value larger than arr[i] is found, these are the ones that person i can see.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		[]int{10, 6, 8, 5, 11, 9},
		[]int{3, 1, 2, 1, 1, 0},
	)

	test(
		[]int{5, 1, 2, 3, 10},
		[]int{4, 1, 1, 1, 0},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(heights, expected []int) {
	result := seeable(heights)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func seeable(heights []int) []int {
	result := make([]int, len(heights))
	stack := Stack{}
	for index, height := range heights {
		for len(stack) > 0 && heights[stack.back()] < height {
			result[stack.pop()] += 1
		}
		if len(stack) > 0 {
			result[stack.back()] += 1
		}
		if len(stack) > 0 && heights[stack.back()] == height {
			stack.pop()
		}
		stack = append(stack, index)
	}
	return result
}

type Stack []int

func (stack Stack) back() int {
	return stack[len(stack)-1]
}

func (stack *Stack) pop() int {
	value := stack.back()
	*stack = (*stack)[:len(*stack)-1]
	return value
}
