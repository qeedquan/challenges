/*

Description

Simulate a locked spinner puzzle.

A locked spinner puzzle is a puzzle where you can only change wheels in groups. It is a common puzzle to achieve some value on the spinners by only changing them in the allowed groups.

Imagine a row of D numbered wheels, each labeled sequentially with the digits 0 through 9. This is similar to what is on a briefcase combination lock.

Below this are a series of B buttons with labels that are D digits long. For example, D may be 4 and the labels are 1000 1200 1002 0111 and 0100. Pressing the button labeled 1000 moves the first wheel once, but leaves the others alone, while pressing the button labeled 1002 moves the first wheel once and the fourth wheel twice, leaving the center wheels unchanged.

Your task is to simulate such a locked spinner puzzle giving the final readout of the wheels.

Input

The input to your program will be a line containing D digits (at most 10) representing the starting positions of the wheels. Following this, each line will have the button label for which button is pressed next.There will always be at least 1 digit

Output

Output the final positions of the wheels.

Sample Input

0001
1003
0206
0034
1111
1003

Sample Output

3348

Source

Rocky Mountain 2003

*/

package main

import (
	"bytes"
)

func main() {
	assert(final([]string{
		"0001",
		"1003",
		"0206",
		"0034",
		"1111",
		"1003",
	}) == "3348")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func final(s []string) string {
	n := len(s)
	if n == 0 {
		return ""
	}

	x := convb(s[0])
	for i := 1; i < n; i++ {
		y := convb(s[i])
		for j := range x {
			x[j] = (x[j] + y[j]) % 10
		}
	}
	return convs(x)
}

func convb(s string) []byte {
	b := make([]byte, len(s))
	for i := range b {
		b[i] = s[i] - '0'
	}
	return b
}

func convs(b []byte) string {
	w := new(bytes.Buffer)
	for i := range b {
		w.WriteByte(b[i] + '0')
	}
	return w.String()
}
