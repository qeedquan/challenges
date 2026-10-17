/*

--- Day 21: Scrambled Letters and Hash ---
The computer system you're breaking into uses a weird scrambling function to store its passwords. It shouldn't be much trouble to create your own scrambled password so you can add it to the system; you just have to implement the scrambler.

The scrambling function is a series of operations (the exact list is provided in your puzzle input). Starting with the password to be scrambled, apply each operation in succession to the string. The individual operations behave as follows:

swap position X with position Y means that the letters at indexes X and Y (counting from 0) should be swapped.
swap letter X with letter Y means that the letters X and Y should be swapped (regardless of where they appear in the string).
rotate left/right X steps means that the whole string should be rotated; for example, one right rotation would turn abcd into dabc.
rotate based on position of letter X means that the whole string should be rotated to the right based on the index of letter X (counting from 0) as determined before this instruction does any rotations. Once the index is determined, rotate the string to the right one time, plus a number of times equal to that index, plus one additional time if the index was at least 4.
reverse positions X through Y means that the span of letters at indexes X through Y (including the letters at X and Y) should be reversed in order.
move position X to position Y means that the letter which is at index X should be removed from the string, then inserted such that it ends up at index Y.
For example, suppose you start with abcde and perform the following operations:

swap position 4 with position 0 swaps the first and last letters, producing the input for the next step, ebcda.
swap letter d with letter b swaps the positions of d and b: edcba.
reverse positions 0 through 4 causes the entire string to be reversed, producing abcde.
rotate left 1 step shifts all letters left one position, causing the first letter to wrap to the end of the string: bcdea.
move position 1 to position 4 removes the letter at position 1 (c), then inserts it at position 4 (the end of the string): bdeac.
move position 3 to position 0 removes the letter at position 3 (a), then inserts it at position 0 (the front of the string): abdec.
rotate based on position of letter b finds the index of letter b (1), then rotates the string right once plus a number of times equal to that index (2): ecabd.
rotate based on position of letter d finds the index of letter d (4), then rotates the string right once, plus a number of times equal to that index, plus an additional time because the index was at least 4, for a total of 6 right rotations: decab.
After these steps, the resulting scrambled password is decab.

Now, you just need to generate a new scrambled password and you can access the system. Given the list of scrambling operations in your puzzle input, what is the result of scrambling abcdefgh?

--- Part Two ---
You scrambled the password correctly, but you discover that you can't actually modify the password file on the system. You'll need to un-scramble one of the existing passwords by reversing the scrambling process.

What is the un-scrambled version of the scrambled password fbgdceah?

*/

package main

import (
	"bufio"
	"bytes"
	"fmt"
	"log"
	"os"
	"slices"
	"strings"
)

type Op struct {
	code     int
	position [2]int
	letter   [2]byte
}

const (
	SWAP_POSITION = iota + 1
	SWAP_LETTER
	ROTATE_LEFT
	ROTATE_RIGHT
	ROTATE_LETTER_LEFT
	ROTATE_LETTER_RIGHT
	REVERSE
	MOVE
)

func main() {
	ops, err := load("21.txt")
	if err != nil {
		log.Fatal(err)
	}

	part1([]byte("abcdefgh"), ops)
	part2([]byte("fbgdceah"), ops)
}

func part1(input []byte, ops []Op) {
	fmt.Printf("%s\n", execute(input, ops))
}

func part2(input []byte, ops []Op) {
	slices.Reverse(ops)
	for index := range ops {
		ops[index] = inverse(ops[index])
	}
	fmt.Printf("%s\n", execute(input, ops))
}

func load(name string) (ops []Op, err error) {
	file, err := os.Open(name)
	if err != nil {
		return
	}
	defer file.Close()

	parses := []struct {
		code   int
		kind   int
		format string
	}{
		{SWAP_POSITION, 'D', "swap position %d with position %d"},
		{SWAP_LETTER, 'C', "swap letter %c with letter %c"},
		{ROTATE_LEFT, 'd', "rotate left %d"},
		{ROTATE_RIGHT, 'd', "rotate right %d"},
		{ROTATE_LETTER_RIGHT, 'c', "rotate based on position of letter %c"},
		{REVERSE, 'D', "reverse positions %d through %d"},
		{MOVE, 'D', "move position %d to position %d"},
	}

	scanner := bufio.NewScanner(file)
loop:
	for scanner.Scan() {
		line := scanner.Text()
		line = strings.TrimSpace(line)

		var op Op
		for _, parse := range parses {
			switch parse.kind {
			case 'D':
				_, err = fmt.Sscanf(line, parse.format, &op.position[0], &op.position[1])
			case 'C':
				_, err = fmt.Sscanf(line, parse.format, &op.letter[0], &op.letter[1])
			case 'd':
				_, err = fmt.Sscanf(line, parse.format, &op.position[0])
			case 'c':
				_, err = fmt.Sscanf(line, parse.format, &op.letter[0])
			}
			if err == nil {
				op.code = parse.code
				ops = append(ops, op)
				continue loop
			}
		}
		return nil, fmt.Errorf("Failed to parse line: %q", line)
	}
	return
}

func execute(input []byte, ops []Op) (output []byte) {
	defer func() {
		if err := recover(); err != nil {
			output = nil
		}
	}()

	for _, op := range ops {
		switch op.code {
		case SWAP_POSITION:
			swap_position(input, op.position[0], op.position[1])

		case SWAP_LETTER:
			swap_letter(input, op.letter[0], op.letter[1])

		case ROTATE_LEFT:
			rotate(input, op.position[0])

		case ROTATE_RIGHT:
			rotate(input, len(input)-op.position[0])

		case ROTATE_LETTER_LEFT:
			rotate_letter_left(input, op.letter[0])

		case ROTATE_LETTER_RIGHT:
			rotate_letter_right(input, op.letter[0])

		case REVERSE:
			reverse(input, op.position[0], op.position[1]+1)

		case MOVE:
			input = move(input, op.position[0], op.position[1])
		}
	}
	return input
}

func inverse(op Op) Op {
	switch op.code {
	case ROTATE_LEFT:
		op.code = ROTATE_RIGHT
	case ROTATE_RIGHT:
		op.code = ROTATE_LEFT
	case ROTATE_LETTER_LEFT:
		op.code = ROTATE_LETTER_RIGHT
	case ROTATE_LETTER_RIGHT:
		op.code = ROTATE_LETTER_LEFT
	case MOVE:
		op.position[0], op.position[1] = op.position[1], op.position[0]
	}
	return op
}

func swap_position(input []byte, index0, index1 int) {
	input[index0], input[index1] = input[index1], input[index0]
}

func swap_letter(input []byte, letter0, letter1 byte) {
	for index, letter := range input {
		if letter == letter0 {
			letter = letter1
		} else if letter == letter1 {
			letter = letter0
		}
		input[index] = letter
	}
}

func rotate(input []byte, shift int) {
	slices.Reverse(input[:shift])
	slices.Reverse(input[shift:])
	slices.Reverse(input)
}

func rotate_letter_left(input []byte, letter byte) {
	offsets := []int{1, 1, 6, 2, 7, 3, 0, 4}
	index := bytes.IndexByte(input, letter)
	rotate(input, offsets[index]%len(input))
}

func rotate_letter_right(input []byte, letter byte) {
	offsets := []int{1, 2, 3, 4, 6, 7, 0, 1}
	index := bytes.IndexByte(input, letter)
	rotate(input, len(input)-(offsets[index]%len(input)))
}

func reverse(input []byte, from, to int) {
	slices.Reverse(input[from:to])
}

func move(input []byte, from, to int) []byte {
	letter := input[from]
	input = slices.Delete(input, from, from+1)
	input = slices.Insert(input, to, letter)
	return input
}
