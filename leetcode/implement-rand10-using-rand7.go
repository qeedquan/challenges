/*

Given the API rand7() that generates a uniform random integer in the range [1, 7], write a function rand10() that generates a uniform random integer in the range [1, 10]. You can only call the API rand7(), and you shouldn't call any other API. Please do not use a language's built-in random API.

Each test case will have one internal argument n, the number of times that your implemented function rand10() will be called while testing. Note that this is not an argument passed to rand10().

Example 1:

Input: n = 1
Output: [2]
Example 2:

Input: n = 2
Output: [2,8]
Example 3:

Input: n = 3
Output: [3,8,10]


Constraints:

1 <= n <= 10^5


Follow up:

What is the expected value for the number of calls to rand7() function?
Could you minimize the number of calls to rand7()?

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	test(1e3)
	test(1e4)
	test(1e6)
}

func test(n int) {
	var h [10]int
	for i := 0; i < n; i++ {
		h[rand10()-1]++
	}

	fmt.Printf("N=%v\n", n)
	for i := range h {
		fmt.Printf("%.3f%% ", float64(h[i])/float64(n)*100)
	}
	fmt.Printf("\n\n")
}

func rand10() int {
	r := 0
	for i := 0; i < 10; i++ {
		r += rand.Intn(7) + 1
	}
	return r%10 + 1
}
