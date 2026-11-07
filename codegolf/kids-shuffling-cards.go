/*

Shuffling a deck of cards is hard for kids, so they must figure out ways to get a reasonable well shuffled deck as simply as possible.

One way to do this that gives reasonably good results is:

Take the top card out and insert it a random place in the deck
Take the bottom card out and insert it in a random place in the deck
Continue until you believe it's good enough.
Note that you shall never insert a card in the top or bottom spot, it should be placed somewhere in the deck.

Instead of shuffling cards, we'll shuffle alphanumerical characters: 0-9, A-J, a-j, q-z and Q-Z.

Start with the string shown below and shuffle the characters the way it's described above. You can choose if you want to continue shuffling infinitely or shuffle the cards 100 rounds (100 cards from the top and 100 cards from the bottom).

0123456789abcdefghijqrstuvwxyzABCDEFGHIJQRSTUVWXYZ
The challenge is to display the characters being shuffled. Each "shuffle" (take out and insert card) shall take between 0.25 and 0.35 seconds.

The gif below shows an example output:

https://i.sstatic.net/eh7TU.gif

This is code-golf so the shortest code in bytes wins.

"Why don't you have a-t instead of a-j, q-z?" Because this shall illustrate suits of cards, not just characters. And yes, there are 5 suits.

Note: I have decided to stop using the check mark on code-golf-challenges. Relevant meta posts here and here.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	animate()
}

func animate() {
	cards := []byte("0123456789abcdefghijqrstuvwxyzABCDEFGHIJQRSTUVWXYZ")
	for {
		clear()
		fmt.Printf("%s\n", cards)
		time.Sleep(100 * time.Millisecond)
		shuffle(cards, 1)
	}
}

func shuffle(cards []byte, rounds int) {
	state := 0
	for range rounds * 2 {
		var from, to int
		switch state {
		case 0:
			to = 1 + rand.Intn(len(cards)-1)
		case 1:
			from = len(cards) - 1
			to = rand.Intn(len(cards) - 1)
		}
		cards[from], cards[to] = cards[to], cards[from]
		state ^= 1
	}
}

func clear() {
	fmt.Printf("\033c")
}
