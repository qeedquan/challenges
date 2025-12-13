/*

Input
A floating point number x between 1 and 8 inclusive.

Output
The Dickman function of x. The Dickman–de Bruijn function ρ(u) is a continuous function that satisfies the delay differential equation

uρ′(u)+ρ(u−1)=0,

with initial conditions ρ(u)=1 for 0≤u≤1.

Your answer must be within 0.1 percent of the correct answer.

Examples
x=8 gives 3.23206930422610e-8
x=7 gives 8.74566995329392e-7
x=5.5 gives 0.0000860186111205116
x=4.2 gives 0.00297547478958152
x=2.9 gives 0.0598781159863707
x=1.3 gives 0.737635735532509
x=1 gives 1
If your language has a built in function, please also provide an answer not using the built in function.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(1, 1)
	test(1.3, 0.737635735532509)
	test(2.9, 0.0598781159863707)
	test(4.2, 0.00297547478958152)
	test(5.5, 0.0000860186111205116)
	test(7, 8.74566995329392e-7)
	test(8, 3.23206930422610e-8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, r float64) {
	p := dickman(x)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-9)
}

/*

ported from @Bubbler solution

g(x) computes the Dickman function ρ(x) with relative error under 5e-7 for up to x <= 8.

Instead of a single continuous function ρ(x), let's define a sequence of functions f0(x),f1(x),f2(x),⋯ which are defined on the interval -12≤x≤12:

f0(x) = 1
(x + 3/2) * f'1(x) + f0(x) = 0
(x + i + 1/2) * f'i(x) + f[i-1](x)=0 in general.
Now we will approximate these functions using truncated Maclaurin series. Let's write f(x) = [a0, a1, a2, ...] as a convenient notation for f(x) = a0*x0 + a1&x^1 + a2*x^2 + ....

Solving (x + i + 1/2)*f'i(x) + f[i-1](x)=0 for f[i] gives

f[i](x) = C + ∫ [f[i-1](x) / (x + i + 1/2)] dx

so we will multiply the Maclaurin series of f[i-1](x) with that of 1 / (x + i + 1/2), integrate it, and find the constant term using the boundary condition f[i-1](1/2) = f[i](-1/2).

The Maclaurin series expansion of 1/(x+k) is [k^-1, -(k^-2), k^-3, -(k^-4), ...]. Factor out k^-1 (we will multiply it back later), and multiplying with [a0, a1, a2, a3, ...] gives

[
  a0,
  -k^-1 * a0 + a1,
  k^-2 * a0 - k^-1 * a1 + a2,
  -k^-3 * a0 + k^-2 * a1 - k^-1 * a2 + a3,
  ...
]

which can be converted to a simple scan "multiply the previous cumulative result with -1/k and add current term", i.e. if the resulting series is [b0, b1, b2, b3, ...] then it is equal to

[a0, -1/k * b0 + a1, -1/k * b1 + a2, -1/k * b2 + a3, ...]
Integration is also easy: since integration of x^n is x^(n+1)/(n+1), we can divide each term with its 1-based index and prepend a constant term.

The constant term is simply f[i-1](1/2) - f[i](-1/2) where f[i] is evaluated without the constant term.

E(f,x) evaluates the polynomial f at x. N(p,i) takes the series for fi and the value of i+1.5 to compute the series for fi+1.
g(x) finds the appropriate function for the interval that x belongs to, and then evaluates the function at x offset by an appropriate amount.

I had to read a few papers cited on the Wikipedia page to get the idea, but computing with the idea turned out to be not that complex, yet surprisingly efficient and accurate.
I intentionally didn't golf the program hard to keep the intents relatively clear, in the hopes that others can port this without too much problem.

*/

func dickman(x float64) float64 {
	const N = 100

	f := make([]float64, N)
	f[0] = 1

	for i := range int(x) {
		f = integrate(f, float64(i)+1.5)
	}

	_, p := math.Modf(x)
	return poly(f, p-0.5)
}

func poly(f []float64, x float64) float64 {
	r := 0.0
	for i, c := range f {
		r += c * math.Pow(x, float64(i))
	}
	return r
}

func integrate(p []float64, I float64) []float64 {
	A := append([]float64{}, p...)
	l := len(A)

	for i := 1; i < l; i++ {
		A[i] -= A[i-1] / I
	}

	for i := range l {
		A[i] /= I * float64(-i-1)
	}

	r := poly(p, 0.5) + poly(A, -0.5)/2
	return append([]float64{r}, A...)
}
