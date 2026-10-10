/*

The challenge is simple:

generate a word.
Specifications:

Word must be pronounceable.
This is defined as "alternating between a consonant and a vowel."
A consonant is one of the following letters: bcdfghjklmnpqrstvwxz
A vowel is one of the following letters: aeiouy
Word must be randomly generated.
Words must be able to contain every consonant and vowel. (You can't just use bcdf for consonants and aei for vowels.)
Word must contain 10 letters.
Shortest code (in character count) wins.

*/

package main

import (
	"bytes"
	"fmt"
	"math/rand"
)

func main() {
	for range 10 {
		fmt.Println(gen())
	}
}

func gen() string {
	sym := [2]string{"bcdfghjklmnpqrstvwxz", "aeiouy"}
	w := new(bytes.Buffer)
	i := rand.Intn(2)
	for range 10 {
		s := sym[i]
		n := rand.Intn(len(s))
		w.WriteByte(s[n])
		i = 1 - i
	}
	return w.String()
}
