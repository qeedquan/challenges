/*

Task
Continuously print a random character (a-z, A-Z, 0-9) not separated by a newline (\n).

Expected output
b7gFDRtgFc67h90h8H76f5dD55f7GJ6GRT86hG7TH6T7302f2f4 ...
Note: output should be randomised.

Requirements/Rules
Output must be continuous (i.e. never ending),
Output may not comprise of newlines,
Output must be random, and should not have a set seed (i.e: produce the same output every time)
Output must be only composed of characters: a-z, A-Z, 0-9.
No loopholes, regarding programming language version(s). Use only the tools available with that programming language, no third-party packages, modules, or other addons.
Points
Smallest file size (in bytes)

*/

package main

import (
	"crypto/rand"
	"os"
)

func main() {
	stream()
}

func stream() {
	const alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

	var b [8192]byte
	for {
		n, err := rand.Read(b[:])
		if err != nil {
			break
		}

		for i := 0; i < n; i++ {
			b[i] = alphabet[int(b[i])%len(alphabet)]
		}
		os.Stdout.Write(b[:n])
	}
}
