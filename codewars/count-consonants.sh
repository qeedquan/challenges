#!/bin/sh

cat << EOF >/dev/null

Complete the function that takes a string of English-language text and returns the number of consonants in the string.

Consonants are all letters used to write English excluding the vowels a, e, i, o, u.

EOF

consonants() {
	echo $@ | tr '[:upper:]' '[:lower:]' | tr -c -d "bcdfghjklmnpqrstvwxyz" | wc -c
}

consonants ""
consonants "aaaaa"
consonants "XaeiouX"
consonants "Bbbbb"
consonants "helLo world"
consonants "h^$&^#$&^elLo world"
consonants "0123456789"
consonants "012345_Cb"
