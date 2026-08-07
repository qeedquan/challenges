/*

Each time when Pinocchio is not telling the truth his nose should become longer.

Task:
Write function which determines if pinocchio is telling the truth.

function extendPinocchiosNose(words){
  //return true if lying,false otherwise.
}

When pinocchio is lying he stutter a bit.If word1 is followed by word2 where word2 contains whole word1(case insensitive) you can tell that pinocchio is lying.

//lies examples
-"I am goo good person" //"good" contains "goo"
-"In real story they didnt hanged m me" //"me" contains "m"
-"It is geppetos fault,i would be Good good if not him" //"good" contains "Good"

*/

package main

import "strings"

func main() {
	assert(lying("I am goo good person") == true)
	assert(lying("In real story they didnt hanged m me") == true)
	assert(lying("It is geppetos fault,i would be Good good if not him") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lying(input string) bool {
	words := strings.Split(input, " ")
	for i := 1; i < len(words); i++ {
		if strings.Contains(strings.ToLower(words[i]), strings.ToLower(words[i-1])) {
			return true
		}
	}
	return false
}
