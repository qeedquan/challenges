/*

The fraction 1/41, when written as a decimal, is 0.024390243902439024390243902439... It is fairly clear that the decimal representation never terminates. In this problem we are going to be concerned with finding the digit in a given position within the decimal fraction. We will number the positions from 1, starting immediately after the decimal point. For example, the digit in position 3 of the fraction 1/41 is 4. Similarly the digits in positions 10, 13 and 29 are 9, 4 and 3 respectively.

The fraction 1/8, when written in decimal, is 0.125. In this example the digits at positions 1 and 3 are 1 and 5 respectively. This fraction terminates at position 3 so the digits at positions 4, 5, 6 and so on are all 0.

You will be given a number of fractions. For each fraction you will be given a position. You need to find the digit which appears at this position in the decimal representation of the fraction. The denominators of the fractions and the positions of the required digits will not exceed 10^18.

Input/Output description: The first line of the input data will contain a single integer N, the number of fractions. N lines will follow. Each line contains a fraction (1/X) followed by the target position. Find the digit at the target position in the decimal representation of the fraction. Combine all answers into a single string, separated by spaces.

Example:

input:
5
1/41 29
1/59 92
1/757 974
1/5737 6998
1/74653 54325

answer:
3 5 0 7 7

*/

package main

import (
	"math/big"
)

func main() {
	assert(solve("1/41", 29) == 3)
	assert(solve("1/59", 92) == 5)
	assert(solve("1/757", 974) == 0)
	assert(solve("1/5737", 6998) == 7)
	assert(solve("1/74653", 54325) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(fraction string, position int) int {
	if position < 1 {
		return -1
	}
	number := new(big.Rat)
	number.SetString(fraction)
	result := number.FloatString(position * 2)
	return int(result[position+1] - '0')
}
