/*

Richard Dawkins in his book The Blind Watchmaker, describes a Weasel program. The algorithm can be described as follows:

Start with a random string of 28 characters. Valid characters are all upppercase letters, and space.

Make 100 copies of that string, with a 5% chance per character of that character being replaced with a random character.

Compare each new string with the target "METHINKS IT IS LIKE A WEASEL", and give each a score according to the number of letters in the string which are correct and in the correct position.

If any of the new strings has a perfect score (28), halt.

Choose the highest-scoring string from step 3. How you work out a tie is up to you, but only one string may be chosen. Take the chosen string and go to step 2.

The winner will be the shortest code snippet to get to the correct answer while printing the highest-scoring string of each generation in the following format:

https://i.sstatic.net/JhRcM.png

If people could help by checking other peoples answers would be very helpful!

*/

package main

import (
	"bytes"
	"errors"
	"fmt"
	"math"
	"math/rand"
)

func main() {
	morph("METHINKS IT IS LIKE A WEASEL")
}

func morph(s string) error {
	n := len(s)
	t := initial(n)
	for i := 0; i < math.MaxInt; i++ {
		v := score(s, t)
		fmt.Printf("%d: %s -- score: %d\n", i, t, v)
		if v == n {
			return nil
		}
		t = evolve(s, t, v)
	}
	return errors.New("no convergence")
}

func initial(n int) string {
	w := new(bytes.Buffer)
	for range n {
		i := rand.Intn(len(SYM))
		w.WriteByte(SYM[i])
	}
	return w.String()
}

func mutate(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		if rand.Intn(100) <= 5 {
			i := rand.Intn(len(SYM))
			r = rune(SYM[i])
		}
		w.WriteRune(r)
	}
	return w.String()
}

func evolve(s, t string, v int) string {
	r, m := t, v
	for range 100 {
		p := mutate(t)
		u := score(s, p)
		if u > m {
			r, m = p, u
		}
	}
	return r
}

func score(s, t string) int {
	r := 0
	for i := range s {
		if s[i] == t[i] {
			r++
		}
	}
	return r
}

const SYM = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 "
