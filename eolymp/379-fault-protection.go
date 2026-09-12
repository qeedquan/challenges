/*

Vitya really loves inventing things.
One day he decided to build a robot for his mother that would feed the fish in the aquarium.
Fish are delicate creatures; they must be fed strictly according to a given schedule, so Vitya wants to pay special attention to the robot's reliability.
Vitya took into account that the robot will have to open the aquarium, so there is a risk of water reaching the microchips.
But clever Vitya came up with a complex fault-protection system based on parity control of the binary representation of the commands executed by the robot.
Moreover, for different types of commands, Vitya decided to use different parity principles — for some commands a parity-even system will be used,
and for others — a parity-odd system.

Vitya knows that a bit sequence has an odd parity bit if the number of 1's is odd.
Conversely, a sequence has an even parity bit if the number of 1's is even.
Zero is considered an even number; therefore, a sequence without 1's has an even parity bit.
Vitya even wants to hint that the number of zeros does not affect the parity bit of the sequence.

Input
The input file contains a single line. This line contains from 1 to 31 bits and ends with the letter 'e' or 'o'.

Output
Print the corresponding bit sequence that ends with the parity bit:

even, if the line ended with the character 'e',

odd, if the line ended with the character 'o'.

Examples

Input #1
101e

Answer #1
1010

*/

package main

import "bytes"

func main() {
	assert(solve("101e") == "1010")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(input string) string {
	ones := 0
	for _, symbol := range input {
		if symbol == '1' {
			ones += 1
		}
	}

	index := len(input) - 1
	if index < 0 {
		return "invalid"
	}
	symbol := input[index]

	output := new(bytes.Buffer)
	output.WriteString(input[:index])
	switch {
	case symbol == 'e' && ones%2 == 0:
		fallthrough
	case symbol == 'o' && ones%2 == 1:
		output.WriteRune('0')
	default:
		output.WriteRune('1')
	}
	return output.String()
}
