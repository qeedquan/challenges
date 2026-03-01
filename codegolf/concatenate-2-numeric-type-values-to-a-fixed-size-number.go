/*

You have 2 numbers, both stored separate as numeric data type.

First number is always 6 digits long.

Second number can vary between 1 and 4 digits. If it's less than 4 digits, it needs to be padded with numeric value 0.

End result always needs to be 10 digits number.

Order has to be respected. n1|n2

Example #1:

n1 = 111111
n2 = 2222
result = 1111112222
Example #2:

n1 = 333333
n2 = 44
result = 3333330044
The rule is that you can only use numeric data types (number, int, float, decimal) to get the desired result.

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	assert(concat(111111, 2222) == 1111112222)
	assert(concat(333333, 44) == 3333330044)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func concat(x, y uint64) uint64 {
	s := fmt.Sprintf("%d%04d", x, y)
	r, _ := strconv.ParseUint(s, 10, 64)
	return r
}
