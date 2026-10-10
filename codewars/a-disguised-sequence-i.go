/*

Given u0 = 1, u1 = 2 and the relation 6*u[n]*u[n+1] - 5*u[n]*u[n+2] + u[n+1]*u[n+2] = 0 calculate un for any integer n >= 0.

Examples:
Call fcn the function such as fcn(n) = un.

fcn(17) -> 131072; fcn(21) -> 2097152

Remark:
You can take two points of view to do this kata:

the first one purely algorithmic from the definition of un

the second one - not at all mandatory, but as a complement - is to get a bit your head around and find which sequence is hidden behind un.

*/

package main

func main() {
	for i := range 30 {
		assert(rel(i) == 0)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rel(n int) int {
	return 6*u(n)*u(n+1) - 5*u(n)*u(n+2) + u(n+1)*u(n+2)
}

func u(n int) int {
	return 1 << n
}
