#!/bin/sh

cat << EOF >/dev/null

Description
Atbash is a simple substitution cipher originally for the Hebrew alphabet, but possible with any known alphabet. It emerged around 500-600 BCE. It works by substituting the first letter of an alphabet for the last letter, the second letter for the second to last and so on, effectively reversing the alphabet. Here is the Atbash substitution table:

Plain:  abcdefghijklmnopqrstuvwxyz
Cipher: ZYXWVUTSRQPONMLKJIHGFEDCBA
Amusingly, some English words Atbash into their own reverses, e.g., "wizard" = "draziw."

This is not considered a strong cipher but was at the time.

For more information on the cipher, please see the Wikipedia page on Atbash.

Input Description
For this challenge you'll be asked to implement the Atbash cipher and encode (or decode) some English language words. If the character is NOT part of the English alphabet (a-z), you can keep the symbol intact. Examples:

foobar
wizard
/r/dailyprogrammer
gsrh rh zm vcznkov lu gsv zgyzhs xrksvi
Output Description
Your program should emit the following strings as ciphertext or plaintext:

ullyzi
draziw
/i/wzrobkiltiznnvi
this is an example of the atbash cipher

EOF

atbash() {
	echo "$1" | tr 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz' 'ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihgfedcba'
}

atbash "foobar"
atbash "wizard"
atbash "/r/dailyprogrammer"
atbash "gsrh rh zm vcznkov lu gsv zgyzhs xrksvi"

