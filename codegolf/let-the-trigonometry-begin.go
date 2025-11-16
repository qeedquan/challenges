/*

Introduction:
The sine of x is given by the formula:

sin(x) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9! - x^11/11! + ...

The cosine of x is given by the formula:

cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + x^8/8! - x^10/10! + ...

Task:
Given the value of x and n, write a program (no functions, etc.) to output the value of sin(x) and cos(x) correct up to n terms of the formula above.
Assume that x is in radians.

Input:
x n
A decimal number x (with up to 3 decimal places) and an integer n. Input must be on stdin or a prompt dialog box (iff your language doesn't support stdin)

Output:
[sin(x)]
[cos(x)]

The value of both sin(x) and cos(x) should be rounded to 6 decimal places. If sin(x) is 0.5588558855 (10 decimal digits), it should be rounded to 0.558856 (6 decimal digits).
The rounding must take place to the nearest, as described in the fifth column, "Round to nearest", of the the table in this Wiki article.

Constraints:
1 <= x <= 20
1 <= n <= 20
Samples:
----
5 3

10.208333
14.541667
----
8.555 13

0.765431
-0.641092
----
9.26 10

-3.154677
-8.404354
----
6.54 12

0.253986
0.967147
----
5 1

5.000000
1.000000
----
20 20

-5364.411846
-10898.499385
----

Notes:
Standard loopholes are prohibited.
Built-in math functions and operators of trigonometry (sin, cos, tan, etc.), factorial, and exponentiation cannot be used. You are free to use a built-in rounding function for estimating the result of computing sin(x) and cos(x) to the 6-th decimal digit.
No need to handle wrong inputs.
Only ASCII characters can be used in the program, not the Chinese Unicode ones that allow code compression.
Your program must terminate, and display the output, within 3 seconds of input.
Your answer must accompany the ungolfed code, along with the explanation of the code (compulsory if the code is not immediately obvious to programmers-not-familiar-with-your-language, especially GolfScript, J, etc.).
Please include a link to an online compiler where your program can be tested.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(5, 3, 10.208333, 14.541667)
	test(8.555, 13, 0.765431, -0.641092)
	test(9.26, 10, -3.154677, -8.404354)
	test(6.54, 12, 0.253986, 0.967147)
	test(5, 1, 5.000000, 1.000000)
	test(20, 20, -5364.411846, -10898.499385)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x float64, n int, sr, cr float64) {
	const eps = 1e-6
	s, c := taylor(x, n)
	fmt.Println(s, c)
	assert(math.Abs(s-sr) < eps)
	assert(math.Abs(c-cr) < eps)
}

/*

@xnor

The main idea is to compute 2*n terms of e^(ix), and then take the imaginary and real part to get the sin and cos values approximated to n terms. We use the truncation of the Taylor series:

e^(ix)≈sum_{k=0}^{2n-1} (i*x)^k/k!
This is polynomial in i*x, but rather than compute its value by summing each term, we use a modified Horner's Method to compute the sequence (defined recursively in reverse)

t_{2n} = 1
t_k = 1 + t_{k+1}*i*x/k, which gives t_1 equaling the desired value.

*/

func taylor(x float64, n int) (float64, float64) {
	r := 1.0 + 0i
	k := 2 * n
	for k > 1 {
		k -= 1
		r = r*1i*complex(x/float64(k), 0) + 1
	}
	return imag(r), real(r)
}
