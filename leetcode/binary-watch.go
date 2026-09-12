/*

A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.

    For example, the below binary watch reads "4:51".

Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent.
You may return the answer in any order.

The hour must not contain a leading zero.

    For example, "01:00" is not valid. It should be "1:00".

The minute must be consist of two digits and may contain a leading zero.

    For example, "10:2" is not valid. It should be "10:02".

Example 1:

Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

Example 2:

Input: turnedOn = 9
Output: []

Constraints:

    0 <= turnedOn <= 10

*/

package main

import (
	"fmt"
	"math/bits"
	"reflect"
)

func main() {
	test(1, []string{"0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"})
	test(9, []string{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(b int, r []string) {
	p := binarywatch(b)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func binarywatch(b int) []string {
	r := []string{}
	for i := uint(0); i < 1024; i++ {
		if b == bits.OnesCount(i) {
			h, m := bin2time(i)
			if h < 12 && m < 60 {
				r = append(r, fmt.Sprintf("%d:%02d", h, m))
			}
		}
	}
	return r
}

func bin2time(v uint) (h, m uint) {
	h = (v >> 6) & 0x1f
	m = v & 0x3f
	return
}
