/*

Task
You are given a digital number written down on a sheet of paper.

Your task is to figure out if you rotate the given sheet of paper by 180 degrees would the number still look exactly the same.


Example
For number = "1", the result should be false

For number = "29562", the result should be true.

For number = "77", the result should be false.

Input/Output
[input] string number
sequence of digital digits given as a string.

[output] a boolean value
true if you rotate the given sheet of paper by 180 degrees then the number still look exactly the same. false otherwise.

*/

package main

func main() {
	assert(rotatepaper("1") == false)
	assert(rotatepaper("29562") == true)
	assert(rotatepaper("77") == false)
	assert(rotatepaper("96") == true)
	assert(rotatepaper("689") == true)
	assert(rotatepaper("56789") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rotatepaper(s string) bool {
	lut := map[byte]byte{
		'0': '0',
		'2': '2',
		'5': '5',
		'6': '9',
		'8': '8',
		'9': '6',
	}

	n := len(s)
	for i := range n/2 + n%2 {
		if s[i] != lut[s[n-i-1]] || lut[s[i]] == 0 {
			return false
		}
	}
	return true
}
