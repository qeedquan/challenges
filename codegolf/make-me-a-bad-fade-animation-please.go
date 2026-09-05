/*

Your task is to, as the title discreetly suggests, make a bad fade animation of one word turning into a second word for yours truly.

What exactly is this "fade animation" you may ask?

To make a spectacular(ly bad) fade animation, you take two strings which will contain only printable ASCII characters. You start by printing your starting string (the first of the two). Then, you randomly pick a character in the original word and change it to the corresponding character in the word you want to animate to. When the words are of unequal length, you must pad them with spaces.

You keep on doing this until all of the characters have been changed, but you will not change the character at a certain index more than once. Here is an example i/o:

Hey -> Peeps
Hey    # original string
Hey s  # replace char at index 4
Hey s  # replace char at index 1
Pey s  # replace char at index 0
Pee s  # replace char at index 2
Peeps  # replace char at index 3
You must write a function or full program that changes a letter and then prints the new string at increments of one second. The input format is loose, but the output format is strict.

This is code-golf, so shortest code in bytes wins.

Some test cases (Form: init -> final):

Stringy -> Blingy
Banana -> Republic
United -> States
Make America -> Tissue box
I like walls -> I have small hands
Hello, -> world!
Reference implementation in Python 2:

import random
import time
def F(c,f):
    print c                                      # before we do stuff
    if len(c)>len(f):f+=" "*(len(c)-len(f))      # add padding part 1
    if len(f)>len(c):c+=" "*(len(f)-len(c))      # add padding part 2
    c, f = list(c), list(f)
    ai = [i for i in range(len(c))]              # a list for keeping track
    while len(ai) > 0:                           #  of available indices
        time.sleep(1)                            # 1 second pause...
        i = ai.pop(random.randint(0,len(ai)-1))  # get a random index and remove
        c[i] = f[i]                              #   it from the list
        print ''.join(c)                         # print the new string

*/

package main

import (
	"fmt"
	"math/rand"
	"slices"
	"strings"
	"time"
)

func main() {
	fade("Hey", "Peeps")
	fade("Stringy", "Blingy")
	fade("Banana", "Republic")
	fade("United", "States")
	fade("Make America", "Tissue box")
	fade("I like walls", "I have small hands")
	fade("Hello,", "world!")
}

func fade(init, final string) {
	fmt.Println(init)

	final = pad(init, final)
	init = pad(final, init)

	rune0 := []rune(init)
	rune1 := []rune(final)
	indices := make([]int, len(rune0))
	for i := range indices {
		indices[i] = i
	}

	for len(indices) > 0 {
		time.Sleep(1 * time.Second)
		n := rand.Intn(len(indices))
		i := indices[n]
		indices = slices.Delete(indices, n, n+1)
		rune0[i] = rune1[i]
		fmt.Println(string(rune0))
	}
	fmt.Println()
}

func pad(string0, string1 string) string {
	if len(string0) > len(string1) {
		string1 += strings.Repeat(" ", len(string0)-len(string1))
	}
	return string1
}
