/*

Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators.
You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Constraints:

1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].
The integer values in the input expression do not have a leading '-' or '+' denoting the sign.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
	"strconv"
	"strings"
)

func main() {
	test("2-1-1", []int{0, 2})
	test("2*3-4*5", []int{-34, -14, -10, -10, 10})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(expr string, expected []int) {
	result := compute(expr)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func compute(expr string) []int {
	result := recurse(expr)
	sort.Ints(result)
	return result
}

func recurse(expr string) []int {
	result := []int{}
	for i, symbol := range expr {
		if strings.IndexRune("+-*", symbol) < 0 {
			continue
		}

		lhs := recurse(expr[:i])
		rhs := recurse(expr[i+1:])
		for _, x := range lhs {
			for _, y := range rhs {
				switch symbol {
				case '+':
					result = append(result, x+y)
				case '-':
					result = append(result, x-y)
				case '*':
					result = append(result, x*y)
				}
			}
		}
	}

	if len(result) == 0 {
		value, _ := strconv.Atoi(expr)
		result = append(result, value)
	}

	return result
}
