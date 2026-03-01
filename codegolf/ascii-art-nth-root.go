/*

Challenge:
Given two integers a and b, with lengths A=length(a),B=length(b), output an ASCII-art of the ath root of b, including the answer rounded to A amount of decimal places.
The size of the ASCII-art root also depends on A and B.

Example:

a=123, b=1234

     ____
123 /1234 = 1.060
\  /
 \/
Because B=4, we have four _ above the 1234. Because A=3, we have three† / and 1.0595772951... is rounded to 1.060.

†: This will not be equal to A, but ⌈A2⌉+1 instead.

Challenge rules:
I/O format is flexible:
You're allowed to take the input loose or as a pair of integers; doubles; strings; list of digits; etc.
You're allowed to print the result directly to STDOUT; return it as a string; return it as a list/array/stream of string-lines; return it as a matrix of characters; etc.
If input a has an odd length A, the number is left-aligned in the output.
So in the example above you're not allowed to have the second line as  123/1234 = 1.060! (It should be 123<space>/... instead of <space>123/...)
The = in the output should be surrounded by a single leading/trailing space
Rounding can be done in any reasonable way (e.g. rounding towards 0, half-up, half-even, banker's rounding, etc.)
If the rounded result ends with 0s, you're allowed to omit them. (E.g., the 1.060 in the example above may also be 1.06.)
You can assume a>0 and b≥0 (a is positive, b is non-negative).
Trailing spaces in the output, and a single trailing newline is fine. Multiple trailing newlines or trailing whitespaces are not.

General rules:
This is code-golf, so the shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages.
Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (e.g. TIO).
Also, adding an explanation for your answer is highly recommended.

Test cases:
Inputs: a=3, b=100 (A=1, B=3)
   ___
3 /100 = 4.6
\/

Inputs: a=123, b=1234 (A=3, B=4)
     ____
123 /1234 = 1.060
\  /
 \/

Inputs: a=10, b=10 (A=2, B=2)
   __
10/10 = 1.26
\/

Inputs: a=1298123, b=9023847978341 (A=7, B=13)
         _____________
1298123 /9023847978341 = 1.0000230
\      /
 \    /
  \  /
   \/

Inputs: a=2500, b=0 (A=4, B=1)
     _
2500/0 = 0.0000
\  /
 \/

*/

package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	asciiroot(3, 100)
	asciiroot(123, 1234)
	asciiroot(10, 10)
	asciiroot(1298123, 9023847978341)
	asciiroot(2500, 0)
}

func asciiroot(a, b int64) {
	A := len(fmt.Sprint(-a)) & ^1
	B := len(fmt.Sprint(b))
	c := math.Pow(float64(b), 1/float64(a))
	fmt.Print(strings.Repeat(" ", A+1))
	fmt.Print(strings.Repeat("_", B))
	fmt.Println()
	fmt.Printf("%-*d/%d = %.*f", A, a, b, A, c)
	fmt.Println()
	for p := `\`; A > 0; p = " " + p {
		A -= 2
		fmt.Printf("%s%s/\n", p, strings.Repeat(" ", A))
	}
}
