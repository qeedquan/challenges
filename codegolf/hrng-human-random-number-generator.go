/*

You know it: keyboard or mouse input is just too mainstream to create Random Numbers through human behavior.

Create the most unique (Pseudo)Random Number Generator that create its numbers through human behavior.

Web-API's are not restricted! Anyone should use the code provided, so any special hardware is restricted. (I think we can assume that everyone has a smartphone) The number should be a 256 bit number.

Example: use the Google Map's API to get current traffic to create the Random Number.

This is a popularity-contest, so most votes wins!

*/

package main

import (
	"fmt"
	"io"
	"log"
	"math/rand"
	"net/http"
)

func main() {
	resp, err := http.Get("http://codegolf.stackexchange.com/questions/109658/hrng-human-random-number-generator")
	check(err)

	buf, err := io.ReadAll(resp.Body)
	check(err)

	val := uint64(0)
	for i := range buf {
		val += uint64(buf[i]) * uint64(rand.Intn(50))
	}
	fmt.Println(val)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}
