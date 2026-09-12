/*

At some point or another, most programmers will encounter problems in text processing that has a very elegant solution using regular expressions.
But regular expressions can also be over-relied on and abused, and make code unreadable.
There is a lot of truth in the old saying "Some people, when confronted with a problem, think 'I know, I'll use regular expressions.' Now they have two problems."
So today, lets embrace those two problems and pound some regular expressions into submission!

Your task is to write a regular expression that will match a string if and only if the number of vowels (both upper and lower case) in that string is exactly divisible by 3.
For instance, the regular expression will not match the string "Hello!", because there are only two vowels there, "e" and "o" (and 2 is not divisible by 3),
but it will match "Daily programmer" because there are six vowels, "Daily programmer" (and 6 is divisible by 3).

For the purposes of this problem, the vowels of the English language are "A", "E", "I", "O", "U" and "Y" (in both upper and lower cases, obviously).

Here are a few strings you can test your regular expressions on:

"Friends, Romans, countrymen, lend me your ears!"

"Double, double, toil and trouble; Fire burn and cauldron bubble."

"Alas, poor Yorick! I knew him, Horatio. A fellow of infinite jest, of most excellent fancy."

"To be, or not to be- that is the question: Whether 'tis nobler in the mind to suffer The slings and arrows of outrageous fortune Or to take arms against a sea of troubles, And by opposing end them."

"Everybody stand back! I know regular expressions."

*/

package main

import "regexp"

func main() {
	assert(REGEX.MatchString("Hello!") == false)
	assert(REGEX.MatchString("Daily programmer") == true)
	assert(REGEX.MatchString("Friends, Romans, countrymen, lend me your ears!") == true)
	assert(REGEX.MatchString("Double, double, toil and trouble; Fire burn and cauldron bubble.") == true)
	assert(REGEX.MatchString("Alas, poor Yorick! I knew him, Horatio. A fellow of infinite jest, of most excellent fancy.") == true)
	assert(REGEX.MatchString("To be, or not to be- that is the question: Whether 'tis nobler in the mind to suffer The slings and arrows of outrageous fortune Or to take arms against a sea of troubles, And by opposing end them.") == false)
	assert(REGEX.MatchString("Everybody stand back! I know regular expressions.") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var REGEX = regexp.MustCompile(`^([^aeiouyAEIOUY]*[aeiouyAEIOUY][^aeiouyAEIOUY]*[aeiouyAEIOUY][^aeiouyAEIOUY]*[aeiouyAEIOUY][^aeiouyAEIOUY]*)*$`)
