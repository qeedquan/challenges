/*

You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.

Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]

Constraints:

n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.

Hint 1
If you want to move a ball from box i to box j, you'll need abs(i-j) moves.

Hint 2
To move all balls to some box, you can move them one by one.


Hint 3
For each box i, iterate on each ball in a box j, and add abs(i-j) to answers[i].

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		"110",
		[]int{1, 1, 3},
	)

	test(
		"001011",
		[]int{11, 8, 5, 4, 3, 4},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(boxes string, expected []int) {
	result := minimal(boxes)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func minimal(boxes string) []int {
	result := make([]int, len(boxes))
	count(result, boxes, 0, len(boxes), 1)
	count(result, boxes, len(boxes)-1, -1, -1)
	return result
}

func count(result []int, boxes string, start, end, step int) {
	index, ops, balls := start, 0, 0
	for {
		result[index] += ops
		if boxes[index] == '1' {
			balls += 1
		}
		ops += balls

		if index += step; index == end {
			break
		}
	}
}
