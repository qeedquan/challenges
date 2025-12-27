/*

It is easy to see that for every fraction in the form 1/k(k > 0), we can always find two positive integers x and y, x ≥ y, such that:
1/k = 1/x + 1/y

Now our question is: can you write a program that counts how many such pairs of x and y there are for any given k?

Input
Input contains no more than 100 lines, each giving a value of k (0 < k ≤ 10000).

Output
For each k, output the number of corresponding (x, y) pairs, followed by a sorted list of the values of x and y, as shown in the sample output.

Sample Input
2
12

Sample Output
2
1/2 = 1/6 + 1/3
1/2 = 1/4 + 1/4
8
1/12 = 1/156 + 1/13
1/12 = 1/84 + 1/14
1/12 = 1/60 + 1/15
1/12 = 1/48 + 1/16
1/12 = 1/36 + 1/18
1/12 = 1/30 + 1/20
1/12 = 1/28 + 1/21
1/12 = 1/24 + 1/24

*/

package main

import (
	"fmt"
	"math/big"
	"reflect"
)

func main() {
	test(2, []string{
		"1/2 = 1/6 + 1/3",
		"1/2 = 1/4 + 1/4",
	})
	test(12, []string{
		"1/12 = 1/156 + 1/13",
		"1/12 = 1/84 + 1/14",
		"1/12 = 1/60 + 1/15",
		"1/12 = 1/48 + 1/16",
		"1/12 = 1/36 + 1/18",
		"1/12 = 1/30 + 1/20",
		"1/12 = 1/28 + 1/21",
		"1/12 = 1/24 + 1/24",
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(k int64, r []string) {
	p := pairs(k)
	fmt.Println(len(p))
	for _, s := range p {
		fmt.Println(s)
	}
	fmt.Println()
	assert(reflect.DeepEqual(p, r))
}

func pairs(k int64) []string {
	one := big.NewInt(1)

	p := []string{}
	K := big.NewRat(1, k)
	X := new(big.Rat)
	for y := int64(1); y <= 2*k; y++ {
		Y := big.NewRat(1, y)
		X.Sub(K, Y)

		N1 := X.Num()
		D1 := X.Denom()
		D2 := Y.Denom()
		if N1.Cmp(one) == 0 && D1.Cmp(D2) >= 0 {
			p = append(p, fmt.Sprintf("1/%v = 1/%v + 1/%v", k, D1, D2))
		}
	}
	return p
}
