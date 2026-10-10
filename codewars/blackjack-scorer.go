/*

Complete the function that determines the score of a hand in the card game Blackjack ( https://en.wikipedia.org/wiki/Blackjack ) (aka 21).

The function receives an array of strings that represent each card in the hand ("2", "3", ..., "10", "J", "Q", "K" or "A") and should return the score of the hand (integer).

Scoring rules:
Number cards count as their face value (2 through 10). Jack, Queen and King count as 10. An Ace can be counted as either 1 or 11.

Return the highest score of the cards that is less than or equal to 21. If there is no score less than or equal to 21 return the smallest score more than 21.

Examples
["A"]                           ==>  11
["A", "J"]                      ==>  21
["A", "10", "A"]                ==>  12
["5", "3", "7"]                 ==>  15
["5", "4", "3", "2", "A", "K"]  ==>  25

*/

package main

import "strconv"

func main() {
	assert(scorehand([]string{"A"}) == 11)
	assert(scorehand([]string{"A", "J"}) == 21)
	assert(scorehand([]string{"A", "10", "A"}) == 12)
	assert(scorehand([]string{"5", "3", "7"}) == 15)
	assert(scorehand([]string{"5", "4", "3", "2", "A", "K"}) == 25)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func scorehand(cards []string) int {
	score := 0
	aces := 0
	for _, card := range cards {
		switch card {
		case "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10":
			value, _ := strconv.Atoi(card)
			score += value
		case "J", "Q", "K":
			score += 10
		case "A":
			score += 11
			aces += 1
		}
	}

	for score > 21 && aces > 0 {
		score -= 10
		aces -= 1
	}

	return score
}
