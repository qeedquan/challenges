/*

Create a function that converts a given ASCII string to its hexadecimal SHA-256 hash.

sha256("Hello World!") => "7f83b1657ff1fc53b92dc18148a1d65dfc2d4b1fa3d677284addd200126d9069"

*/

package main

import (
	"crypto/sha256"
	"fmt"
)

func main() {
	assert(sha256sum("Hello World!") == "7f83b1657ff1fc53b92dc18148a1d65dfc2d4b1fa3d677284addd200126d9069")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sha256sum(s string) string {
	return fmt.Sprintf("%x", sha256.Sum256([]byte(s)))
}
