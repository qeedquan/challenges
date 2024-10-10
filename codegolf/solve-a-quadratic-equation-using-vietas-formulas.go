/*

Exposition
Your mathematics teacher is a big fan of Vieta's formulas, and he believes that you should use them to solve quadratic equations. Given the equation

ax^2 + bx + c = 0
the product of its roots is c/a, and their sum is -b/a. When all of a, b and c are nonzero integers, assuming the roots are rational numbers, it's enough to try all possible numbers in the form

r1 = ±s/t
where s is a divisor of abs(c), and t is a divisor of abs(a). For each such r1, plug it into ax^2 + bx + c, and see whether the result is 0. If yes, then r1 is a root. The second root is -b/a-r1 or (c/a)/r1 - you can choose whatever formula you like.

Your teacher decided to give you many exercises, and he expects you to describe how you used Vieta's formulas to solve each one. Each exercise looks like this (example):

9x^2+12x+4=0
Write a subroutine or a program that gets an exercise as input, and outputs your alleged "solving process" to appease your teacher.

Input
Since you will feed the exercise to your program manually, format it in any convenient form. For example, use space-separated values on stdin:

9 12 4
or call a function with 3 parameters:

SolveExercise(9, 12, 4);
or parse the exercise literally:

9x^2+12x+4=0
Your output should be formatted as described below. Use the standard output device or return it as a string from your subroutine.

Output (example)
x = 1? 9x^2+12x+4 = 25
x = 2? 9x^2+12x+4 = 64
x = 1/3? 9x^2+12x+4 = 9
x = 2/3? 9x^2+12x+4 = 16
... (as many or as few failed attempts as you like)
x = -2/3? 9x^2+12x+4 = 0
r1 = -2/3
r2 = -12/9-(-2/3) = -2/3
Alternatively, the last line can be:

r2 = 4/9/(-2/3) = -2/3
Some additional notes:

The minimum number of line-breaks in the output is as described in the example (trailing line-break is not required). Additional line-breaks are permitted.
All coefficients in input are integers in the range [-9999...9999], none can be equal to 0
All roots are rational numbers, and should be output as such - e.g. 0.66666667 is not equal to 2/3 and so is incorrect
In the final expressions for r1 and r2, integers should be output as such, e.g. -99/1 is unacceptable, and should be output as -99; in other places in the output, denominator equal to ±1 is acceptable
Reduced form for rational numbers is not required - e.g. 2/4 is a good substitute for 1/2, even though it's ugly, even for roots r1 and r2
Parentheses in the output are sometimes required by rules of mathematics, e.g. in the expression 12/9/(2/3). When precedence rules of mathematics permit omission of parentheses, they are not required, e.g. -12/9--2/3. Superfluous parentheses are permitted: 4-(2) is OK, even though it's ugly
There should be at least one case (input) for which your program tries 3 or more non-integer values for r1; however, it's allowed to "guess the right answer" almost always on the first try
All trial values for r1 must be rational numbers ±s/t, where s and t are constrained as described above

Test cases

Input

x^2-x-2=0
or
1 -1 -2

Possible output

x=1? x^2-x-2=-2
x=-1? x^2-x-2=0
r1=-1
r2=-2/1/-1=2

Input

-x^2+2x-1=0
or
-1, 2x, -1

Possible output

x=1? -x^2+2x-1=0
r1=1
r2=-2/-1-1=1

Input

7x^2-316x+924=0
or
X(7, -316, 924);

Possible output (a divisor of 924 is 42, which solves the equation by "luck")

x=42? 7x^2-316x+924=0
r1=42
r2=316/7-42=22/7
Input

6x^2-35x-6=0
or

[6 -35 -6]
Possible output (even though your program may "know" that 6 is a root, it decides to show some failed trials)

x=1/2? 6x^2-35x-6=-88/4
x=1/3? 6x^2-35x-6=-153/9
x=3/2? 6x^2-35x-6=-180/4
x=6/1? 6x^2-35x-6=0
r1=6
r2=35/6-6=-1/6
Alternative versions for the last line:

r2=--35/6-6=-1/6
r2=-6/6/6=-1/6
Impossible input (no rational solutions)

x^2+5x+1=0
Impossible input (zero coefficient)

x^2-1=0

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(quadvieta(9, 12, 4))
	fmt.Println(quadvieta(-1, 2, -1))
	fmt.Println(quadvieta(7, -316, 924))
	fmt.Println(quadvieta(6, -35, -6))
	fmt.Println(quadvieta(1, 5, 1))
	fmt.Println(quadvieta(1, 0, -1))
}

func quadvieta(a, b, c int) (r0, r1 *big.Rat) {
	if a == 0 || b == 0 || c == 0 {
		return
	}

	s := divisors(abs(c))
	t := divisors(abs(a))
	for _, s := range s {
		for _, t := range t {
			if evalzero(a, b, c, s, t) {
				r0 = xrat(s, t)
				break
			}

			if evalzero(a, b, c, -s, t) {
				r0 = xrat(-s, t)
				break
			}
		}
	}

	if r0 != nil {
		r1 = xrat(-b, a)
		r1.Sub(r1, r0)
	}

	return
}

func divisors(n int) []int {
	r := []int{}
	for i := 1; i <= n; i++ {
		if n%i == 0 {
			r = append(r, i)
		}
	}
	return r
}

func evalzero(a, b, c, s, t int) bool {
	zero := xrat(0, 1)

	x := xrat(s, t)
	x2 := xrat(1, 1)
	x2.Mul(x, x)

	A := xrat(a, 1)
	B := xrat(b, 1)
	C := xrat(c, 1)

	A.Mul(A, x2)
	B.Mul(B, x)
	A.Add(A, B)
	A.Add(A, C)

	return A.Cmp(zero) == 0
}

func xrat(a, b int) *big.Rat {
	return big.NewRat(int64(a), int64(b))
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
