/*

Description

Your rich uncle died recently, and the heritage needs to be divided among your relatives and the church (your uncle insisted in his will that the church must get something). There are N relatives (N <= 18) that were mentioned in the will. They are sorted in descending order according to their importance (the first one is the most important). Since you are the computer scientist in the family, your relatives asked you to help them. They need help, because there are some blanks in the will left to be filled. Here is how the will looks:

Relative #1 will get 1 / ... of the whole heritage,
Relative #2 will get 1 / ... of the whole heritage,
---------------------- ...
Relative #n will get 1 / ... of the whole heritage.

The logical desire of the relatives is to fill the blanks in such way that the uncle's will is preserved (i.e the fractions are non-ascending and the church gets something) and the amount of heritage left for the church is minimized.

Input

The only line of input contains the single integer N (1 <= N <= 18).

Output

Output the numbers that the blanks need to be filled (on separate lines), so that the heritage left for the church is minimized.

Sample Input

2

Sample Output

2
3

Source

ural 1108

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	for i := 0; i < 2; i++ {
		fmt.Println(sylvester(i))
	}
}

// https://oeis.org/A000058
func sylvester(n int) *big.Int {
	one := big.NewInt(1)

	r := big.NewInt(2)
	for i := 0; i < n; i++ {
		x := new(big.Int)
		y := new(big.Int)

		x.Mul(r, r)
		y.Neg(r)

		x.Add(x, y)
		x.Add(x, one)
		r.Set(x)
	}
	return r
}
