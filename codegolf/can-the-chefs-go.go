/*

On the TV cooking show Guy's Grocery Games, the chefs cannot begin shopping until Guy Fieri, the show's host, says "Three, two, one, go!" However, the words do not have to be all together. He often "hides" the words in things like this (based on a real example, but not quoting verbatim):

There are three of you here; after this round there will be two; but only one of you will go shop for up to $20,000.

(At the end of the show, the winning chef must find either five or ten items, depending on the episode, from the store; the number of items found determines how much money they win.)

Fairly regularly, he succeeds in confusing the chefs and they don't go. Often, they realize after a few seconds that they can go and frantically run down the aisles trying to make up for the lost time; other times, they don't realize it until the judges start shouting "Go! Go! Go!"

Can you do better?

Write a program that determines

Whether the input string allows the chefs to go, and
If so, at what point in the string they may go.
The chefs may go if the string contains three, followed by zero or more other characters, followed by two, followed by zero or more other characters, followed by one, followed by zero or more other characters, followed by go. Matching is case-insensitive.

The point at which the chefs may go is the zero-based index of the o in go.

Because ThreeTwoOneGo is 13 characters, this number will always be at least 12. If the chefs can go, return the point at which they can go. If they cannot, return any falsy value or any number of your choice less than or equal to 11. This number does not need to be consistent; it's okay if it varies randomly and/or with the input, as long as it is consistently less than or equal to 11.

*/

package main

import (
	"regexp"
)

func main() {
	assert(restarte.MatchString(`There are three of you here; after this round there will be two; but only one of you will go shop for up to $20,000.`) == true)
	assert(restarte.MatchString(`ThreeTwoOneGo`) == true)
	assert(restarte.MatchString(`Three twos onerous gone`) == true)
	assert(restarte.MatchString(`Healthy threesomes outwork nonegos`) == true)
	assert(restarte.MatchString(`threetwogoone`) == false)
	assert(restarte.MatchString(`threetwogoonego`) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var (
	restarte = regexp.MustCompile(`(?i)three.*two.*one.*go`)
)
