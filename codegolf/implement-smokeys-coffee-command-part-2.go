/*

Like the previous SmokeDetector challenge? This one is for you too ;)
Note: SmokeDetector is a bot that detects spam and offensive posts on the network and posts alerts to chat.

What to implement
Smokey's !!/coffee command uniformly at random picks one of these words (sorts of coffee):

Espresso
Macchiato
Ristretto
Americano
Latte
Cappuccino
Mocha
Affogato
jQuery
adds it to the message: "brews a cup of $COFFEE_SORT for $USERNAME"

Your task is to implement the function that takes a username as any reasonable input format, randomly (uniformly at random) picks $COFFEE_SORT, and prints to the screen:

brews a cup of $COFFEE_SORT for $USERNAME

Rules
Regular code-golf — the shortest answer in bytes wins ;)

Good luck!

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	for i := 0; i < 10; i++ {
		fmt.Println(coffee("Jay"))
	}
}

func coffee(user string) string {
	flavors := []string{
		"Espresso",
		"Macchiato",
		"Ristretto",
		"Americano",
		"Latte",
		"Cappuccino",
		"Mocha",
		"Affogato",
		"jQuery",
	}

	i := rand.Intn(len(flavors))
	return fmt.Sprintf("brews a cup of %v for %v", flavors[i], user)
}
