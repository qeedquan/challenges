/*

Print a point chosen uniformly at random inside the circle of radius 1 centered at (a,b).

Input
One line contains three integers n (0<n≤1000), a and b (−100≤a,b≤100).

Output
Print n lines. Each line must contain two real numbers x and y, where (x,y) is a uniformly chosen point strictly inside the circle of radius 1 centered at (a,b).

Examples
Input #1
5 3 6

Answer #1
3.876984 5.564813
2.235771 5.928483
3.268512 5.227540
3.298673 6.924705
2.274073 5.551337

*/

package main

import (
	"fmt"
	"math"
	"math/rand"
)

func main() {
	solve(5, 3, 6)
}

func solve(n int, x, y float64) {
	for range n {
		fmt.Println(gen(x, y, 1))
	}
}

// https://stackoverflow.com/questions/5837572/generate-a-random-point-within-a-circle-uniformly
func gen(x, y, r float64) (float64, float64) {
	rad := r * math.Sqrt(rand.Float64())
	phi := rand.Float64() * 2 * math.Pi
	return x + rad*math.Cos(phi), y + rad*math.Sin(phi)
}
