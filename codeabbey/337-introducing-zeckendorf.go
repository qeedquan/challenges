/*

The Fibonacci series is very well known. Every number in the series (except for the first two numbers) is the sum of the previous two numbers. The first two numbers are usually taken to be 0 and 1. However, for the purpose of this problem we will take the first two numbers to be 1 and 2. This creates the Fibonacci series 1, 2, 3, 5, 8, 13, 21, 34, 55, ...

The Belgian mathematician Edouard Zeckendorf formulated an interesting theorem about the representation of integers as sums of Fibonacci numbers.

Zeckendorf's theorem states that every positive integer can be represented uniquely as the sum of one or more distinct Fibonacci numbers in such a way that the sum does not include any two consecutive Fibonacci numbers. For example, 50 = 3 + 13 + 34 is an allowed representation. Conversely 23 = 5 + 5 + 13 is not an allowed representation because of the repeated use of 5. 36 = 2 + 5 + 8 + 21 is also not an allowed representation because 5 and 8 are consecutive Fibonacci numbers.

In this problem you will be given some positive integers and are to represent each of these as a unique Zeckendorf sum. The numbers should be given in ascending order, separated by spaces. So the answer for 50 would be 3 13 34

Input/Output description: The first line of the input data will contain a single integer N, the number of values to convert.
N lines will follow. Each line contains a single number (less than 10^18). Convert the number to its Zeckendorf representation, in ascending order, separated by single spaces. Combine all answers into a single string, separated by spaces.

Example:

input:
5
50
256
731
5892
8888888

answer:
3 13 34 2 21 233 3 8 21 89 610 1 3 21 89 1597 4181 3 13 34 89 987 6765 46368 121393 832040 2178309 5702887

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(zeckendorf(50))
	fmt.Println(zeckendorf(256))
	fmt.Println(zeckendorf(731))
	fmt.Println(zeckendorf(5892))
	fmt.Println(zeckendorf(8888888))
}

func fib(n int) int {
	a := 0
	b := 1
	for range n {
		a, b = b, a+b
	}
	return a
}

func zeckendorf(n int) []int {
	if n < 0 {
		return []int{}
	}

	if n == 0 {
		return []int{0}
	}

	i := 1
	for ; i < n; i++ {
		if fib(i+1) > n {
			break
		}
	}

	r := []int{}
	for ; n > 0; i-- {
		v := fib(i)
		if v <= n {
			n -= v
			r = append(r, v)
		}
	}
	sort.Ints(r)
	return r
}
