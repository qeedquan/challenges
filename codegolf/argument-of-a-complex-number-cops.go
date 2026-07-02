/*

This is the cop's thread, where one should post the scrambled code. Here is the robbers' thread where the cracked source should be posted and linked to the cop's answer.

Task: Write the shortest safe program that given two inputs x,y, outputs arg(x+iy), where arg(z) is defined as the angle between the positive real axis and the line joining the origin and z.

This is cops-and-robbers, so the rules are:

In your answer, post a scrambled version of your source code, which should not work. (should be written in any order)
You can take input/output in any standard way.
Hardcoding is forbidden.
Standard loopholes are banned.
If your code is cracked by the robbers, you must mention that it has been cracked in your title and include a spoiler containing your exact code.
Same thing applies for safe answers. (mention in the title that it's safe and include the spoiler)
You must specify the programming language you used and byte count.
Answers are considered safe after 5 days.
You can assume that |x|,|y|≤5.
You can also assume that x,y∈Z
Minimum decimal precision is 5 decimal places with any rounding mechanism of your choice.
You must state the rounding mechanism in your answer.
You are not allowed to return as fractions (numerator/denominators)
+-------------+
|Example cases|
+-------------+

+ - + - + -------------------------- +
| x | y | Output (10 decimal places) |
+ - + - + -------------------------- +
| 5 | 5 |        0.7853981633        |
+ - + - + -------------------------- +
| 1 | 4 |        1.3258176636        |
+ - + - + -------------------------- +
| 0 | 2 |        1.5707963267        |
+ - + - + -------------------------- +
| 0 | 0 |         Undefined          |
+ - + - + -------------------------- +
| -1| 0 |        3.1415926535        |
+ - + - + -------------------------- +
| 1 | 0 |              0             |
+ - + - + -------------------------- +
| -2| 1 |        2.6779450445        |
+ - + - + -------------------------- +
| -3| -4|       -2.2142973355        |
+ - + - + -------------------------- +
| 2 | -5|       -1.1902899496        |
+ - + - + -------------------------- +
The shortest safe answer by April 15 will be considered the winner.

*/

package main

import (
	"fmt"
	"math"
	"math/cmplx"
)

func main() {
	test(5+5i, 0.7853981633)
	test(1+4i, 1.3258176636)
	test(0+2i, 1.5707963267)
	test(0, 0)
	test(-1+0i, math.Pi)
	test(-2+1i, 2.6779450445)
	test(-3-4i, -2.2142973355)
	test(2-5i, -1.1902899496)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(z complex128, r float64) {
	p := cmplx.Phase(z)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-6)
}
