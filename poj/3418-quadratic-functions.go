/*

Description

You are to process a sequence of M queries of two types:

Add a quadratic function f(x) = ax^2 + bx + c into the plane.
Compute the global minimum value of all the quadratic functions at x: min{fi(x)}.

Input

The first line consists of one integer: M (number of queries). (2 ≤ M ≤ 10^6)
The next M lines contain queries. Each query can be either addition or computation.

I a b c : add a quadratic function into the plane. You can assume the coefficient of the linear term is the double of the quadratic term's.
Q x : compute the global minimum value of all the quadratic functions at x: min{fi(x)}. Before the query, there is at least a curve in the plane.
All numbers in the input file are integers, whose absolute values are no more than 10^6.

Output

For each computation query, print a line consisting of one integer which denotes the global minimum value. Assume the absolute values of the answers are no more than 2 × 109.

Sample Input

2
I 1 2 1
Q 1

Sample Output

4

Source

POJ Monthly--2007.10.06, Amber(hupo001)@POJ

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	process([]string{
		"I 1 2 1",
		"Q 1",
	})
}

func process(ops []string) {
	var q [][3]int
	for _, op := range ops {
		var (
			c [3]int
			x int
		)

		n, _ := fmt.Sscanf(op, "I %d %d %d", &c[0], &c[1], &c[2])
		if n == 3 {
			q = append(q, c)
			continue
		}

		n, _ = fmt.Sscanf(op, "Q %d", &x)
		if n == 1 {
			r := math.MaxInt
			for _, v := range q {
				r = min(r, v[0]*x*x+v[1]*x+v[2])
			}
			fmt.Println(r)
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
