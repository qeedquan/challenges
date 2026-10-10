/*

Description

In the kingdom of Polygon the royal family consists of the king, the queen, and the 10-year-old twins, Prince Obtuse and Prince Trisect. The twins are fiercely competitive, and on their birthday they always vie with each other for the biggest portion of the cake. The wise king and queen have devised the following way to prevent squabbles over the cake. The King randomly selects some points in the same plane, and then the prince will be given the chance to select three different points from them to make a triangle. The circumcircle of the triangle would be the shape of the cake for him. Now one of the little princes asks you for help. Your task is to help the little prince to find the biggest cake he can get.

Input

The first line of the input is an integer T which indicates the number of test cases. The first line of each test case is an integer n, denoting the number of points.3 ≤ n ≤ 655. The following n lines describe coordinates of points. 0 ≤ x, y ≤ 10000.

Output

For each test case, output radius of the biggest cake given with accuracy 10-3 in a single line.

Sample Input

1
4
0 0
1 0
1 1
3 1

Sample Output

3.536

Source

South Central China 2008 hosted by NUDT

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]vec2{
		{0, 0},
		{1, 0},
		{1, 1},
		{3, 1},
	}, 3.536)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []vec2, r float64) {
	v := cakeful(a)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-3)
}

func cakeful(a []vec2) float64 {
	n := len(a)
	d := alloc(n)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			l := length(sub(a[i], a[j]))
			d[i][j], d[j][i] = l, l
		}
	}

	r := 0.0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				p := sub(a[k], a[i])
				q := sub(a[j], a[i])
				t := math.Abs(wedge(p, q))
				r = max(r, d[i][j]*(d[j][k]/2)*(d[k][i]/t))
			}
		}
	}
	return r
}

func alloc(n int) [][]float64 {
	m := make([][]float64, n)
	t := make([]float64, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}
	return m
}

func length(p vec2) float64 {
	return math.Hypot(p.x, p.y)
}

func sub(p, q vec2) vec2 {
	return vec2{p.x - q.x, p.y - q.y}
}

func wedge(p, q vec2) float64 {
	return p.x*q.y - p.y*q.x
}

type vec2 struct {
	x, y float64
}
