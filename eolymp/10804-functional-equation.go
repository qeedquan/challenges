/*

Let f:R→R, x !=0.

2f(x) + f(1/x) = x

Given a value of x. Find the value of f(x).

Input
One real number x, x != 0.

Output
Print the value of f(x) with 4 decimal digits.

Examples
Input #1
1

Answer #1
0.3333

*/

package main

import "fmt"

func main() {
	fmt.Printf("%.4f\n", f(1))
}

/*

1. 2*f(x) + f(1/x) = x

Substitute x with 1/x
2. 2*f(1/x) + f(x) = 1/x

Multiply equation 1 by 2
3. 4*f(x) + 2*f(1/x) = 2*x

Subtract equation 2 from equation 3 to get rid of f(1/x)
4. 3*f(x) = 2*x - 1/x

Divide both side by 3
f(x) = (2*x*x - 1) / (3 * x)

*/

func f(x float64) float64 {
	return (2*x*x - 1) / (3 * x)
}
