#!/bin/sh

cat << EOF >/dev/null

A Palindrome is a sequence that is the same in reverse as it is forward.

I.e. hannah, 12321.

Your task is to write a function to determine whether a given string is palindromic or not.

Bonus: Support multiple lines in your function to validate Demetri Martin's 224 word palindrome poem.

Thanks to _lerp for submitting this idea in r/dailyprogrammer_ideas!

EOF

palindrome() {
	if [ "$1" = "$(echo $1 | rev)" ]; then
		echo true
	else
		echo false
	fi
}

palindrome "hannah"
palindrome "12321"
palindrome "XYZ"
palindrome "123456"
palindrome "xxxyxxx"

