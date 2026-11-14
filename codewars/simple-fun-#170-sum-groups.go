/*

Given an array of integers, sum consecutive even numbers and consecutive odd numbers. Repeat the process while it can be done and return the length of the final array.

## Example

For arr = [2, 1, 2, 2, 6, 5, 0, 2, 0, 5, 5, 7, 7, 4, 3, 3, 9]

The result should be 6.


[2, 1, 2, 2, 6, 5, 0, 2, 0, 5, 5, 7, 7, 4, 3, 3, 9]  -->
         2+2+6       0+2+0     5+5+7+7       3+3+9
[2, 1,   10,    5,    2,        24,     4,   15   ] -->
                               2+24+4
[2, 1,   10,    5,             30,           15   ]
The length of final array is 6


## Input/Output

- [input] integer array arr

  A non-empty array,

  1 ≤ arr.length ≤ 1000

  0 ≤ arr[i] ≤ 1000


- [output] an integer

  The length of the final array

*/

package main

import (
	"bytes"
	"regexp"
)

func main() {
	assert(sumgroups([]int{2, 1, 2, 2, 6, 5, 0, 2, 0, 5, 5, 7, 7, 4, 3, 3, 9}) == 6)
	assert(sumgroups([]int{2, 1, 2, 2, 6, 5, 0, 2, 0, 3, 3, 3, 9, 2}) == 5)
	assert(sumgroups([]int{1, 1, 2, 2}) == 1)
	assert(sumgroups([]int{1, 2}) == 2)
	assert(sumgroups([]int{2}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sumgroups(a []int) int {
	re0 := regexp.MustCompile("1(11)*")
	re1 := regexp.MustCompile("(0|11)+")

	w := new(bytes.Buffer)
	for _, v := range a {
		w.WriteRune('0' + rune(v&1))
	}

	s := re0.ReplaceAllString(w.String(), "1")
	s = re1.ReplaceAllString(s, "0")
	return len(s)
}
