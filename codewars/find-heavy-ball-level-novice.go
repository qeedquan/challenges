/*

There are 8 balls numbered from 0 to 7. Seven of them have the same weight. One is heavier. Your task is to find its number.

Your function findBall will receive single argument - scales object. The scales object contains an internally stored array of 8 elements (indexes 0-7), each having the same value except one, which is greater. It also has a public method named getWeight(left, right) which takes two arrays of indexes and returns -1, 0, or 1 based on the accumulation of the values found at the indexes passed are heavier, equal, or lighter.

getWeight returns:

-1 if left pan is heavier

1 if right pan is heavier

0 if both pans weight the same

Examples of scales.getWeight() usage:

scales.getWeight([3], [7]) returns -1 if ball 3 is heavier than ball 7, 1 if ball 7 is heavier, or 0 i these balls have the same weight.

scales.getWeight([3, 4], [5, 2]) returns -1 if weight of balls 3 and 4 is heavier than weight of balls 5 and 2 etc.

So where's the catch, you may ask. Well - the scales is very old. You can use it only 4 TIMES before the scale breaks.

Too easy ? Try higher levels:

conqueror
https://www.codewars.com/kata/54404a06cf36258b08000364

master
https://www.codewars.com/kata/544034f426bc6adda200000e

*/

package main

import (
	"math/rand"
)

type Scale interface {
	Weight([]int, []int) int
}

type Balls [8]int

func main() {
	for range 1000000 {
		simulate()
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func simulate() {
	var balls Balls
	weight := rand.Intn(1000)
	index := rand.Intn(len(balls))
	for i := range balls {
		balls[i] = weight
	}
	balls[index] = weight + 1 + rand.Intn(1000)

	assert(index == findball(balls))
}

func (balls Balls) Weight(left, right []int) int {
	leftsum, rightsum := 0, 0
	for _, index := range left {
		leftsum += balls[index]
	}
	for _, index := range right {
		rightsum += balls[index]
	}

	switch {
	case leftsum > rightsum:
		return -1
	case leftsum == rightsum:
		return 0
	}
	return 1
}

func findball(scale Scale) int {
	balls := []int{0, 1, 2, 3, 4, 5, 6, 7}
	current := balls
	length := 4
	for range 3 {
		left := current[:length]
		right := current[length:]
		if scale.Weight(left, right) < 0 {
			current = left
		} else {
			current = right
		}
		length /= 2
	}
	return current[0]
}
