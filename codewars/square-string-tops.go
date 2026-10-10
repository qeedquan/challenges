/*

Task
Write a function that accepts msg string and returns local tops of string from the highest to the lowest.
The string's tops are from displaying the string in the below way:


                                         7891012
                             TUWvXY      6     3
                   ABCDE     S    Z      5
           lmno    z   F     R    1      4
     abc   k  p    v   G     Q    2      3
.34..9 d...j  q....x   H.....P    3......2
125678 efghi  rstuwy   IJKLMNO    45678901

The next top is always 1 character higher than the previous one. For the above example, the solution for the 123456789abcdefghijklmnopqrstuwyxvzABCDEFGHIJKLMNOPQRSTUWvXYZ123456789012345678910123 input string is 7891012TUWvXYABCDElmnoabc34.

When the msg string is empty, return an empty string.
The input strings may be very long. Make sure your solution has good performance.
The (.)dots on the sample dispaly of string are only there to help you to understand the pattern

Check the test cases for more samples.

*/

package main

import (
	"slices"
)

func main() {
	assert(tops("") == "")
	assert(tops("abcde") == "cd")
	assert(tops("123456789abcdefghijklmnopqrstuwyxvzABCDEFGHIJKLMNOPQRSTU") == "TUABCDElmnoabc34")
	assert(tops("123456789abcdefghijklmnopqrstuwyxvzABCDEFGHIJKLMNOPQRSTUWvXYZ123456789012345678910123") == "7891012TUWvXYABCDElmnoabc34")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tops(message string) string {
	var (
		buffer [][]byte
		top    = 2
		step   = 5
		start  = 2
	)
	for start < len(message) {
		end := min(start+top, len(message))
		buffer = append(buffer, []byte(message[start:end]))
		start += top + step
		top += 1
		step += 3
	}

	output := []byte{}
	for i := range buffer {
		slices.Reverse(buffer[i])
		output = append(output, buffer[i]...)
	}
	slices.Reverse(output)
	return string(output)
}
