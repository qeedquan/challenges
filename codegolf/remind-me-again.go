/*

Introduction
Ever heard of Remind? No? Neither did I until about 2 years ago. Basic premise of it is for teachers to send out reminders and communicate with their students. Pretty neat, right? It even allows you send emotes and react to messages! Which I do on a daily basis.

But, one thing about Remind is that the teachers always send the "Do your homework!" "If you don't, you'll get an F!". But, there is useful stuff too, like "Test on Tuesday", or the occasional "Have a good day!". I almost always reply happy with a thumbs up, but sometimes, I have to put a thumbs down.

Challenge
Your task today is to find out if a message has a certain connotation to it. If it has a positive connotation to it, reply with a thumbs up. If it has a negative connotation, reply with a thumbs down.

How am I supposed to detect connotations?
A positive connotation will normally have 3 words in it. The 3 words are: Happy, Good, and Passed.

A negative connotation will have 3 also. Those 3: Test, Fail, and Homework.

What am I testing for?
You are testing to see if a message contains positive, negative or both connotations.

If a message has positive connotations to it, go ahead and return the unicode code point for thumbs up (U+1F44D).

If it has negative connotations to it, return the unicode code point for thumbs down (U+1F44E).

If the message has both negative and positive connotations, return the code point for a neutral face (U+1F610).

If, for some other reason, it doesn't have either connotations, return a nice ol' shrug (¯\_(ツ)_/¯). If the shrug doesn't show up right, here's the Emojipedia link to the shrug

Constraints
Program must take a message as input.
Positive connotations must return thumbs up code point (U+1F44D)
Negative connotations must return thumbs down code point (U+1F44E).
If the message has both connotations, return the neutral face code point (U+1F610).
If the message has neither connotations, return the shrug (¯\_(ツ)_/¯).
This is code-golf, Shortest bytes win

Test cases.
Input -> Output
Happy Good Friday! -> U+1F44D
Congrats, you just played yourself -> ¯\_(ツ)_/¯
You failed the test. -> U+1F44E
Good job on the test. -> U+1F610

*/

package main

import "strings"

func main() {
	assert(connotation("Happy Good Friday!") == "👍")
	assert(connotation("Congrats, you just played yourself") == `¯\_(ツ)_/¯`)
	assert(connotation("You failed the test.") == "👎")
	assert(connotation("Good job on the test.") == "😐")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func connotation(sentence string) string {
	positive := 0
	negative := 0
	words := strings.Split(sentence, " ")
	for _, word := range words {
		word = strip(word)
		switch strings.ToLower(word) {
		case "happy", "good", "passed":
			positive++
		case "test", "fail", "homework":
			negative++
		}
	}

	switch {
	case positive > 0 && negative == 0:
		return "👍"
	case positive == 0 && negative > 0:
		return "👎"
	case positive > 0 && negative > 0:
		return "😐"
	}
	return `¯\_(ツ)_/¯`
}

func strip(word string) string {
	word = strings.Replace(word, "!", "", -1)
	word = strings.Replace(word, ".", "", -1)
	word = strings.Replace(word, "?", "", -1)
	return word
}
