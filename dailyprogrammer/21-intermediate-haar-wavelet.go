/*

This idea is to implement the haar wavelet transform on an array of length 2n . This algorithm is a critical algorithm for many image compression and image processing applications, and it is relatively simple both recursively and iteratively.

The solution should take in as input an array of floating-point values, and return an array of floating point values that in some sense implements the haar wavelet transform.

thanks to Steve132 for the challenge

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	x1 := make([]float64, 8)
	for i := range x1 {
		x1[i] = rand.Float64()
	}
	x2 := haar(x1)
	x3 := haarinv(x2)
	fmt.Printf("% .3f\n", x1)
	fmt.Printf("% .3f\n", x2)
	fmt.Printf("% .3f\n", x3)
}

// https://mathr.co.uk/blog/2019-10-30_haar_wavelets.html
// signal length has to be a power of 2
func haar(x []float64) []float64 {
	n := len(x)
	z1 := append([]float64{}, x...)
	z2 := make([]float64, n)
	for l := n >> 1; l > 0; l >>= 1 {
		for i := range l {
			a := z1[2*i]
			b := z1[2*i+1]
			s := (a + b) / 2
			d := (a - b) / 2
			z2[i] = s
			z2[l+i] = d
		}
		copy(z1, z2)
	}
	return z1
}

func haarinv(x []float64) []float64 {
	n := len(x)
	z1 := append([]float64{}, x...)
	z2 := make([]float64, n)
	for l := 1; l <= n>>1; l <<= 1 {
		copy(z2, z1)
		for i := range l {
			s := z2[i]
			d := z2[l+i]
			a := s + d
			b := s - d
			z1[2*i] = a
			z1[2*i+1] = b
		}
	}
	return z1
}
