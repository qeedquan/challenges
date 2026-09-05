/*

Your task is to generate an emoticon of three characters, the first character being one eye, the second the mouth, and the third another eye. Each eye is a random one of these characters: $'*+-;O^`ox~, and the mouth is a random one of these: ,-._coux.

Each eye and the mouth must be on the same general level. These eyes: '*;^` and these mouths: -coux are "upper-level", while these eyes: $+-Oox~ and these mouths: ,._ are "lower-level". Any emoticon has a 50 % chance of using only upper-level eyes and mouth, and a 50 % chance of using only lower-level ones.

Additionally, the eyes should usually not be different. The chance of the eyes using the same symbol must be somewhere between 50 % and 67 %.

Rules
The submission must be a function or a full program.
The submission must either print the emoticon to the screen with optional trailing and/or preceding whitespace, or returning the emoticon as a string.
The emoticon should have a 50 % chance of being upper-level and a 50 % chance of being lower-level.
All eyes and mouths of the same level must have the same chance of occuring.
The eyes should be the same 50-67 % of the time.
Standard loopholes apply.
This is a code-golf, so the shortest answer in bytes wins!
Examples:

-_-     // All symbols are lower-level: valid
~o.~    // Two eyes on the left side: invalid
^^      // No mouth - invalid
^_^     // The mouth is lower-level but the eyes are not: invalid
^-*     // All symbols are upper-level: valid
---     // Eyes are lower-level but mouth is upper-level: invalid

Enjoy!

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	for i := 0; i < 10; i++ {
		fmt.Println(emoticon())
	}
}

func emoticon() string {
	const (
		EYE_UPPER   = "'*;^`"
		EYE_LOWER   = "$+-Oox~"
		MOUTH_UPPER = "-coux"
		MOUTH_LOWER = ",._"
	)

	e, m := EYE_UPPER, MOUTH_UPPER
	if rand.Intn(2) == 1 {
		e, m = EYE_LOWER, MOUTH_LOWER
	}

	i := rand.Intn(len(e))
	j := rand.Intn(len(m))
	k := i
	if rand.Intn(2) == 1 {
		for k == i {
			k = rand.Intn(len(e))
		}
	}

	return fmt.Sprintf("%c%c%c", e[i], m[j], e[k])
}
