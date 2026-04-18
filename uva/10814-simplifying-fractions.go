/*

You are to write a program that reduces a fraction into its lowest terms.

Input
The first line of the input file gives the number of test cases N (≤ 20). Each of the following N lines
contains a fraction in the form of p/q (1 ≤ p, q ≤ 10^30).

Output
For each test case, output the fraction after simplification.

Sample Input
4
1 / 2
2 / 4
3 / 3
4 / 2

Sample Output
1 / 2
1 / 2
1 / 1
2 / 1

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(simplify("1/2"))
	fmt.Println(simplify("2/4"))
	fmt.Println(simplify("3/3"))
	fmt.Println(simplify("4/2"))
}

func simplify(s string) string {
	r := new(big.Rat)
	r.SetString(s)
	return r.String()
}
