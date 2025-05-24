/*

Define a regular expression which tests if a given string representing a binary number is divisible by 5.

Examples:
// 5 divisable by 5
divisibleByFive.test('101') === true

// 135 divisable by 5
divisibleByFive.test('10000111') === true

// 666 not divisable by 5
divisibleByFive.test('0000001010011010') === false
Note:
This can be solved by creating a Finite State Machine that evaluates if a string representing a number in binary base is divisible by given number.

The detailed explanation for dividing by 3 is here
https://math.stackexchange.com/questions/140283/why-does-this-fsm-accept-binary-numbers-divisible-by-three

The FSM diagram for dividing by 5 is here

https://aswitalski.github.io/img/FSM-binary-divisible-by-five.png

*/

package main

import (
	"fmt"
	"regexp"
)

func main() {
	for i := range 1000000 {
		s := fmt.Sprintf("%b", i)
		if isdiv5.MatchString(s) {
			assert(i%5 == 0)
		} else {
			assert(i%5 != 0)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var isdiv5 = regexp.MustCompile(`^0*(0|((1(10)*(0|11)((10*1(((10)*0)|(1(01)*1)))|(01*0(((01)*1)|((01)*00))))*10*)))$`)
