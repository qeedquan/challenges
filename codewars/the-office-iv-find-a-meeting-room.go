/*

Your job at E-Corp is both boring and difficult. It isn't made any easier by the fact that everyone constantly wants to have a meeting with you, and that the meeting rooms are always taken!

In this kata, you will be given an array. Each value represents a meeting room. Your job? Find the first empty one and return its index (N.B. There may be more than one empty room in some test cases).

'X' --> busy
'O' --> empty
If all rooms are busy, return "None available!"

*/

package main

import "strings"

func main() {
	assert(meeting("XOX") == 1)
	assert(meeting("OXXXX") == 0)
	assert(meeting("XXOXX") == 2)
	assert(meeting("X") == "None available!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func meeting(rooms string) any {
	index := strings.IndexRune(rooms, 'O')
	if index < 0 {
		return "None available!"
	}
	return index
}
