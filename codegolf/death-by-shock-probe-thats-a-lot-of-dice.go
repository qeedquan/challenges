/*

In the webcomic Darths & Droids, Pete, who plays R2-D2 in the fictional roleplaying campaign around which the comic is based, once claims (warning: potential spoilers in the linked comic) that, with the Lost Orb of Phanastacoria rigged up to his shock probe, he can now dish out a whopping 1048576d4 of damage. (The GM has neither confirmed nor denied this.) Since it should be reasonably obvious that almost no one will actually have the patience to roll that many dice, write a computer program to do it for him, outputting the total value rolled in some reasonable format. Entries will be ranked by program size (shortest program, by byte count, wins), both overall and per-language, with run time breaking ties. Answer may be either a full program or a function definition.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println(dicesum())
}

func dicesum() int {
	r := 0
	for range 1 << 20 {
		r += rand.Intn(4) + 1
	}
	return r
}
