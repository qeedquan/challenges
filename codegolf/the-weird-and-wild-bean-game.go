/*

Maybe some of you already know this game: you have a collection of jelly beans of different colors. For every color, the bean can have different tastes, some are good and some are bad, and you cannot tell them apart. You have to pick a bean of a given color, and pray you have select a good one.

So, write the shortest program that receives a color of your choice (from a given list), and randomly returns the taste selected. The taste has to be picked from a built-in list. The possible list of inputs and outputs are:

Input      Output choices [only one from the list]
--------------------------------------------------
green      lawn clippings, lime, mucus, pear
yellow     rotten eggs, buttered popcorn
blue       toothpaste, blue berry
orange     vomit, peach
brown      canned dog food, chocolate
white      stinky socks, tutti-frutti, baby diapers, coconut
Rules:

You can assume that the input is going to be always a color from the input choices.
Case and trailing spaces and/or newlines do not matter.
Output must be uniformly random: succesive program executions must yield different results, and the chances of getting a given taste must be the same for all tastes in a list.
This is code-golf, so may the shortest program win!

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println(pick("green"))
	fmt.Println(pick("black"))
	fmt.Println(pick("orange"))
	fmt.Println(pick("brown"))
	fmt.Println(pick("white"))
}

func pick(color string) string {
	tastings := map[string][]string{
		"green":  []string{"lawn clippings", "lime", "mucus", "pear"},
		"yellow": []string{"rotten eggs", "buttered popcorn"},
		"blue":   []string{"toothpaste", "blue berry"},
		"orange": []string{"vomit", "peach"},
		"brown":  []string{"canned dog food", "chocolate"},
		"white":  []string{"stinky socks", "tutti-frutti", "baby diapers", "coconut"},
	}

	offerings := tastings[color]
	length := len(offerings)
	if length == 0 {
		return ""
	}
	index := rand.Intn(length)
	return offerings[index]
}
