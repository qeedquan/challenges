/*

Description

Simon is doing a physics experiment with N identical balls with the same radius of R centimeters. Before the experiment, all N balls are fastened within a vertical tube one by one and the lowest point of the lowest ball is H meters above the ground. At beginning of the experiment, (at second 0), the first ball is released and falls down due to the gravity. After that, the balls are released one by one in every second until all balls have been released. When a ball hits the ground, it will bounce back with the same speed as it hits the ground. When two balls hit each other, they with exchange their velocities (both speed and direction).

http://poj.org/images/3684_1.png

Simon wants to know where are the N balls after T seconds. Can you help him?

In this problem, you can assume that the gravity is constant: g = 10 m/s2.

Input

The first line of the input contains one integer C (C ≤ 20) indicating the number of test cases. Each of the following lines contains four integers N, H, R, T.
1≤ N ≤ 100.
1≤ H ≤ 10000
1≤ R ≤ 100
1≤ T ≤ 10000

Output

For each test case, your program should output N real numbers indicating the height in meters of the lowest point of each ball separated by a single space in a single line. Each number should be rounded to 2 digit after the decimal point.

Sample Input

2
1 10 10 100
2 10 10 100

Sample Output

4.95
4.95 10.20

Source

POJ Founder Monthly Contest – 2008.08.31, Simon

*/

package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	test(1, 10, 10, 100, []float64{4.95})
	test(2, 10, 10, 100, []float64{4.95, 10.20})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(N int, H, R, T float64, r []float64) {
	p := snapshots(N, H, R, T)
	fmt.Println(p)
	assert(len(p) == len(r))
	for i := range p {
		assert(math.Abs(p[i]-r[i]) < 1e-2)
	}
}

func snapshots(N int, H, R, T float64) []float64 {
	p := make([]float64, N)
	for i := range p {
		p[i] = H
	}

	l := min(int(T), N)
	for i := 0; i < l; i++ {
		p[i] = position(p[i], T-float64(i))
	}

	sort.Float64s(p)

	R /= 100
	for i := 0; i < N; i++ {
		p[i] += 2 * float64(i) * R
	}

	return p
}

func position(h, t float64) float64 {
	const g = 10
	t0 := math.Sqrt(2 * h / g)
	t -= 2 * t0 * math.Floor(t/(2*t0))
	if t > t0 {
		t = 2*t0 - t
	}
	return h - 0.5*g*t*t
}
