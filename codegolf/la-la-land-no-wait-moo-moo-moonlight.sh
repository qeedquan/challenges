#!/bin/sh

cat << EOF >/dev/null

This challenge is a tribute to the winner of Best Picture at the Oscars 2017, La La Land Moonlight!

Write a function/program that takes a string containing only letters [A-Za-z], the four symbols that are common in every day sentences .,'? and spaces, and outputs the string in the style of La La Land.

To be more specific, take the letters up to, and including, the first vowel group, and print/output it twice adding a space each time, then print/output the whole string. y is a vowel in this challenge. Punctuation and capitalization should be kept.

You may assume that all strings contain at least one vowel, and that all strings start with a letter.

Test cases:

Land
La La Land

Moonlight
Moo Moo Moonlight

quEueIng
quEueI quEueI quEueIng

This isn't a single word.
Thi Thi This isn't a single word.

It's fun to play golf
I I It's fun to play golf

Ooo
Ooo Ooo Ooo

I'm okay
I I I'm okay

Hmm, no. There will be at least one vowel, but it can be anywhere.
Hmm, no Hmm, no Hmm, no. There will be at least one vowel, but it can be anywhere.

Why is y a vowel?
Why Why Why is y a vowel?
This is code-golf so the shortest code in each language wins. Explanations are encouraged, also in mainstream languages.

EOF

lala() {
	echo $@ | sed 's/[^aeiouy]*[aeiouy]\+/& & &/i'
}

lala "Land"
lala "Moonlight"
lala "quEueIng"
lala "This isn't a single word."
lala "It's fun to play golf"
lala "Ooo"
lala "I'm okay"
lala "Hmm, no. There will be at least one vowel, but it can be anywhere."
lala "Why is y a vowel?"
