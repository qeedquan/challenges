/*

A well-known provider of content services for mobile phones decided to earn a large sum of money once again. The organizers launched a major promotion called TV for 5 credits. Any participant could send an SMS to the short number 2009, containing a single integer—the amount they are willing to pay (in credits) for the TV. The TV will be given to the participant who submits the lowest unique bid (that is, a bid amount that no other participant offers). If there are no special bids (i.e., no unique bids), the TV remains with the organizers. Please note that sending an SMS is charged!

Given the bids of all participants, write a program to determine the number of the participant who wins the TV.

Input
The first line contains a natural number N (1≤N≤10^6)—the number of participants.

The second line contains N natural numbers, each not exceeding 30000—the bids of the participants, in the order they were received.

Output
Output a single integer—the number (1-indexed) of the participant who won the TV, or 0 if there is no winner.

Examples
Input #1
6
3 9 1 2 1 3

Answer #1
4

*/

package main

import (
	"math"
)

func main() {
	assert(solve([]int{3, 9, 1, 2, 1, 3}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(numbers []int) int {
	count := make(map[int]int)
	for _, number := range numbers {
		count[number] += 1
	}

	minimum := math.MaxInt
	position := 0
	for index, number := range numbers {
		if count[number] == 1 && (position == 0 || minimum > number) {
			position = index + 1
			minimum = number
		}
	}
	return position
}
