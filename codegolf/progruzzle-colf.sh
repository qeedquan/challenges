#!/bin/sh

cat << EOF >/dev/null

Ever fancied creating cool twitter hashtags such as #brexit or #brangelina? this golf is for you.

Write a program that accepts two strings A & B as input and merges them according to the following algorithm:

let n be the number of vowels groups in A (e.g. britain has 2 vowels groups : i in position 3 and ai in position 5).
if n = 1 : truncate A starting at its first vowel group position (example: bill => b)
if n > 1 : truncate A starting at its n-1th vowel group position (example: programming => progr, britain => br)
remove all consonants at the beginning of B (jennifer => ennifer)
concatenate the modified A & B
Vowels are aeiou; consonants are bcdfghjklmnpqrstvwxyz.

Input
You can assume the input strings are lowercase and contain at least one vowel and one consonant.

Examples
brad + angelina      => brangelina
britain + exit       => brexit
ben + jennifer       => bennifer
brangelina + exit    => brangelexit
bill + hillary       => billary
angelina + brad      => angelad
programming + puzzle => progruzzle
code + golf          => colf
out + go             => o

EOF

# ported from @Jordan solution
hashtag() {
	echo $@ | sed -E 's/([aeiou]+[^aeiou]*){,2} [^aeiou]*//'
}

hashtag "brad" "angelina"
hashtag "britain" "exit"
hashtag "ben" "jennifer"
hashtag "brangelina" "exit"
hashtag "bill" "hillary"
hashtag "angelina" "brad"
hashtag "programming" "puzzle"
hashtag "code" "golf"
hashtag "out" "go"

