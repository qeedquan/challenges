/*

The program should accept one input which is a number to multiply the sleep interval by (n >= 0 && n <= 50).

100ms Moves

^(")v
v(")^
^(")^
v(")v
200ms Moves

(>")>
<(")>
<("<)
Extra Details
Randomness doesn't have to be uniform but each dance move should have a reasonable chance of occuring (at least 1 in 60 seems fair, it's OK if the same move occurs twice in a row)
There should only be one bird displayed at a time, not multiple birds
Trailing whitespace is allowed (but other trailing characters are not)
A bird should be displayed before the sleep

Example in Python 3
import random, time, sys

birds = """(>")>
<(")>
<("<)
^(")v
v(")^
^(")^
v(")v"""
birds = birds.split()

interval = int(input("Sleep for 100ms*"))
selection = -1

while True:
    if selection == -1:
        selection = 1
    else:
        selection = random.randint(0, len(birds)-1)
    sys.stdout.write('\r'+birds[selection])
    if selection > 2:
        time.sleep(0.1*interval)
    else:
        time.sleep(0.2*interval)

Winning
This is code-golf so least bytes wins!

*/

package main

import (
	"flag"
	"fmt"
	"math/rand"
	"time"
)

func main() {
	var interval time.Duration
	flag.DurationVar(&interval, "interval", 1, "specify interval")
	flag.Parse()
	animate(interval)
}

func animate(interval time.Duration) {
	birds := []string{
		`(>")>`,
		`<(")>`,
		`<("<)`,
		`^(")v`,
		`v(")^`,
		`^(")^`,
		`v(")v`,
	}

	selection := 1
	for {
		fmt.Printf("\r%s", birds[selection])

		duration := 100 * time.Millisecond
		if selection <= 2 {
			duration = 200 * time.Millisecond
		}
		time.Sleep(duration * interval)

		selection = rand.Intn(len(birds))
	}
}
