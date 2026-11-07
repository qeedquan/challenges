/*

Theme Week:
I got the whole week so I am merging all 3 challenges into a theme of Texas Hold 'em Poker. All 3 challenges will be related on this popular card game of poker.

Description:
For those who want to know more about Texas Hold 'Em Poker or just need a refresher. Check [Wikipedia Article on Texas Hold 'Em Poker] (http://en.wikipedia.org/wiki/Texas_hold_%27em)

For the first challenge we will simulate the dealing part of the game.

Input:
You will be asked how many players 2 to 8. You will always be one of the players and you are facing 1 to 7 other computer controlled players.

Output:
Display the 2 cards each player is dealt and the display the 5 community cards.

Format is left up to you. (The exact method of the output a card. For my examples I am using verbal words but someone might use unicode symbols for the card suit or other. You design this as long as we can tell the cards apart it is all good)

Example:
How many players (2-8) ? 3

Your hand: 2 of Clubs, 5 of Diamonds
CPU 1 Hand: Ace of Spades, Ace of Hearts
CPU 2 Hand: King of Clubs, Queen of Clubs

Flop: 2 of Hearts, 5 of Clubs, Ace of Clubs
Turn: King of Hearts
River: Jack of Hearts
Dealing Cards:
To keep things close to the game you will be dealing from 1 deck of standard playing cards. Once you deal that card you cannot deal it again. The exact method is part of the challenge and for you to decide, design and implement.

In Texas Hold em you burn a card (draw and discard without looking at it) before you do the flop, turn and river. It removes these cards from the pool of possible cards that can be dealt. If you wish to show these cards (I did not in my example) then please for science go for it.

Looking ahead for the Intermediate:
In the intermediate you will be asked to compare various hands of poker to find which hand is the winning hand.

*/

package main

import (
	"flag"
	"fmt"
	"math/rand"
	"os"
	"strconv"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	count, err := strconv.Atoi(flag.Arg(0))
	if count < 1 || count >= 24 || err != nil {
		fmt.Println("invalid number")
		return
	}

	var (
		deck      Deck
		hands     = make([][2]Card, count)
		community [5]Card
	)
	deck.Init()
	deck.Shuffle()
	for i := range count {
		hands[i][0] = deck.Deal()
		hands[i][1] = deck.Deal()
	}
	for i := range community {
		community[i] = deck.Deal()
	}

	for i := range count {
		if i == 0 {
			fmt.Printf("Your hand: %s, %s\n", hands[i][0], hands[i][1])
		} else {
			fmt.Printf("CPU %d hand: %s, %s\n", i, hands[i][0], hands[i][1])
		}
	}
	fmt.Println()

	fmt.Printf("Flop: %s %s %s\n", community[0], community[1], community[2])
	fmt.Printf("Turn: %s\n", community[3])
	fmt.Printf("River: %s\n", community[4])
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: 1-23")
	flag.PrintDefaults()
	os.Exit(2)
}

type Card int

type Deck struct {
	count int
	cards [52]Card
}

func (c Card) Suit() int {
	return int(c-1) / 13
}

func (c Card) Value() int {
	return int((c-1)%13) + 1
}

func (c Card) String() string {
	rank := "A23456789TJQK"
	suit := []rune{'♦', '♣', '♥', '♠'}
	return fmt.Sprintf("%c%c", rank[c.Value()-1], suit[c.Suit()])
}

func (d *Deck) Init() {
	for i := range d.cards {
		d.cards[i] = Card(i + 1)
	}
	d.count = len(d.cards)
}

func (d *Deck) Shuffle() {
	rand.Shuffle(d.count, func(i, j int) {
		d.cards[i], d.cards[j] = d.cards[j], d.cards[i]
	})
}

func (d *Deck) Deal() Card {
	d.count -= 1
	return d.cards[d.count]
}
