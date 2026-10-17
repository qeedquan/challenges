/*

Two students are giving each other test answers during a test. They don't want to be caught so they are sending each other coded messages.

For example one student is sending the following message: "Answer to Number 5 Part b". He starts with a square grid (in this example a 5x5 grid) and he writes the message down, including with spaces:

Answe
r to
Numbe
r 5 P
art b
He then starts writing the message down one column at a time, from the top to the bottom. The encoded message is now: "ArNran u rstm5twob  e ePb"

You are the teacher of this class. Your job is to decipher the messages and bust the students.

Task
Complete the function that takes one parameter (the encoded message) and return the original message.

Note: The length of the string is always going to be a perfect square.

Have fun !!!

*/

package main

import "math"

func main() {
	assert(decipher("ArNran u rstm5twob  e ePb") == "Answer to Number 5 Part b")
	assert(decipher("ArNran u rstm8twob  e ePc") == "Answer to Number 8 Part c")
	assert(decipher("7660yyyay59y9y85") == "7yy96y5y6y980ay5")
	assert(decipher(" 5y7622a067 8y62") == " 608526yy2767a 2")
	assert(decipher("9y98a877a95976a758726a89a5659957ya y") == "9777a5y762579aa66y897a5aa5589 89899y")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func decipher(message string) string {
	output := ""
	for count := 0; len(output) < len(message); count++ {
		for index := count; index < len(message); {
			output += string(message[index])
			index += isqrt(len(message))
		}
	}
	return output
}

func isqrt(x int) int {
	return int(math.Sqrt(float64(x)))
}
