/*

Input:
Two integers: one negative, one positive.

Output:
On the first line output lowest to highest. On the second line we've removed the highest and lowest numbers and sign-changed all individual numbers. On the third line we've removed the highest and lowest numbers again and sign-changed all individual numbers again. etc. (The example below should make the challenge clearer.)

Important: In addition, we add spaces so the numbers in a column are all aligned (to the right).
The minimal alignment is the main part of this challenge, this means that you can't just make every single number the same width. The width of a column is based on the largest number-width of that specific column (and the sequence with sign-change is to give the numbers some variety in width per column).

For example:

Input: -3,6

Output:
-3,-2,-1, 0, 1, 2, 3, 4,5,6   // sequence from lowest to highest
 2, 1, 0,-1,-2,-3,-4,-5       // -3 and 6 removed; then all signs changed
-1, 0, 1, 2, 3, 4             // 2 and -5 removed; then all signs changed again
 0,-1,-2,-3                   // -1 and 4 removed; then all signs changed again
 1, 2                         // 0 and -3 removed; then all signs changed again
                              // only two numbers left, so we're done
As you can see above, spaces are added at the positive numbers, when they share a column with negative numbers to compensate for the - (the same would apply to 2-digit numbers).

Challenge rules:
Input must be two integers
You can assume these integers are in the -99-99 (inclusive) range.
The first integer will be negative, and the other will be positive.
Output can be in any reasonable format, as long as it's clear there are rows and rightly aligned columns: I.e. STDOUT; returning as String with newlines; returning as list of Strings; etc. Your call.
The output must also contain a delimiter of your own choice (except for spaces, tabs, new-lines, digits or -): I.e. ,; and ; and |; and X; etc. are all acceptable delimiters.
The output lines may not contain a leading or trailing delimiter.
The output may contain ONE trailing new-line, and any line may contain any number of trailing spaces.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.

Test cases:
Input: -3,6

Output:
-3,-2,-1, 0, 1, 2, 3, 4,5,6
 2, 1, 0,-1,-2,-3,-4,-5
-1, 0, 1, 2, 3, 4
 0,-1,-2,-3
 1, 2

Input: -1,1

Output:
-1,0,1
 0

Input: -2,8

Output:
-2,-1, 0, 1, 2, 3, 4, 5, 6,7,8
 1, 0,-1,-2,-3,-4,-5,-6,-7
 0, 1, 2, 3, 4, 5, 6
-1,-2,-3,-4,-5
 2, 3, 4
-3

Input: -15,8

Output:
-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1, 0, 1, 2, 3, 4, 5, 6,7,8
 14, 13, 12, 11, 10,  9, 8, 7, 6, 5, 4, 3, 2, 1, 0,-1,-2,-3,-4,-5,-6,-7
-13,-12,-11,-10, -9, -8,-7,-6,-5,-4,-3,-2,-1, 0, 1, 2, 3, 4, 5, 6
 12, 11, 10,  9,  8,  7, 6, 5, 4, 3, 2, 1, 0,-1,-2,-3,-4,-5
-11,-10, -9, -8, -7, -6,-5,-4,-3,-2,-1, 0, 1, 2, 3, 4
 10,  9,  8,  7,  6,  5, 4, 3, 2, 1, 0,-1,-2,-3
 -9, -8, -7, -6, -5, -4,-3,-2,-1, 0, 1, 2
  8,  7,  6,  5,  4,  3, 2, 1, 0,-1
 -7, -6, -5, -4, -3, -2,-1, 0
  6,  5,  4,  3,  2,  1
 -5, -4, -3, -2
  4,  3

Input: -3,15

Output:
-3,-2,-1, 0, 1, 2, 3, 4,  5, 6,  7,  8,  9, 10, 11, 12, 13,14,15
 2, 1, 0,-1,-2,-3,-4,-5, -6,-7, -8, -9,-10,-11,-12,-13,-14
-1, 0, 1, 2, 3, 4, 5, 6,  7, 8,  9, 10, 11, 12, 13
 0,-1,-2,-3,-4,-5,-6,-7, -8,-9,-10,-11,-12
 1, 2, 3, 4, 5, 6, 7, 8,  9,10, 11
-2,-3,-4,-5,-6,-7,-8,-9,-10
 3, 4, 5, 6, 7, 8, 9
-4,-5,-6,-7,-8
 5, 6, 7
-6

Input: -12,12

Output:
-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1, 0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10,11,12
 11, 10,  9, 8, 7, 6, 5, 4, 3, 2, 1, 0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11
-10, -9, -8,-7,-6,-5,-4,-3,-2,-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10
  9,  8,  7, 6, 5, 4, 3, 2, 1, 0,-1,-2,-3,-4,-5,-6,-7,-8,-9
 -8, -7, -6,-5,-4,-3,-2,-1, 0, 1, 2, 3, 4, 5, 6, 7, 8
  7,  6,  5, 4, 3, 2, 1, 0,-1,-2,-3,-4,-5,-6,-7
 -6, -5, -4,-3,-2,-1, 0, 1, 2, 3, 4, 5, 6
  5,  4,  3, 2, 1, 0,-1,-2,-3,-4,-5
 -4, -3, -2,-1, 0, 1, 2, 3, 4
  3,  2,  1, 0,-1,-2,-3
 -2, -1,  0, 1, 2
  1,  0, -1
  0

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(-3, 6, [][]int{
		{-3, -2, -1, 0, 1, 2, 3, 4, 5, 6},
		{2, 1, 0, -1, -2, -3, -4, -5},
		{-1, 0, 1, 2, 3, 4},
		{0, -1, -2, -3},
		{1, 2},
	})

	test(-1, 1, [][]int{
		{-1, 0, 1},
		{0},
	})

	test(-2, 8, [][]int{
		{-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8},
		{1, 0, -1, -2, -3, -4, -5, -6, -7},
		{0, 1, 2, 3, 4, 5, 6},
		{-1, -2, -3, -4, -5},
		{2, 3, 4},
		{-3},
	})

	test(-15, 8, [][]int{
		{-15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8},
		{14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7},
		{-13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6},
		{12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5},
		{-11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4},
		{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3},
		{-9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2},
		{8, 7, 6, 5, 4, 3, 2, 1, 0, -1},
		{-7, -6, -5, -4, -3, -2, -1, 0},
		{6, 5, 4, 3, 2, 1},
		{-5, -4, -3, -2},
		{4, 3},
	})

	test(-3, 15, [][]int{
		{-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
		{2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14},
		{-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
		{0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12},
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
		{-2, -3, -4, -5, -6, -7, -8, -9, -10},
		{3, 4, 5, 6, 7, 8, 9},
		{-4, -5, -6, -7, -8},
		{5, 6, 7},
		{-6},
	})

	test(-12, 12, [][]int{
		{-12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
		{11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11},
		{-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
		{9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9},
		{-8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8},
		{7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7},
		{-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6},
		{5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5},
		{-4, -3, -2, -1, 0, 1, 2, 3, 4},
		{3, 2, 1, 0, -1, -2, -3},
		{-2, -1, 0, 1, 2},
		{1, 0, -1},
		{0},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b int, r [][]int) {
	p := gen(a, b)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func gen(a, b int) [][]int {
	r := [][]int{}
	f := b < a
	for {
		v := []int{}
		if a < b {
			for i := a; i <= b; i++ {
				v = append(v, i)
			}
		} else {
			for i := a; i >= b; i-- {
				v = append(v, i)
			}
		}

		if !f {
			a, b = -a-1, -b+1
		} else {
			a, b = -a+1, -b-1
		}
		f = !f

		r = append(r, v)
		if len(v) < 3 {
			break
		}
	}
	return r
}
