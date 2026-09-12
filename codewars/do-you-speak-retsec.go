/*

Do you speak retsec?
You and your friends want to play undercover agents. In order to exchange your secret messages, you've come up with the following system: you take the word, cut it in half, and place the first half behind the latter. If the word has an uneven number of characters, you leave the middle at its previous place:

http://i.imgur.com/Ozy6p09.png

That way, you'll be able to exchange your messages in private.

Task
You're given a single word. Your task is to swap the halves. If the word has an uneven length, leave the character in the middle at that position and swap the chunks around it.

Examples
reverseByCenter("secret")  == "retsec" // no center character
reverseByCenter("agent")   == "nteag"  // center character is "e"

Remarks
Don't use this to actually exchange messages in private.q

*/

package main

import "fmt"

func main() {
	assert(encrypt("secret") == "retsec")
	assert(encrypt("agent") == "nteag")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func encrypt(s string) string {
	n := len(s)
	if n&1 == 0 {
		return s[n/2:] + s[:n/2]
	}
	return fmt.Sprintf("%s%c%s", s[n/2+1:], s[n/2], s[:n/2])
}
