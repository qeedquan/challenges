/*

Find f(n).

Input
The first line contains single integer t — the number of test cases.

The only line of each test case contains single integer n (1≤n≤10^6).

Output
The answer to the problem.

The answer will be considered correct if the absolute difference is no more than 10^-4.

Examples
Input #1
5
6
7
8
9
10

Answer #1
31991.2306
32132.2305
32317.2307
32552.2293
32843.2288


*/

package main

import (
	"fmt"
	"math"
)

func main() {
	for i := 6.0; i <= 10; i++ {
		fmt.Printf("%.4f\n", solve(i))
	}
}

/*

Editorial:


Notice that samples have numbers around some number +0.23 , at the same time notice the last term of the math expression is reduced to
676767/67×π=10101π≈31733.23

Now we need to get formula for integer part which can be got with samples pattern observation which is n^3+n^2+n thus the final formula is n^3+n^2+n+10101π.

*/

func solve(n float64) float64 {
	return n*n*n + n*n + n + 10101*math.Pi
}
