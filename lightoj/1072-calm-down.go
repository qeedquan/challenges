/*

George B. wants to be more than just a good American. He wants to make his daddy proud and become a hero. You know, like Shakib Khan.

But sneaky as he is, he wants a special revolver that will allow him to shoot more often than just the usual six times. This way he can fool and kill the enemy easily (at least that's what he thinks, and that's the best he can think). George has kidnapped . . . uh, I mean . . ."invited" you and will only let you go if you help him with the math. The piece of the revolver that contains the bullets looks like this (examples for 6 and 17 bullets):

https://static.lightoj.com/images/problem-1072/1604094534205.png?style=centerme,haveborder

There is a large circle with radius R and n little circles each having radius r, are placed inside on the border of the large circle. George wants his bullets to be as large as possible, so there should be no space between the circles. George will decide how large the whole revolver will be and how many bullets it shall contain. Your job is, given R and n, to compute r. You have decided to help, because you know that he can't make a revolver even if you help him with the math.

Input
Input starts with an integer T (≤ 125), denoting the number of test cases.

Each case contains a real number R (0 < R < 1000) and contains up to at most two places after the decimal point and an integer n (2 ≤ n ≤ 100).

Output
For each test case, print the case number and r in a single line. Errors less than 10-6 will be ignored.

Sample
Input	Output
4
4.0 6
4.0 17
3.14 100
42 2

Case 1: 1.3333333333
Case 2: 0.6209067545
Case 3: 0.0956260953
Case 4: 21

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(4, 6))
	fmt.Println(solve(4, 17))
	fmt.Println(solve(3.14, 100))
	fmt.Println(solve(42, 2))
}

func solve(r, n float64) float64 {
	a := math.Pi / n
	s := math.Sin(a)
	return r * s / (1 + s)
}
