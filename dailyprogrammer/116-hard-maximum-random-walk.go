/*

Consider the classic random walk: at each step, you have a 1/2 chance of taking a step to the left and a 1/2 chance of taking a step to the right. Your expected position after a period of time is zero; that is the average over many such random walks is that you end up where you started. A more interesting question is what is the expected rightmost position you will attain during the walk.

Author: thePersonCSC

Formal Inputs & Outputs
Input Description
The input consists of an integer n, which is the number of steps to take (1 <= n <= 1000). The final two are double precision floating-point values L and R which are the probabilities of taking a step left or right respectively at each step (0 <= L <= 1, 0 <= R <= 1, 0 <= L + R <= 1). Note: the probability of not taking a step would be 1-L-R.

Output Description
A single double precision floating-point value which is the expected rightmost position you will obtain during the walk (to, at least, four decimal places).

Sample Inputs & Outputs
Sample Input
walk(1,.5,.5) walk(4,.5,.5) walk(10,.5,.4)

Sample Output
walk(1,.5,.5) returns 0.5000 walk(4,.5,.5) returns 1.1875 walk(10,.5,.4) returns 1.4965

Challenge Input
What is walk(1000,.5,.4)?

Challenge Input Solution
(No solution provided by author)

Note
Have your code execute in less that 2 minutes with any input where n <= 1000

I took this problem from the regional ACM ICPC of Greater New York.

*/

package main

import "fmt"

func main() {
	fmt.Println(walk(1, 0.5, 0.5))
	fmt.Println(walk(4, 0.5, 0.5))
	fmt.Println(walk(10, 0.5, 0.4))
	fmt.Println(walk(1000, 0.5, 0.4))
}

/*

@Cosmologicon

You can define the solution recursively, which can then be solved with
memoization in O(n^(2)) time/space, or with dynamic programming in O(n^(2)) time
and O(n) space. (I used memoization. A DP solution in C should be able to solve
it for 1000 steps in much less than 1 second.)

For simplicity, assume L and R are fixed. Let's say there's a "flag" at the
rightmost place you've visited. If you're standing at the flag and you step
right, you bring the flag with you, and if you step left, you leave the flag
behind. The question is what's the expected flag position after n steps?

walk(n,f) is the expected final location of the flag if you're currently
standing at 0, there are n steps remaining, and the flag is currently at f. If
you're currently standing at k, then by shifting the number line over by k steps
you can see that the expected final location of the flag is walk(n,f-k)+k. This
lets you get the expected final flag location for each of the three different
possibilities:

If you don't step in either direction this turn, it's E0 = walk(n-1,f)
If you step to the left this turn, k will be -1 and it's EL = walk(n-1,f+1)-1
If you step to the right this turn, k will be +1 and it's ER = walk(n-1,f-1)+1

Except that the flag can never be to your left, because you move it if you step
to the right. So replace f-1 with max(f-1,0). The recursive formula then is:

walk(n,f) = L * EL + R * ER + (1-L-R) * E0

You only need the base case that walk(0,f) = f.

*/

func walk(n int, L, R float64) float64 {
	return recurse(n, L, R, 0)
}

var cache = make(map[[4]any]float64)

func recurse(n int, L, R, f float64) float64 {
	if n < 1 {
		return f
	}

	k := [4]any{n, L, R, f}
	if x, ok := cache[k]; ok {
		return x
	}

	EL := recurse(n-1, L, R, f+1) - 1
	E0 := recurse(n-1, L, R, f)
	ER := recurse(n-1, L, R, max(f-1, 0)) + 1
	cache[k] = L*EL + R*ER + (1-L-R)*E0
	return cache[k]
}
