/*

You are developing an image hosting website.

You have to create a function for generating random and unique image filenames.

Create a function for generating a random 6 character string which will be used to access the photo URL.

To make sure the name is not already in use, you are given access to an PhotoManager object.

You can call it like so to make sure the name is unique

// at this point, the website has only one photo, hosted on the 'ABCDEF' url
photoManager.nameExists('ABCDEF'); // returns true
photoManager.nameExists('BBCDEF'); // returns false
Note: We consider two names with same letters but different cases to be unique.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	photomanager := make(map[string]bool)
	for range 50 {
		fmt.Println(generate(photomanager))
	}
}

func generate(photomanager map[string]bool) string {
	const symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
	for {
		name := ""
		for range 6 {
			char := rand.Intn(len(symbols))
			name += string(symbols[char])
		}
		if !photomanager[name] {
			photomanager[name] = true
			return name
		}
	}
}
