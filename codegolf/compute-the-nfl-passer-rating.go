/*

Each quarterback in the NFL is given a passer rating at the end of the game, which measures how good their forward passes were. It is not strictly a basic arithmetic formula, and is calculated as follows.

Let

n be the number of forward pass attempts
c be the number of completed forward passes
y be the passing yards
t be the number of forward touchdown passes
i be the number of intercepted forward passes

Then calculate
f1 = 5(c/n - 0.3)
f2 = 0.25(y/n - 3)
f3 = 20(t/n)
f4 = 2.375 - 25(i/n)
and clamp these numbers between 0 and 2.375. Then the passer rating is 100*(f1+f2+f3+f4)/6
Given the clamping and the convention of rounding the rating to one decimal place, this number is between 0 and 158.3.

Task
Given n,c,y,t,i, calculate the passer rating rounded to one decimal place. You may round ties either way and may assume

all numbers are nonnegative integers n is positive t≤c and c+i≤n (a touchdown pass is by definition completed, and every pass is either complete, incomplete or intercepted)
Test cases
Some of these cases can be found on these Wikipedia pages.

n, c, y, t, i, rating
10 2 25 0 1 0.0
8 0 71 0 2 24.5
8 1 71 0 2 24.5
8 3 71 0 2 30.7
13 7 154 0 2 56.7
8 3 98 0 0 84.4
21 12 102 1 3 46.2
65 43 503 2 0 99.7
17 12 126 3 1 106.9
19 14 192 1 1 101.2
19 16 192 1 1 104.4
19 18 192 1 1 104.4
16 11 223 2 1 125.0
29 24 412 4 0 158.3
15 12 276 3 0 158.3

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(10, 2, 25, 0, 1, 0.0)
	test(8, 0, 71, 0, 2, 24.5)
	test(8, 1, 71, 0, 2, 24.5)
	test(8, 3, 71, 0, 2, 30.7)
	test(13, 7, 154, 0, 2, 56.7)
	test(8, 3, 98, 0, 0, 84.4)
	test(21, 12, 102, 1, 3, 46.2)
	test(65, 43, 503, 2, 0, 99.7)
	test(17, 12, 126, 3, 1, 106.9)
	test(19, 14, 192, 1, 1, 101.2)
	test(19, 16, 192, 1, 1, 104.4)
	test(19, 18, 192, 1, 1, 104.4)
	test(16, 11, 223, 2, 1, 125.0)
	test(29, 24, 412, 4, 0, 158.3)
	test(15, 12, 276, 3, 0, 158.3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, c, y, t, i, r float64) {
	v := rate(n, c, y, t, i)
	fmt.Printf("%.1f\n", v)
	assert(math.Abs(v-r) < 1e-1)
}

func rate(n, c, y, t, i float64) float64 {
	Q := 2.375
	k0 := max(min(Q, 5*c/n-1.5), 0)
	k1 := max(min(Q, (y/n-3)/4), 0)
	k2 := min(Q, 20*t/n)
	k3 := max(0, Q-25*i/n)
	return (k0 + k1 + k2 + k3) / .06
}
