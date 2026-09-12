/*

The pupil of the first class additionally obtains a glass of milk and a pie if his weight is less than 30 kilograms.
In the first class n pupils are studying. The volume of the glass of milk is 200 ml, and the volume of the package of milk is 0.9 liters.
Find the number of additional packages of milk and pies needed every day.

Input
The first line contains the integer n (0<n≤100). The next line contains n space-separated positive real numbers – the weight of each first-grader.

Output
Print two integers in one line - the number of additional packages of milk and pies needed every day.

Examples

Input #1
8
30 27 31 25 32 29 25 30

Answer #1
1 4

Input #6
30
21.5 36 30 35 22.5 39 45 20.7 38 35 20 24 36 23 20.9 22 21 30 38 33 30 37 31.6 25 32 29 35.8 40 28.9 25

Answer #6
3 13

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve([]float64{30, 27, 31, 25, 32, 29, 25, 30}))
	fmt.Println(solve([]float64{21.5, 36, 30, 35, 22.5, 39, 45, 20.7, 38, 35, 20, 24, 36, 23, 20.9, 22, 21, 30, 38, 33, 30, 37, 31.6, 25, 32, 29, 35.8, 40, 28.9, 25}))
}

func solve(a []float64) (float64, int) {
	c := 0
	for _, v := range a {
		if v < 30 {
			c++
		}
	}
	m := math.Ceil(float64(c*200) / 900)
	return m, c
}
