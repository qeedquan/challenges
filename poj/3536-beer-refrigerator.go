/*

Description

Beer Lovers Club makes regular parties. They hate warm beer, but club’s refrigerator is too small to store enough beer for the whole company. So they decided to order a special super-big beer refrigerator. The new refrigerator should be a parallelepiped a × b × c and store exactly n cubical 1 × 1 × 1 beer boxes (the club has n members). To decrease losses of cold, the total area of the surface of the refrigerator must be as small as possible.

For example, if the capacity of the refrigerator must be 12, the possible variants are:

Dimensions		Surface Area
3 × 2 × 2		32
4 × 3 × 1		38
6 × 2 × 1		40
12 × 1 × 1		50
The best variant in this case is 3 × 2 × 2.

Help the beer lovers to find the optimal dimensions of their new refrigerator.

Input

The input file contains single integer number n (1 ≤ n ≤ 10^6) — the capacity of the refrigerator. Help the beer lovers to find the optimal dimensions of their new refrigerator.

Output

Output three integer numbers: a, b and c — the optimal dimensions of the refrigerator. If there are several solutions, output any of them.

Sample Input

#1	12
#2	13
#3	1000000

Sample Output

#1	3 2 2
#2	1 13 1
#3	100 100 100

Source

Northeastern Europe 2007, Northern Subregion

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(12, 3, 2, 2)
	test(13, 13, 1, 1)
	test(1000000, 100, 100, 100)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, ra, rb, rc int) {
	a, b, c := dimensions(n)
	fmt.Println(a, b, c)
	assert(a == ra)
	assert(b == rb)
	assert(c == rc)
}

func dimensions(n int) (a, b, c int) {
	m := math.MaxInt
	d1 := isqrt(n) + 1
	for i := 1; i <= d1; i++ {
		if n%i != 0 {
			continue
		}

		d2 := isqrt(n/i) + 1
		for j := i; j <= d2; j++ {
			if (n/i)%j != 0 {
				continue
			}

			k := n / (i * j)
			v := 2 * (i*j + j*k + k*i)
			if v < m {
				m, a, b, c = v, i, j, k
			}
		}
	}
	return max(a, b, c), mid(a, b, c), min(a, b, c)
}

func mid(a, b, c int) int {
	return max(min(a, b), min(max(a, b), c))
}

func isqrt(x int) int {
	return int(math.Sqrt(float64(x)))
}
