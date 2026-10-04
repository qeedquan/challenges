/*

In this challenge, you should take input as a number between 0 and 11 inclusive and a (possibly empty) list of the following strings/notes:

C Db D Eb E F Gb G Ab A Bb B
You are required to output flat notes, not sharp notes.
Also, notes cannot contain more than one flat sign (Bbb is not allowed), and notes that can be written without a flat sign must not be written with one (Fb and Cb are not allowed).

The strings each represent a note in the chromatic scale. Your output should be the list of notes ‘transposed’ up with the input number of semitones. For example, the input

1, C D E F Eb Db B
should output

Db Eb F Gb E D C
. In other words, for each note in the sequence, output the one n notes up, wrapping from B to C if necessary.

Examples:

0, A B C Db Eb -> A B C Db Eb
1, C D E F G A B -> Db Eb F Gb Ab Bb C
2, Db Eb Gb Ab Bb -> Eb F Ab Bb C
7, C D Eb F G -> G A Bb C D
11, G E E -> Gb Eb Eb
5, (empty) -> (empty)

This is code-golf, so fewest bytes wins!

*/

package main

import (
	"slices"
	"strings"
)

func main() {
	assert(transpose(0, "A B C Db Eb") == "A B C Db Eb")
	assert(transpose(1, "C D E F G A B") == "Db Eb F Gb Ab Bb C")
	assert(transpose(2, "Db Eb Gb Ab Bb") == "Eb F Ab Bb C")
	assert(transpose(7, "C D Eb F G") == "G A Bb C D")
	assert(transpose(11, "G E E") == "Gb Eb Eb")
	assert(transpose(5, "") == "")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func transpose(semitones int, notes string) string {
	table := []string{
		"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B",
	}

	result := []string{}
	for _, note := range strings.Fields(notes) {
		index := slices.Index(table, note)
		if index < 0 {
			return "invalid"
		}
		result = append(result, table[(index+semitones)%12])
	}
	return strings.Join(result, " ")
}
