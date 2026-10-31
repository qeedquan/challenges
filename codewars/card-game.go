/*

Lеt's create function to play cards. You receive 3 arguments: card1 and card2 are cards from a single deck; trump is the main suit, which beats all others.

You have a preloaded deck (in case you need it):

deck = ["joker","2♣","3♣","4♣","5♣","6♣","7♣","8♣","9♣","10♣","J♣","Q♣","K♣","A♣",
                "2♦","3♦","4♦","5♦","6♦","7♦","8♦","9♦","10♦","J♦","Q♦","K♦","A♦",
                "2♥","3♥","4♥","5♥","6♥","7♥","8♥","9♥","10♥","J♥","Q♥","K♥","A♥",
                "2♠","3♠","4♠","5♠","6♠","7♠","8♠","9♠","10♠","J♠","Q♠","K♠","A♠"]

Game rules
If both cards have the same suit, the higher one wins
If both cards have trump, the higher one wins
If the cards have different suits and no one has trump, return "Let us play again."
If one card has trump, but not the other, the one with the trump wins
If there is a winner, return "The first/second card won."
If the two cards are the same, return "Someone cheats."
The joker always wins

Examples
"3♣", "Q♣", "♦"  -->  "The second card won."
"5♥", "A♣", "♦"  -->  "Let us play again."
"8♠", "8♠", "♣"  -->  "Someone cheats."
"2♦", "A♠", "♦"  -->  "The first card won."
"joker", "joker", "♦"  -->  "Someone cheats."

*/

package main

import (
	"slices"
	"unicode/utf8"
)

func main() {
	assert(cardgame("3♣", "Q♣", '♦') == "The second card won.")
	assert(cardgame("5♥", "A♣", '♦') == "Let us play again.")
	assert(cardgame("8♠", "8♠", '♣') == "Someone cheats.")
	assert(cardgame("2♦", "A♠", '♦') == "The first card won.")
	assert(cardgame("joker", "joker", '♦') == "Someone cheats.")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cardgame(card1, card2 string, trump rune) string {
	deck := []string{
		"joker", "2♣", "3♣", "4♣", "5♣", "6♣", "7♣", "8♣", "9♣", "10♣", "J♣", "Q♣", "K♣", "A♣",
		"2♦", "3♦", "4♦", "5♦", "6♦", "7♦", "8♦", "9♦", "10♦", "J♦", "Q♦", "K♦", "A♦",
		"2♥", "3♥", "4♥", "5♥", "6♥", "7♥", "8♥", "9♥", "10♥", "J♥", "Q♥", "K♥", "A♥",
		"2♠", "3♠", "4♠", "5♠", "6♠", "7♠", "8♠", "9♠", "10♠", "J♠", "Q♠", "K♠", "A♠",
	}

	if card1 == "joker" && card2 == "joker" {
		return "Someone cheats."
	}
	if card1 == "joker" {
		return "The first card won."
	}
	if card2 == "joker" {
		return "The second card won."
	}
	if card1 == card2 {
		return "Someone cheats."
	}

	suit1, _ := utf8.DecodeLastRuneInString(card1)
	suit2, _ := utf8.DecodeLastRuneInString(card2)
	if suit1 == suit2 {
		value1 := slices.Index(deck, card1)
		value2 := slices.Index(deck, card2)
		if value1 > value2 {
			return "The first card won."
		}
		return "The second card won."
	}

	if suit1 == trump && suit2 != trump {
		return "The first card won."
	}
	if suit2 == trump && suit1 != trump {
		return "The second card won."
	}
	return "Let us play again."
}
