/*

Description

In his freshman year, flymouse studied integral. Symbolic integration frustrated him a lot. He was often confused by those subtle techniques: alternately trying integration by substitution and integration by parts until the integrand appears in a tabulated form then employing integration by quadrature to have the work finally done. In contrast, numerical integration intrigued him much. By following some fixed procedures such as Newton-Cotes formulas, he could easily find the approximation to some definite integrals without too much effort. Given the exercises flymouse did, can your program do as nice a job as flymouse did?

Input

The input contains several test cases. Each test case consists of one line containing a univariate function f(x) and two real numbers a and b meaning the approximate value of  is to be found. f(x) is expressed as a C-expression-like string. Allowed tokens are summarized in the following table:

Token	Meaning	Example	Example in Mathematical Form
+	addition, positive	x+1, +x	x + 1, +x
-	subtraction, negative	x-1, -x	x − 1, −x
*	multiplication	x*x	x · x
/	division	x/2	x⁄2
^	power	x^-x	x−x
(	left parenthesis	(x+1)*x	(x + 1) x
)	right parenthesis	-(x+1)	−(x + 1)
sin	sine	sin(x)	sin x
cos	cosine	cos(x)	cos x
tan	tangent	tan(x)	tan x
log	natural logarithm	log(x)	ln x
exp	exponential	exp(x)	ex
asin	inverse sine	asin(x)	arcsin x
acos	inverse cosine	acos(x)	arccos x
atan	inverse tangent	atan(x)	arctan x
abs	absolute value	abs(x)	|x|
x	variable	x	x
constant	C floating-point constants without suffixes	0, 1.5	0, 1.5
And the syntax is given below:

S	::=	+S | -S | S+S | S-S | S*S | S/S | S^S | F(S) | (S) | x | constant
F	::=	sin | cos | tan | log | exp | asin | acos | atan
Operator precedence and associativity are almost the same as those in C except that ‘^’ takes higher precedence than ‘*’ and ‘/’ and has right associativity.

f(x) is not necessarily continuous. It can have singularities which are always isolated if exist. It can be oscillatory, but it will never be oscillatory in the neighborhood of singularities where it blows up. The integral is guaranteed to converge.

Length of the interval over which f(x) is integrated is not longer than 10.

Process to end of file.

Output

For each test case, output one line with only the approximate value of the integral rounded to exactly four digits past the decimal point.

Sample Input

x+1 0 1
+x 0 1
x-1 0 1
-x 0 1
x*x 0 1
x/2 0 1
x^-x 0 1
(x+1)*x 0 1
-(x+1) 0 1
sin(x) 0 1
cos(x) 0 1
tan(x) 0 1
log(x) 1 2
exp(x) 0 1
asin(x) 0 1
acos(x) 0 1
atan(x) 0 1
abs(x) 0 1
x 0 1
1 0 1
sin(x)/x 0 1

Sample Output

1.5000
0.5000
-0.5000
-0.5000
0.3333
0.2500
1.2913
0.8333
-1.5000
0.4597
0.8415
0.6156
0.3863
1.7183
0.5708
1.0000
0.4388
0.5000
0.5000
1.0000
0.9461

Hint

Be cautious about outputting ‘-0.0000’.
Make your integration module as robust as possible.

Source

POJ Monthly--2006.12.31, galaxy

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(f1, 0, 1, 1.5000)
	test(f2, 0, 1, 0.5000)
	test(f3, 0, 1, -0.5000)
	test(f4, 0, 1, -0.5000)
	test(f5, 0, 1, 0.3333)
	test(f6, 0, 1, 0.2500)
	test(f7, 0, 1, 1.2913)
	test(f8, 0, 1, 0.8333)
	test(f9, 0, 1, -1.5000)
	test(f10, 0, 1, 0.4597)
	test(f11, 0, 1, 0.8415)
	test(f12, 0, 1, 0.6156)
	test(f13, 1, 2, 0.3863)
	test(f14, 0, 1, 1.7183)
	test(f15, 0, 1, 0.5708)
	test(f16, 0, 1, 1.0000)
	test(f17, 0, 1, 0.4388)
	test(f18, 0, 1, 0.5000)
	test(f19, 0, 1, 0.5000)
	test(f20, 0, 1, 1.0000)
	test(f21, 0, 1, 0.9461)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(f func(float64) float64, begin, end float64, expected float64) {
	value := simpson(f, begin, end, 1e3)
	fmt.Println(value)
	assert(math.Abs(value-expected) < 1e-4)
}

func simpson(f func(float64) float64, begin, end float64, n int) float64 {
	delta := (end - begin) / float64(n)
	ret := f(begin)
	for i, j := 0, 1; j < n; j++ {
		ret += float64(4-(i<<1)) * f(begin+float64(j)*delta)
		i = (i + 1) & 1
	}
	ret += f(end)
	ret *= (delta / 3)
	return ret
}

func f1(x float64) float64  { return x + 1 }
func f2(x float64) float64  { return +x }
func f3(x float64) float64  { return x - 1 }
func f4(x float64) float64  { return -x }
func f5(x float64) float64  { return x * x }
func f6(x float64) float64  { return x / 2 }
func f7(x float64) float64  { return math.Pow(x, -x) }
func f8(x float64) float64  { return (x + 1) * x }
func f9(x float64) float64  { return -(x + 1) }
func f10(x float64) float64 { return math.Sin(x) }
func f11(x float64) float64 { return math.Cos(x) }
func f12(x float64) float64 { return math.Tan(x) }
func f13(x float64) float64 { return math.Log(x) }
func f14(x float64) float64 { return math.Exp(x) }
func f15(x float64) float64 { return math.Asin(x) }
func f16(x float64) float64 { return math.Acos(x) }
func f17(x float64) float64 { return math.Atan(x) }
func f18(x float64) float64 { return math.Abs(x) }
func f19(x float64) float64 { return x }
func f20(x float64) float64 { return 1 }
func f21(x float64) float64 {
	if x == 0 {
		return 1
	}
	return math.Sin(x) / x
}
