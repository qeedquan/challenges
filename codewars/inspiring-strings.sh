#!/bin/sh

cat << EOF >/dev/null

When given a string of space separated words, return the word with the longest length. If there are multiple words with the longest length, return the last instance of the word with the longest length.

Example:

'red white blue' //returns string value of white

'red blue gold' //returns gold

EOF

longestword() {
	echo $@ | sed 's/ /\n/g' | perl -e 'print sort { length($a) <=> length($b) } <>' | tail -n 1
}

longestword red white blue
longestword red blue gold
