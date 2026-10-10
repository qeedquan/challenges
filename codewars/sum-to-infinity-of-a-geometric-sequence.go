/*

Hello everyone.

I have a simple challenge for you today. In mathematics, the formula for finding the sum to infinity of a geometric sequence is:

Soo = a1 / (1 - r)

ONLY IF -1 < r < 1

where:

a is the first term of the sequence
r is the common ratio of the sequence (calculated by dividing one term in the sequence by the previous term)
For example: 1 + 0.5 + 0.25 + 0.125 + ... = 2

Your challenge is to calculate the sum to infinity of the given sequence. The solution must be rounded to 3 decimal places.

If there are no solutions, for example if r is out of the above boundaries, return "No Solutions".

Hope you enjoy, let me know of any issues or improvements!

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]float64{1, 0.5, 0.25, 0.125}, 2)
	test([]float64{250, 100, 40, 16}, 416.667)
	test([]float64{21, 4.2, 0.84, 0.168}, 26.25)
	test([]float64{5, -2.5, 1.25, -0.625}, 3.333)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x []float64, r any) {
	v := suminf(x)
	fmt.Println(v)

	switch r := r.(type) {
	case string:
		assert(v == r)
	case float64:
		f := v.(float64)
		assert(math.Abs(f-r) < 1e-3)
	}
}

func suminf(x []float64) any {
	const eps = 1e-12

	if len(x) < 2 {
		return "No solutions"
	}

	r := x[1] / x[0]
	for i := 2; i < len(x); i++ {
		if math.Abs(x[i]/x[i-1]-r) >= eps {
			return "No solutions"
		}
	}
	if r <= -1 || r >= 1 {
		return "No solutions"
	}

	return x[0] / (1 - r)
}
