/*

Inspired by this xkcd

https://i.sstatic.net/AWTyS.png

You work for Shazam and they have a project for you. Some customers are complaining about their app taking up too much space on their phone, so they want you to code a lite version of the app. Unfortunately, your existing code can only understand the word "na", and you have to ship soon. That's okay, we'll do the best with what we've got.

The Challenge
You must write a full program that takes a user input, or takes a command line argument, and print the title and artist of the song. Since we are trying to fix customers complaining about program size, your code must be as short as possible. The input will be a string consisting entirely of na's, with a single space between them. Lowercase/uppercase is arbitrary. This is considered a valid input: Na Na nA na NA This is an invalid input: nah nah NA naNa banana You must determine what song is playing and print it out in exactly this format:

Song: <trackname>
Artist: <artist>
If the input is exactly 8 na's, this matches two separate songs, so you must print both:

Song: Batman Theme
Artist: Neal Hefti
and

Song: Na Na Hey Hey Kiss Him Goodbye
Artist: Steam
If the input is exactly 10 na's, you must print:

Song: Katamari Damacy
Artist: Yuu Miyake
If the input is exactly 11 na's, you must print:

Song: Hey Jude
Artist: The Beatles
If the input is 12 or more na's, you must print

Song: Land Of 1000 Dances
Artist: Wilson Pickett
Lastly, if the input is invalid, there are less than 8 na's, or any of the words are not "na", your program fails to understand the music. So logically, there is only one other song that it could possibly be. You must print:

Song: Africa
Artist: Toto
As usual, standard loopholes apply, and the shortest answer in bytes wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := 1; i <= 16; i++ {
		lyrics := strings.Repeat("NA ", i)
		lyrics = lyrics[:len(lyrics)-1]
		playing(lyrics)
	}
}

func playing(lyrics string) {
	fmt.Printf("%q\n", lyrics)
	tokens := strings.Split(lyrics, " ")
	for _, token := range tokens {
		if strings.ToLower(token) != "na" {
			output("Invalid", "Invalid")
			fmt.Println()
			return
		}
	}

	switch len(tokens) {
	case 8:
		output("Batman Theme", "Neal Hefti")
		output("Na Na Hey Hey Kiss Him Goodbye", "Steam")
	case 10:
		output("Katamari Damacy", "Yuu Miyake")
	case 11:
		output("Hey Jude", "The Beatles")
	case 12:
		output("Land Of 1000 Dances", "Wilson Pickett")
	default:
		output("Africa", "Toto")
	}
	fmt.Println()
}

func output(song, artist string) {
	fmt.Println("Song:", song)
	fmt.Println("Artist:", artist)
}
