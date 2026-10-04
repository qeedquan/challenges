/*

This is the final test of becoming a spy - In our last question: "Ancestors Blowfish - play with bits." (https://www.codewars.com/kata/587510553793a30f640000ff)

we played with bits of plain text & password with special XOR and finally got an encrypted text.

Lets say you put your hands on a secret email which Donald Trump sent to Hillary Clinton, you know 3 things regarding this email:

It is encrypted with our Ancestors blowfish encryption.
The plain text was in english.
The password was in english.
You don't know the password, you dont know it's length, you don't know why the hell Donald Trump wrote secret email to Hillary Clinton...

A real spy can decrypt it.

Good Luck.

**it is important to solve or at least read the linked kata before trying this one - (https://www.codewars.com/kata/587510553793a30f640000ff)

*/

package main

import "bytes"

func main() {
	assert(decrypt("慔扡据慤批") == "Tandy")
	assert(decrypt("䉳佰佹䴠䉫佩佴") == "spy kit")
	assert(decrypt("乔佡\u206E䵤䅹") == "Tandy")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func decrypt(s string) string {
	w := new(bytes.Buffer)
	for _, r := range []rune(s) {
		w.WriteRune(r & 0xff)
	}
	return w.String()
}
