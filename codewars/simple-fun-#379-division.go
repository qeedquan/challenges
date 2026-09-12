/*

Task
You are given three positive integers t, a, b. Your task is to establish whether (t^a - 1)/(t^b -1) is an integer with less than 100 digits.

Return the result of (t^a - 1)/(t^b -1) in string format, if the result is an integer with less than 100 digits. Otherwise, return "Not an integer with less than 100 digits".

Still not understand the task? Look at the following example ;-)

Example
For t = 2, a = 9, b = 3, the output should be "73". Because:

(2^9-1)/(2^3-1) = 511/7 = 73
For t = 2, a = 3, b = 2, the output should be "Not an integer with less than 100 digits". Because:

(2^3-1)/(2^2-1) = 7/3 = 2.33333333...
For t = 123, a = 911, b = 1, the output should be "Not an integer with less than 100 digits". Because the result of (123^911 - 1)/(123^1 -1) is more than 100 digits.

Note
1 < t <= 100

1 < a <= 10000

1 < b <= 100

Because of obvious reasons, something like require("xxxx") was disabled. ;-)

Happy Coding ^_^

*/

package main

import (
	"math/big"
)

func main() {
	assert(division(2, 9, 3) == "73")
	assert(division(2, 3, 2) == "Not an integer with less than 100 digits")
	assert(division(21, 42, 7) == "18952884496956715554550978627384117011154680106")
	assert(division(123, 911, 1) == "Not an integer with less than 100 digits")
	assert(division(26, 72, 12) == "7914088058189701698257980774208334029257966300557096880872877892964775528040930938881")
	assert(division(3, 52, 2) == "807635236153334162366530")
	assert(division(5, 37, 1) == "18189894035458564758300781")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func division(t, a, b int64) string {
	x := raise(t, a)
	y := raise(t, b)

	q := new(big.Int)
	r := new(big.Int)
	q.Quo(x, y)
	r.Mod(x, y)

	s := q.String()
	if r.Cmp(zero) != 0 || len(s) >= 100 {
		return "Not an integer with less than 100 digits"
	}
	return s
}

func raise(t, p int64) *big.Int {
	x := big.NewInt(t)
	y := big.NewInt(p)
	x.Exp(x, y, nil)
	x.Sub(x, one)
	return x
}

var (
	zero = big.NewInt(0)
	one  = big.NewInt(1)
)
