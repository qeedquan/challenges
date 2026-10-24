/*

You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

Return the largest possible value of num after any number of swaps.

Example 1:

Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
Example 2:

Input: num = 65875
Output: 87655
Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.
Swap the first digit 5 with the digit 7, this results in the number 87655.
Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.


Constraints:

1 <= num <= 10^9

*/

package main

import (
	"fmt"
	"sort"
	"strconv"
)

func main() {
	assert(largest(1234) == 3412)
	assert(largest(65875) == 87655)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func largest(n uint64) uint64 {
	b := []byte(fmt.Sprint(n))
	e := xs{}
	o := xs{}
	for i, v := range b {
		if v&1 == 0 {
			e = append(e, &b[i])
		} else {
			o = append(o, &b[i])
		}
	}

	sort.Sort(e)
	sort.Sort(o)

	r, _ := strconv.ParseUint(string(b), 0, 64)
	return r
}

type xs []*byte

func (x xs) Len() int           { return len(x) }
func (x xs) Less(i, j int) bool { return *x[i] > *x[j] }
func (x xs) Swap(i, j int)      { *x[i], *x[j] = *x[j], *x[i] }
