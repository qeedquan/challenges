/*

A customer came to the market and decided to buy two watermelons.
He wanted to experiment by buying the heaviest and the lightest watermelons.
But there is one problem: there are many watermelons and he does not know how to choose the lightest and the heaviest one. Help him!

Input
The first line contains the number of watermelons n (n≤30000).
The second line contains n numbers, each number is the mass of the corresponding watermelon.
All weights of watermelons are positive integers and do not exceed 30000.

Output
Print two numbers: the weight of the lightest watermelon and the weight of the heaviest watermelon the customer will buy,
or print the message Ooops! (without quotes), if there are not enough watermelons.

Examples

Input #1
5
5 1 6 5 9

Answer #1
1 9

Input #2
1
5

Answer #2
Ooops!

Input #3
2
30000 30000

Answer #3
30000 30000

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	fmt.Println(solve([]int{5, 1, 6, 5, 9}))
	fmt.Println(solve([]int{5}))
	fmt.Println(solve([]int{30000, 30000}))
}

func solve(a []int) any {
	if len(a) < 2 {
		return "Ooops!"
	}
	return [2]int{
		slices.Min(a),
		slices.Max(a),
	}
}
