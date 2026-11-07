/*

Another problem from "coding" interview section with T-Bank, it preceded Cheapest Bus Tickets and is simpler but allows a handful of implementations, differing in their qualities.

Paolo Durno founds his keyboard has a key B broken. But it not simply just "not types in the char"! Besides this obvious effect, it mystically deletes some one of preceding characters: either the nearest previous capital or small letter, depending on whether the button was pressed with Shift or without (i.e. whether B or b was to be typed).

The goal is, by the given string, to produce the result of typing it with this curious keyboard.

Input provides a count of testcases to follow in the first line.
Next lines contain single testcase each, in a form of strings, consisting only of latin letters.

Answer should provide resulting malformed strings, space separated.

Example:

input:

1
YetAnotherBrokenKeyboard

answer:

YetnotherrokenKeoard

*/

package main

import (
	"bytes"
	"unicode"
)

func main() {
	assert(solve("YetAnotherBrokenKeyboard") == "YetnotherrokenKeoard")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(input string) string {
	uppers := []int{}
	lowers := []int{}
	buffer := []rune{}
	index := 0
	for _, symbol := range input {
		switch symbol {
		case 'B':
			uppers = pop(uppers, buffer)
		case 'b':
			lowers = pop(lowers, buffer)
		default:
			buffer = append(buffer, symbol)
			if unicode.IsUpper(symbol) {
				uppers = append(uppers, index)
			} else if unicode.IsLower(symbol) {
				lowers = append(lowers, index)
			}
			index += 1
		}
	}

	output := new(bytes.Buffer)
	for _, symbol := range buffer {
		if symbol >= 0 {
			output.WriteRune(symbol)
		}
	}
	return output.String()
}

func pop(positions []int, buffer []rune) []int {
	size := len(positions)
	if size > 0 {
		index := positions[size-1]
		buffer[index] = -1
		positions = positions[:size-1]
	}
	return positions
}
