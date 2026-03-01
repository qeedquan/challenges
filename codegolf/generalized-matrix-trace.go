/*

Inspiration.
https://chat.stackexchange.com/transcript/message/42442315#42442315

Given (by any means):

A two-argument (or single argument consisting of a two-element list) black box function, f: ℤ+ × ℤ+ → ℤ+ (input and output are 1, 2, 3,…)
A strictly positive integer matrix with at least two rows and two columns
return the matrix's function trace.

What is a function trace?

A normal matrix trace is the sum of the major diagonal (top-left to bottom-right) of a matrix:

[[1,2,3],[4,5,6],[7,8,9]] → [1,5,9] → 1+5+9 → 15

But instead of summing, we want to apply f along the diagonal:

[[1,2,3],[4,5,6],[7,8,9]] → [1,5,9] → f(f(1,5),9) or f(1,f(5,9))

Please state whether you use left-to-right or right-to-left.

The given matrix and all intermediate values will be strictly positive integers within your language's integer domain. The matrix may be non-square.

Examples
f(x,y) = xy, [[1,2,3],[4,5,6],[7,8,9]] → 1×5×9 → 45

f(x,y) = xy, [[1,2,3],[4,5,6],[7,8,9]] → 159 → 1

f(x,y) = x-y, [[4,5,6],[1,2,3]] → 4-2 → 2

f(x,y) = (x+y)⁄2, [[2,3,4],[5,6,7],[8,9,10]] → 5 or 7

f(x,y) = x+2y, [[1,2,3],[4,5,6],[7,8,9]] → 47 or 29

f(x,y) = max(x,y), [[1,2,3],[4,5,6],[7,8,9]] → max(1,5,9) → 9

f(x,y) = 2x, [[1,2,3],[4,5,6],[7,8,9]] → 2 or 4

f(x,y) = lcm(x,y), [[2,2,2],[2,2,3],[2,3,3],[4,4,4]] → lcm(2,2,3) → 6

Reference implementation.

∇value←fn Trace matrix;rows;cols;diagLength;inds;i;leftInds;leftVal;leftString;rightInds;rightVal;rightString;expr
 rows←≢matrix         ⍝ tally
 cols←≢⊃matrix        ⍝ tally first
 diagLength←rows⌊cols ⍝ minimum
 inds←⍳diagLength-1   ⍝ indices

 :For i :In inds
     leftInds←i i
     leftVal←matrix[⊂leftInds]
     leftString←⍕leftVal       ⍝ stringify

     rightInds←leftInds+1
     rightVal←matrix[⊂rightInds]
     rightString←⍕rightVal

     expr←leftString,fn,rightString ⍝ concatenate
     value←⍎expr                    ⍝ evaluate
     matrix[⊂rightInds]←value
 :EndFor
∇

*/

package main

import (
	"math"
)

func main() {
	assert(trace([][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}, mul) == 45)

	assert(trace([][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}, pow) == 1)

	assert(trace([][]int{
		{4, 5, 6},
		{1, 2, 3},
	}, sub) == 2)

	assert(trace([][]int{
		{2, 3, 4},
		{5, 6, 7},
		{8, 9, 10},
	}, avg) == 7)

	assert(trace([][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}, xp2y) == 29)

	assert(trace([][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}, imax) == 9)

	assert(trace([][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}, double) == 4)

	assert(trace([][]int{
		{2, 2, 2},
		{2, 2, 3},
		{2, 3, 3},
		{4, 4, 4},
	}, lcm) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func trace(m [][]int, f func(int, int) int) int {
	if len(m) == 0 || len(m[0]) == 0 {
		return 0
	}

	n := min(len(m), len(m[0]))
	r := m[0][0]
	for i := 1; i < n; i++ {
		r = f(r, m[i][i])
	}
	return r
}

func mul(x, y int) int    { return x * y }
func pow(x, y int) int    { return int(math.Pow(float64(x), float64(y))) }
func sub(x, y int) int    { return x - y }
func avg(x, y int) int    { return (x + y) / 2 }
func xp2y(x, y int) int   { return x + 2*y }
func imax(x, y int) int   { return max(x, y) }
func double(x, y int) int { return 2 * x }
func lcm(x, y int) int    { return abs(x*y) / gcd(x, y) }

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
