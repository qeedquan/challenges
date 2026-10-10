/*

You will be given a positive, whole number (that will never contain a 0) as input. Your task is to check whether it is a Lynch-Bell number or not.

A number is a Lynch-Bell number if all of its digits are unique and the number is divisible by each of its digits.

In fact, there are actually only 548 Lynch-Bell numbers, so hard-coding is a possibility, but will almost certainly be longer.

126 is a Lynch-Bell number because all of its digits are unique, and 126 is divisible by 1, 2, and 6.

You can output any truthy and falsy value.

Examples:
7 -> truthy
126 -> truthy
54 -> falsy
55 -> falsy
3915 -> truthy
This is OEIS A115569.

*/

package main

import "fmt"

func main() {
	tab := []uint{1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 15, 24, 36, 48, 124, 126, 128, 132, 135, 162, 168, 175, 184, 216, 248, 264, 312, 315, 324, 384, 396, 412, 432, 612, 624, 648, 672, 728, 735, 784, 816, 824, 864, 936, 1236, 1248, 1296, 1326, 1362, 1368, 1395, 1632, 1692, 1764, 1824}

	for _, v := range tab {
		assert(lynchbell(v) == true)
	}

	assert(lynchbell(7) == true)
	assert(lynchbell(126) == true)
	assert(lynchbell(54) == false)
	assert(lynchbell(55) == false)
	assert(lynchbell(3915) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A115569
func lynchbell(n uint) bool {
	s := fmt.Sprint(n)
	m := make(map[rune]bool)
	for _, r := range s {
		m[r] = true
	}
	if len(m) < len(s) {
		return false
	}
	for i := range s {
		d := uint(s[i] - '0')
		if d == 0 || n%d != 0 {
			return false
		}
	}
	return true
}
