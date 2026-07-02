/*

Given two positive reals a and b, output some positive reals ri, such that ∑ri=a and ∏(ri+1)=b.
You can assume that it's possible.
You can also assume that your float type have infinite precision.

Test cases:

2,3 => 2
2,4 => 1,1 or 1/2,(sqrt(57)+9)/12,(9-sqrt(57))/12 or etc.
2,5 => 1/3,1/2,2/3,1/2 or etc.
2,8 => (undefined behavior)
2,2 => (undefined behavior)
e,2e => 1,e-1 or etc. (e is natural base, though any number>1 work)
3,e^3 => (undefined behavior) (It's possible to get as close as you want to e^3, but not reaching)
Shortest code wins.

Notes
Given the assumption with infinite precision, you can't solve arbitrary equation if your language doesn't have such functions(you can still use functions like Solve in Mathematica to solve such). In this case, some forms may have solution mathematically but you can't work it out, e.g. p,p,p,...,p,q where p and q are reals. (At least software don't provide exact solution for x*x*x*y=5,3*x+y=7)

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(2, 3))
	fmt.Println(solve(2, 4))
	fmt.Println(solve(2, 5))
	fmt.Println(solve(2, 8))
	fmt.Println(solve(2, 2))
	fmt.Println(solve(math.E, 2*math.E))
	fmt.Println(solve(3, math.Exp(3)))
	fmt.Println(solve(3, 19))
}

/*

@xnor

Based on this solution of Delfad0r, who also saved 1 byte off this

We first try to find a two-element solution with r1+r2=a and (r1+1)(r2+1)=b, which we do by solving a quadratic equation.
If we get real solutions, we're done. (If one solution is zero, we remove it and output a singleton.)

If this quadratic isn't solvable in the reals, we replace a -> a/2 and b -> sqrt(b) and solve from there.
If we find a solution to this, then duplicating the list (that is, repeating each element a second time) gives a solution to the original problem, since this doubles the sum and squares the product of numbers-plus-one.
We recursively make these substitutions until we simplify (a,b) to ones that give a two-element solution.

We show that this process always reaches a solution.
For the problem to be solvable, we must have b < e^a, which follows directly from ∑ri=a and ∏(ri+1)=b along with e^r[i] > r[i] + 1.
Since e^a is the increasing limit of (1 + a/N)^N as N->Inf, the bound b < e^a implies that b < (1 + a/N)^N, or equivalently that b^(1/N) < 1 + a/N, for sufficiently large N.
By choosing N=2^n as a large power of 2, doing n-1 steps of the substitution a -> a/2 and b -> sqrt(b) gives us a'=2a/N and b'=b^(2/N), which we've shown satisfy sqrt(b') < 1 + a'/2.

This is exactly what we need to have real solutions for r1+r2=a and (r1 + 1)(r2 + 1)=b, which gives a quadratic with discriminant (1 + a/2)^2 - b.
It solutions are
r = a/2 +- sqrt((1 - a/2)^2 - b)

*/

func solve(a, b float64) (float64, float64) {
	for det(a, b) < 0 {
		a, b = a/2, math.Sqrt(b)
	}

	d := math.Sqrt(det(a, b))
	r0 := a/2 + d
	r1 := a/2 - d
	return r0, r1
}

func det(a, b float64) float64 {
	s := 1 + a/2
	return s*s - b
}
