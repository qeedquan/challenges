/*

You are given an integer N. Your job is to figure out how many substrings inside of N divide evenly with N.

Confused? I'll break it down for you.

Let's say that you are given the integer '877692'.

8 does not evenly divide with 877692. 877692/8 = 109711 with 4 remainder.

7 does not evenly divide with 877692. 877692/7 = 125384 with 4 remainder.

7 does not evenly divide with 877692. 877692/7 = 125384 with 4 remainder.

6 evenly divides with 877692. 877692/6 = 146282 with 0 remainder.

9 does not evenly divide with 877692. 877692/9 = 97521 with 3 remainder.

2 evenly divides with 877692. 877692/2 = 438846 with 0 remainder.

We aren't going to stop there though. We need to check ALL of the substrings inside of 877692.

87 does not evenly divide with 877692. 877692/87 = 10088 with 36 remainder.

77 does not evenly divide with 877692. 877692/77 = 11398 with 46 remainder.

76 does not evenly divide with 877692. 877692/76 = 11548 with 44 remainder.

69 does not evenly divide with 877692. 877692/69 = 12720 with 12 remainder.


etc.

Rules:

-If an integer is 0, then it does NOT divide evenly into anything.
-Even though N can divide evenly with itself, we do not count it towards the end number. For Example:

N = 23, the answer will be 0.

-If there are multiple instances of a number, they all get counted. For example:

N = 11, the answer will be 2

Input:

A non negative integer.
Output:

The number of times you found an integer that was evenly divisible with N.

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	assert(count(23) == 0)
	assert(count(11) == 2)
	assert(count(123) == 2)
	assert(count(1230) == 5)
	assert(count(1) == 0)
	assert(count(1111111111) == 25)
	assert(count(2431) == 1)
	assert(count(6234562222) == 5)
	assert(count(623456222222242) == 9)
	assert(count(623456222222) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A038769 (related)
func count(n int64) int64 {
	if n < 0 {
		return 0
	}

	s := fmt.Sprint(n)
	c := int64(0)
	for i := 0; i < len(s); i++ {
		for j := i + 1; j <= len(s); j++ {
			x, _ := strconv.ParseInt(s[i:j], 10, 64)
			if x != 0 && x != n && n%x == 0 {
				c++
			}
		}
	}
	return c
}
