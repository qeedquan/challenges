/*

The EML function in combination with the constant 1 is universal for elementary functions:
https://arxiv.org/abs/2603.21852

eml(x, y) = exp(x) - ln(y)

Here the exponential and logarithm are complex, taking the principal branch.
Finally, the extended reals are used, giving ln(0)=-∞, e^-∞=0. In the above expression, the value of a-b is left undefined where a and b are both non-finite.

I define an EML expression as either the integer 1, or the eml function applied to two EML expressions.
The goal of this challenge is to generate EML expressions for integers n.
For example, a possible expression for n=2 is:

eml(
 eml(1, eml(eml(1, 1), 1)),
 eml(eml(eml(1, eml(eml(1, eml(1, eml(eml(1, 1), 1))), 1)), eml(1, 1)), 1)
)

Your task is to generate EML expressions for the numbers 0≤n≤1000.
Your score is the total number of eml applications needed.
The score contribution for the above example of n=2 would be 13, as there are thirteen applications of eml.
Each number must be its own independent expression - you can not assign temporaries or re-use partial results.

*/

package main

import (
	"fmt"
	"math/cmplx"
)

func main() {
	fmt.Println(add(one(), one()))
}

func eml(x, y complex128) complex128      { return cmplx.Exp(x) - cmplx.Log(y) }
func e() complex128                       { return eml(1, 1) }
func exp(x complex128) complex128         { return eml(x, 1) }
func zero() complex128                    { return eml(1, exp(exp(1))) }
func one() complex128                     { return negate(multiply(i(), i())) }
func infinity() complex128                { return eml(1, zero()) }
func neg_infinity() complex128            { return eml(1, infinity()) }
func negate(x complex128) complex128      { return eml(neg_infinity(), exp(x)) }
func ln(x complex128) complex128          { return negate(eml(neg_infinity(), x)) }
func invert(x complex128) complex128      { return exp(negate(ln(x))) }
func subtract(x, y complex128) complex128 { return eml(ln(x), exp(y)) }
func add(x, y complex128) complex128      { return subtract(x, negate(y)) }
func multiply(x, y complex128) complex128 { return exp(add(ln(x), ln(y))) }
func divide(x, y complex128) complex128   { return multiply(x, invert(y)) }
func power(x, y complex128) complex128    { return exp(multiply(y, ln(x))) }
func i() complex128                       { return power(negate(1), divide(1, add(1, 1))) }
