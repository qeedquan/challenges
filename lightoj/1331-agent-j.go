/*

Agent J is preparing to steal an antique diamond piece from a museum. As it is fully guarded and they are guarding it using high technologies, it's not easy to steal the piece. There are three circular laser scanners in the museum which are the main headache for Agent J. The scanners are centered in a certain position, and they keep rotating maintaining a certain radius. And they are placed such that their coverage areas touch each other as shown in the picture below:

https://static.lightoj.com/images/problem-1332-agent_j-1603777535898.png?centerme,haveborder

Here R1, R2 and R3 are the radii of the coverage areas of the three laser scanners. The diamond is placed in the place blue shaded region as in the picture. Now your task is to find the area of this region for Agent J, as he needs to know where he should land to steal the diamond.

Input
Input starts with an integer T (≤ 1000), denoting the number of test cases.

Each case starts with a line containing three real numbers denoting R1, R2 and R3 (0 < R1, R2, R3 ≤ 100). And no number contains more than two digits after the decimal point.

Output
For each case, print the case number and the area of the place where the diamond piece is located. Error less than 10^-6 will be ignored.

Sample
Input	Output
3
1.0 1.0 1.0
2 2 2
3 3 3

Case 1: 0.16125448
Case 2: 0.645017923
Case 3: 1.4512903270

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(1, 1, 1))
	fmt.Println(solve(2, 2, 2))
	fmt.Println(solve(3, 3, 3))
}

func solve(a, b, c float64) float64 {
	s := (a + a + b + b + c + c) / 2.0
	r := math.Sqrt(s * (s - a - b) * (s - b - c) * (s - c - a))
	r -= area(a, angle(b+c, c+a, a+b))
	r -= area(b, angle(c+a, a+b, b+c))
	r -= area(c, angle(a+b, b+c, c+a))
	return r
}

func area(r, a float64) float64 {
	return 0.5 * r * r * a
}

func angle(A, B, C float64) float64 {
	return math.Acos((B*B + C*C - A*A) / (2 * B * C))
}
