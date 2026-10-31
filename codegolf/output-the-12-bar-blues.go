/*

Note to those without experience in music: Through making an attempt to solve this problem, you may find that music and computer programming are similar in the ways that they implement rules and syntax. With some help from Wikipedia, you can likely solve this problem with no prior knowledge of music theory.

Write a program that can take a string representing any valid key signature (ex: C, D#, Ab) and return the appropriate chord progression for a 12 bar blues in that key.

Many aspiring jazz musicians begin their musical journey by learning the 12 bar blues. It is a popular chord progression that consists of the I, IV, and V chords of a key.

There are a few variations of the 12 bar blues, we will use the following:

I   I   I   I
IV  IV  I   I
V   IV  I   I
Where each numeral represents the chords of the given key.

Examples

------------------------

Input:    C

Output:   C   C   C   C
          F   F   C   C
          G   F   C   C

------------------------

Input:    Eb

Output:   Eb  Eb  Eb  Eb
          Ab  Ab  Eb  Eb
          Bb  Ab  Eb  Eb

------------------------

Input:    F#

Output:   F#  F#  F#  F#
          B   B   F#  F#
          C#  B   F#  F#
Note: In music, you can write some notes two different ways. (ex: F# is equivalent to Gb). Consequently, a given input may have multiple valid answers. An answer is correct as long as it outputs chords that are correct, regardless of how they are represented.

Example - F# Alternative solution

Input:    F#

Output:   Gb  Gb  Gb  Gb
          Cb  Cb  Gb  Gb
          Db  Cb  Gb  Gb
Answers should be returned in one of the following formats:

Examples - Valid Formatting (Given input C)

Valid output 1 (multi-line string):
C   C   C   C
F   F   C   C
G   F   C   C

Valid output 2 (single line string):
C C C C F F C C G F C C

Valid output 3 (1d list/array):
['C', 'C', 'C', 'C', 'F', 'F', 'C', 'C', 'G', 'F', 'C', 'C']

Valid Output 4 (2d list/array):
[['C', 'C', 'C', 'C'],
 ['F', 'F', 'C', 'C'],
 ['G', 'F', 'C', 'C']]
This is code-golf: The solution with the fewest bytes wins.

Python 3 - Sample Code, not Golfed
def twelve_bar_blues(k_input):

	chords = ['Ab', 'A', 'Bb', 'B', 'C', 'Db', 'D', 'Eb', 'E', 'F', 'Gb', 'G']*2

	if k_input not in chords and k_input[1] == '#':
		k_index = chords.index(k_input[0]) + 1
		k = chords[k_index]
	else:
		k = k_input

	I_index = chords.index(k)
	I = chords[I_index]

	IV_index = I_index + 5
	IV = chords[IV_index]

	V_index = I_index + 7
	V = chords[V_index]

	return f'{I} {I} {I} {I} {IV} {IV} {I} {I} {V} {IV} {I} {I}'

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	assert(twelve_bar_blues("C") == "C C C C F F C C G F C C")
	assert(twelve_bar_blues("Eb") == "Eb Eb Eb Eb Ab Ab Eb Eb Bb Ab Eb Eb")
	assert(twelve_bar_blues("F#") == "Gb Gb Gb Gb B B Gb Gb Db B Gb Gb")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func twelve_bar_blues(key string) string {
	chords := []string{
		"Ab", "A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G",
		"Ab", "A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G",
	}

	i := slices.Index(chords, key)
	if i < 0 {
		i = slices.Index(chords, key[:1]) + 1
		if i <= 0 {
			return "invalid key"
		}
	}

	I := chords[i]
	IV := chords[i+5]
	V := chords[i+7]

	return fmt.Sprintf("%v %v %v %v %v %v %v %v %v %v %v %v",
		I, I, I, I, IV, IV, I, I, V, IV, I, I)
}
