/*

I have come across a question on the Code Review site that seems interesting. I think OP is doing it wrong, but cannot be sure... So let's solve it for him! (write a program, not a function/procedure)

Input (stdin or similar):
An integer x in decimal notation. It is greater than 1 and less than 2^31.

Output (stdout or similar):
An integer y in decimal notation. The product x * y in decimal representation must contain only digits 0 and 1. It must be the minimal such number greater than 0.

Note: output is not limited - if the minimal y is around 10^100, your program must output all of its 100 digits (I don't know whether there is a reasonable limit, like 2^64, on y - didn't solve it).

Your program should finish in a reasonable time (1 second? 1 hour? - something like that) for all x in range.

Bonus:
If your program doesn't have a limit on the size of the input (except RAM), and has polynomial complexity, multiply the byte count of your program by 0.8 and round down.

Example: Input 2; output 5, because 2 * 5 = 10

Example: Input 21; output 481, because 21 * 481 = 10101

Disclaimer: I am not responsible for the question on the Code Review site. In case of any discrepancy, only the description above should be regarded as proper spec.

OEIS A079339

*/

package main

import (
	"strconv"
)

func main() {
	tab := []int64{1, 5, 37, 25, 2, 185, 143, 125, 12345679, 1, 1, 925, 77, 715, 74, 625, 653, 61728395, 579, 5, 481, 5, 4787, 4625, 4, 385, 40781893, 3575, 37969, 37, 3581, 3125, 3367, 3265, 286, 308641975, 3, 2895, 259, 25, 271, 2405, 25607, 25, 24691358, 23935, 213, 23125}

	for i, v := range tab {
		assert(A079339(int64(i+1)) == v)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A079339
func A079339(n int64) int64 {
	if n < 1 {
		return 0
	}
	return A004290(n) / n
}

// https://oeis.org/A004290
func A004290(n int64) int64 {
	if n < 1 {
		return 0
	}
	for i := int64(1); i < 1<<n; i++ {
		s := strconv.FormatInt(i, 2)
		x, _ := strconv.ParseInt(s, 0, 64)
		if x%n == 0 {
			return x
		}
	}
	return -1
}
