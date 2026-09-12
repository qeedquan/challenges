/*

Consider a sorted array of positive floating point numbers such as:

input = [0.22, 2.88, 6.35, 7.17, 9.15]
For each integer i from 1 up to the last value in input rounded up, output the mean of all values less than i.

In this case the output should be:

[0.22 0.22 1.55 1.55 1.55 1.55 3.15 4.155 4.155 5.154 ]
If there is no value in the input less than i
 you don't need to add anything to the output.

More examples: (output rounded to three decimal places)

input = [2.37, 4.15, 5.47, 6.64, 7.01, 8.87, 9.37]

output = [2.37 2.37 3.26 3.997 4.657 5.128 5.752 6.269]

input =  [2.22, 2.66]

output = [2.44]

input = [0.09, 0.09, 2.21, 3.64, 7.26, 7.58, 9]

output = [0.09, 0.09, 0.797, 1.508, 1.508, 1.508, 1.508, 3.478, 3.478]

input = [0.35, 2, 2.45, 3.71, 5.13, 9.0, 9.66]

output = [0.35, 0.35, 1.6, 2.128, 2.128, 2.728, 2.728, 2.728, 2.728, 4.614]
You can round your output to three decimals places or not as you choose.

Your code should run in linear time in the length of the output plus the length of the input

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]float64{0.22, 2.88, 6.35, 7.17, 9.15}, []float64{0.22, 0.22, 1.55, 1.55, 1.55, 1.55, 3.15, 4.155, 4.155, 5.154})
	test([]float64{2.37, 4.15, 5.47, 6.64, 7.01, 8.87, 9.37}, []float64{2.37, 2.37, 3.26, 3.997, 4.657, 5.128, 5.752, 6.269})
	test([]float64{2.22, 2.66}, []float64{2.44})
	test([]float64{0.09, 0.09, 2.21, 3.64, 7.26, 7.58, 9}, []float64{0.09, 0.09, 0.797, 1.508, 1.508, 1.508, 1.508, 3.478, 3.478})
	test([]float64{0.35, 2, 2.45, 3.71, 5.13, 9.0, 9.66}, []float64{0.35, 0.35, 1.6, 2.128, 2.128, 2.728, 2.728, 2.728, 2.728, 4.614})
	test([]float64{}, []float64{})
	test([]float64{-5, -4, -3, -2, -1}, []float64{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []float64) {
	p := cummean(a)
	fmt.Println(p)
	assert(len(p) == len(r))
	for i := range p {
		assert(math.Abs(p[i]-r[i]) < 1e-3)
	}
}

func cummean(a []float64) []float64 {
	n := len(a)
	if n == 0 {
		return []float64{}
	}

	r := []float64{}
	i := 0.0
	j := 0
	s := 0.0
	for i < a[n-1]+1 {
		if j < n && a[j] < i {
			s, j = s+a[j], j+1
		} else {
			if i++; j != 0 {
				r = append(r, s/float64(j))
			}
		}
	}
	return r
}
