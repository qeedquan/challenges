/*

For a lot of the questions today we are going to be doing some simple numerical calculus. Don't worry, its not too terrifying.

Write a function fmin that can take in a real-valued function f(x) where x is a vector in 3D space (bonus points for N-D).

xout=fmin(f,x0) should return a local minimum of f close to x0.

Example in Python

%f is a function with 1 3-vector
def f(x):
    return x[0]**2+x[1]**2+x[2]**2

%find the local minimum of f, starting at (1,1,1)
print fmin(f,[1.0,1.0,1.0])
should print out

[0.0,0.0,0.0]  %because (0,0,0) is the global minimum of f(x,y,z)=x^2+y^2+z^2
EDIT: To make this a little easier, I decided that it is acceptable for your implementation to require that fmin have additional arguments for the derivatives of f

*/

package main

import (
	"fmt"
	"math"
	"math/rand"
)

type fn func(float64, float64, float64) float64

func main() {
	fmt.Println(fmin(f1, 1, 1, 1))
	fmt.Println(fmin(f2, 0, 0, 0))
	fmt.Println(fmin(f3, 20, 20, 20))
	fmt.Println(fmin(f4, 0, 0, 0))
}

// https://en.wikipedia.org/wiki/Hill_climbing
func fmin(f fn, x, y, z float64) (float64, float64, float64) {
	f0 := f(x, y, z)
	for k := 0.0; k < 1000000; k++ {
		d := math.Exp(-k / 2000)
		nx := x + rand.Float64()*2*d - d
		ny := y + rand.Float64()*2*d - d
		nz := z + rand.Float64()*2*d - d
		nf := f(nx, ny, nz)
		if nf < f0 {
			f0, x, y, z = nf, nx, ny, nz
		}
	}
	return x, y, z
}

func f1(x, y, z float64) float64 {
	return x*x + y*y + z*z
}

func f2(x, y, z float64) float64 {
	return math.Sin(x) + math.Sin(y) + math.Sin(z)
}

func f3(x, y, z float64) float64 {
	return x + y + z
}

func f4(x, y, z float64) float64 {
	return math.Cos(x) + math.Sin(y) + math.Cos(z)
}
