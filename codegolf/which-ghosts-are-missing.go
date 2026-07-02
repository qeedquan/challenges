/*

In this challenge, given a list of ghosts from Pac-Man, you must output which ghosts are missing. You must do it in as few bytes as you can

Input
Input will consist of a string or list, which will include a number ghosts, which could include:

Blinky
Inky
Pinky
Clyde
However, input may also include Pac-Man (with that punctuation). So, the maximum amount of items in a list will be five, in any order. It can be assumed that no invalid items will be in the list

Output
Output will consist of a string, or list. This will include of all the ghosts that are not in the input, in any order. However, if Pac-Man is in the input, all ghosts will be considered missing (because he eats them).

Test cases
input: Clyde
output: Blinky, Inky, Pinky
alternate output: Inky, Pinky, Blinky
or one of the other 4 permutations

input: Clyde, Blinky # or however you delimit it
output: Inky, Pinky
alt: Pinky, Inky

input: Pac-Man, Clyde
Output: Blinky, Inky, Pinky, Clyde
or you could output one of the other 23 permutations

input:[null]
Output: Blinky, Inky, Pinky, Clyde
or you could output one of the other 23 permutations
This is codegolf, so the lower the bytecount, the better.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]string{
		"Clyde",
	}, []string{
		"Blinky", "Inky", "Pinky",
	})

	test([]string{
		"Clyde", "Blinky",
	}, []string{
		"Inky", "Pinky",
	})

	test([]string{
		"Pac-Man", "Clyde",
	}, []string{
		"Blinky", "Inky", "Pinky", "Clyde",
	})

	test([]string{},
		[]string{
			"Blinky", "Inky", "Pinky", "Clyde",
		})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, r []string) {
	p := ghosts(s)
	fmt.Println(p)
	sort.Strings(r)
	assert(reflect.DeepEqual(p, r))
}

func ghosts(s []string) []string {
	m := map[string]bool{
		"Blinky": false,
		"Inky":   false,
		"Pinky":  false,
		"Clyde":  false,
	}

	for _, t := range s {
		if t == "Pac-Man" {
			return []string{"Blinky", "Clyde", "Inky", "Pinky"}
		}

		f, ok := m[t]
		if !f && ok {
			m[t] = true
		}
	}

	r := []string{}
	for k, v := range m {
		if !v {
			r = append(r, k)
		}
	}
	sort.Strings(r)

	return r
}
