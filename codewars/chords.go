/*

In Western music, a major chord (major third) starts at a root note and adds the note 4 semitones and 7 semitones above it.

A minor chord (minor third) starts at a root note and adds the note 3 semitones and 7 semitones above it.

Given a root note root, please return an array of the major chord and the minor chord for that root.

The notes are C, C#, D, D#, E, F, F#, G, G#, A, A#, B –– you are given this as a constant

For a music theory kata from a different point of view (figuring out whether a given set of notes is a major chord or minor chord or neither), try this kata from aniametz.

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	fmt.Println(chords("A"))
	fmt.Println(chords("C#"))
}

func chords(root string) [][2]string {
	notes := []string{"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"}
	index := slices.Index(notes, root)
	return [][2]string{
		{notes[(index+4)%12], notes[(index+7)%12]},
		{notes[(index+3)%12], notes[(index+7)%12]},
	}
}
