/*

The Narrative
You are a frog who is at the edge of a pond with waterlilies. You would like to cross the pond without getting wet, so you plan to jump from lily to lily. There is, however, one problem: you are a rare species of frog which can only jump one specific distance, and so you might not be able to cross the pond no matter what you do.

The Objective
Determine if the frog can cross the pond without getting wet.
Your program should take two inputs:

A string or list of lily-y/watery values to represent the lilies in the pond
A positive integer which tells how far the frog jumps
Your program should output a truthy/falsy value to indicate whether the pond is crossable

The frog can start any distance behind the edge of the pond, but may not start on a lily or in the water. Additionally, the frog may finish any distance beyond the far edge of the pond, but not on a lily or in the water. Note that the frog cannot move at any interval other than that which is specified in the input (i.e. With a jumping distance of 3, the pond 001100 is not crossable, even though it appears that the frog could walk from the first waterlily to the second)
Examples:

(lily=1, water=0)

Inputs: "001101001111001", "3"
Output: "Yes"

Inputs: "101001", "2"
Output: "No"

Inputs: "010000001", "7"
Output: "Yes"

Inputs: "00000", "6"
Output: "Yes"

Inputs: "00000", "5"
Output: "No"

Inputs: "00100100", "4"
Output: "No"

Inputs: "001100", "3"
Output: "No"

Inputs: "", "1"
Output: "Yes"

(note that output does not have to be "Yes" or "No", but any truthy/falsy values)
This is code-golf, so the shortest code in bytes wins.

*/

package main

func main() {
	assert(crossable("001101001111001", 3) == true)
	assert(crossable("101001", 2) == false)
	assert(crossable("010000001", 7) == true)
	assert(crossable("00000", 6) == true)
	assert(crossable("00000", 5) == false)
	assert(crossable("00100100", 4) == false)
	assert(crossable("001100", 3) == false)
	assert(crossable("", 1) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func crossable(s string, j int) bool {
	n := len(s)
	if n == 0 {
		return true
	}

loop:
	for i := 0; i < j; i++ {
		for p := i; p < n; p += j {
			if s[p] != '1' {
				continue loop
			}
		}
		return true
	}
	return false
}
