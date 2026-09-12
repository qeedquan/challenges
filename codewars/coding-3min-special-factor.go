/*

This is the simple version of Shortest Code series. If you need some challenges, please try the challenge version

Task:
Give you a positive integer n, find out the special factor.

What is the special factor? An example: if n has a factor x, we can convert them into binary string, if binary string of n contains binary string of x, we can say, x is a special factor of n.

Return an array, include all of the special factor(Ascending order)

Example:
Example1:
n = 6   factor of n: 1,2,3,6
convert them to binary string:
n ==> "110"
factors: 1==>"1"  2==>"10"  3==>"11"  6==>"110"
Hmmm... It seems "110" contains all of them.
So, sc(6) should return [1,2,3,6]

Example2:
n = 15   factor of n: 1,3,5,15
convert them to binary string:
n ==> "1111"
factors: 1==>"1"  3==>"11"  5==>"101"  15==>"1111"
Hmmm... "1","11","1111" are special factors, but "101" is not.
So, sc(15) should return [1,3,15]

Example3:
n = 100   factor of n: 1,2,4,5,10,20,25,50,100
convert them to binary string:
n ==> "1100100"
factors: 1==>"1"  2==>"10"  4==>"100"  5==>"101" 10==>"1010"
  20==>"10100"  25==>"11001"  50==>"110010"  100==>"1100100"
Hmmm... "1","10","100","11001","110010","1100100" are special factors,
"101","1010","10100" are not.
So, sc(100) should return [1,2,4,25,50,100]

*/

package main

import (
	"fmt"
	"slices"
	"strings"
)

func main() {
	test(6, []int{1, 2, 3, 6})
	test(15, []int{1, 3, 15})
	test(100, []int{1, 2, 4, 25, 50, 100})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r []int) {
	assert(slices.Equal(specialfactors(n), r))
}

func specialfactors(n int) []int {
	r := []int{}
	s := fmt.Sprintf("%b", n)
	for i := 1; i <= n; i++ {
		if n%i == 0 && strings.Index(s, fmt.Sprintf("%b", i)) >= 0 {
			r = append(r, i)
		}
	}
	return r
}
